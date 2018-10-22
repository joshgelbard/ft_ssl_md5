/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_digest_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:17 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:17 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_digest_common.h"
#include "hash_algorithm.h"
#include "hash_ctx.h"
#include "util.h"

char		*hash_get_string(struct s_hash_ctx *this)
{
	unsigned char	*b;
	char			*s;
	size_t			i;

	b = zalloc(this->class->digest_size);
	xmemcpy(b, this->digest, this->class->digest_size);
	if (this->class->is_big_endian)
	{
		i = 0;
		while (i < this->class->digest_size / this->class->word_size)
		{
			reverse_byte_order(b + i * this->class->word_size,
					this->class->word_size);
			i++;
		}
	}
	s = zalloc(this->class->digest_size * 2 + 1);
	mem2string(b, this->class->digest_size, s);
	free(b);
	return (s);
}

void		hash_initialize(struct s_hash_algorithm *class,
		struct s_hash_ctx *instance)
{
	if (instance->digest)
		free(instance->digest);
	if (instance->block)
		free(instance->block);
	instance->digest = zalloc(class->digest_size);
	instance->block = zalloc(class->block_size);
	instance->block_offset = 0;
	instance->processed_blocks = 0;
	instance->message_bitsize = 0;
	instance->class = class;
	class->finish_initialize(instance);
}

void		hash_update(struct s_hash_ctx *this,
		void *p, size_t data_len)
{
	size_t			block_size;
	unsigned char	*data;

	block_size = this->class->block_size;
	data = (unsigned char *)p;
	while (data_len >= block_size || this->block_offset + data_len >=
			block_size)
	{
		xmemcpy(this->block + this->block_offset,
				data, block_size - this->block_offset);
		this->class->process_block(this);
		this->processed_blocks++;
		this->block_offset = 0;
		data += block_size;
		data_len -= block_size;
		this->message_bitsize += 8 * block_size;
		xzero(this->block, block_size);
	}
	if (data_len > 0)
	{
		xmemcpy(this->block + this->block_offset, data, data_len);
		this->block_offset += data_len;
		this->message_bitsize += 8 * data_len;
	}
}

static void	append_length(struct s_hash_ctx *this)
{
	unsigned char length_in_two_words[1024];
	unsigned char *w0;
	unsigned char *w1;

	xmemcpy(&length_in_two_words, &this->message_bitsize,
			sizeof(this->message_bitsize));
	if (this->class->is_big_endian)
	{
		w1 = length_in_two_words;
		w0 = length_in_two_words + this->class->word_size;
		reverse_byte_order(w0, this->class->word_size);
		reverse_byte_order(w1, this->class->word_size);
	}
	else
	{
		w0 = length_in_two_words;
		w1 = length_in_two_words + this->class->word_size;
	}
	xmemcpy(this->block + this->class->block_size - this->class->word_size,
			w1, this->class->word_size);
	xmemcpy(this->block + this->class->block_size - this->class->word_size * 2,
			w0, this->class->word_size);
}

void		hash_finalize(struct s_hash_ctx *this)
{
	size_t block_size;

	block_size = this->class->block_size;
	this->block[this->block_offset] = 0x80;
	this->block_offset += 1;
	if (this->block_offset + this->class->word_size * 2 >= block_size)
	{
		if (this->block_offset != block_size)
			xzero(this->block + this->block_offset, block_size -
					this->block_offset - 1);
		this->class->process_block(this);
		this->block_offset = 0;
		this->processed_blocks++;
		xzero(this->block, block_size);
	}
	xzero(this->block + this->block_offset, block_size - this->block_offset - 1
			- this->class->word_size * 2);
	append_length(this);
	this->block_offset = 0;
	this->class->process_block(this);
	this->processed_blocks++;
}
