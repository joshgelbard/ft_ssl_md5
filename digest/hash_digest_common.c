#include "hash_digest_common.h"
#include "hash_algorithm.h"
#include "hash_ctx.h"
#include "reverse_byte_order.h"
#include "memprint.h"
#include "debug.h"

char *hash_get_string(struct s_hash_ctx *this)
{
	unsigned char *b;
	char	*s;
	int		i;

	b = malloc(this->class->digest_size);
	memcpy(b, this->digest, this->class->digest_size);
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
	s = malloc(this->class->digest_size * 2 + 1);
	mem2string(b, this->class->digest_size, s);
	free(b);
	return (s);
}

void hash_initialize(struct s_hash_algorithm *class,
		struct s_hash_ctx *instance)
{
	instance->digest = calloc(class->digest_size, 1);
	instance->block = calloc(class->block_size, 1);
	instance->block_offset = 0;
	instance->processed_blocks = 0;
	instance->message_bitsize = 0;
	instance->class = class;
	class->finish_initialize(instance);
}

void hash_update(struct s_hash_ctx *this,
		void *p, size_t data_len)
{
	size_t block_size;
	unsigned char *data;

	block_size = this->class->block_size;
	data = (unsigned char *)p;
	while (data_len >= block_size || this->block_offset + data_len >= block_size)
	{
		memcpy(this->block + this->block_offset,
				data, block_size - this->block_offset);
		this->class->process_block(this);
		this->processed_blocks++;
		this->block_offset = 0;
		data += block_size;
		data_len -= block_size;
		this->message_bitsize += 8 * block_size;
		bzero(this->block, block_size);
	}
	if (data_len > 0)
	{
		memcpy(this->block + this->block_offset, data, data_len);
		this->block_offset += data_len;
		this->message_bitsize += 8 * data_len;
		assert(this->block_offset < block_size);
	}
	assert(this->block_offset < block_size);
}

static void append_length(struct s_hash_ctx *this)
{
	unsigned char length_in_two_words[1024];
	unsigned char *w0;
	unsigned char *w1;

	memcpy(&length_in_two_words, &this->message_bitsize,
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
	memcpy(this->block + this->class->block_size - this->class->word_size,
			w1, this->class->word_size);
	memcpy(this->block + this->class->block_size - this->class->word_size * 2,
			w0, this->class->word_size);
}

void hash_finalize(struct s_hash_ctx *this)
{
	size_t block_size;
	
	block_size = this->class->block_size;
	assert(this->block_offset < block_size);
	this->block[this->block_offset] = 0x80;
	this->block_offset += 1;
	if (this->block_offset + this->class->word_size * 2 >= block_size)
	{
		if (this->block_offset != block_size)
			bzero(this->block + this->block_offset, block_size - this->block_offset  - 1);
		this->class->process_block(this);
		this->block_offset = 0;
		this->processed_blocks++;
		bzero(this->block, block_size);
	}
	bzero(this->block + this->block_offset, block_size - this->block_offset - 1 - this->class->word_size * 2);
	append_length(this);
	this->block_offset = 0;
	this->class->process_block(this);
	this->processed_blocks++;
}
