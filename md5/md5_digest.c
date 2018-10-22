/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_digest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:14 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:14 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "md5_internal.h"
#include "algorithm_lookup.h"
#include "hash_algorithm.h"
#include "hash_ctx.h"
#include <stdint.h>
#include <string.h>
#include "util.h"

#define A digest[(0 + (4 - step % 4)) % 4]
#define B digest[(1 + (4 - step % 4)) % 4]
#define C digest[(2 + (4 - step % 4)) % 4]
#define D digest[(3 + (4 - step % 4)) % 4]
#define F g_md5_f
#define G g_md5_g
#define H g_md5_h
#define I g_md5_i
#define K g_md5_k
#define S g_md5_s
#define T g_md5_t
#define LEFT_ROTATE(x, n) (((x) << (n)) | (((x) & 0xffffffff) >> (32 - (n))))

typedef uint32_t	(*t_md5_basic_transform)(uint32_t, uint32_t, uint32_t);

t_md5_basic_transform g_transform[4] = { &F, &G, &H, &I };

static void				set_initial_digest_values(struct s_hash_ctx *this)
{
	uint32_t *digest;

	digest = this->digest;
	digest[0] = 0x67452301;
	digest[1] = 0xefcdab89;
	digest[2] = 0x98badcfe;
	digest[3] = 0x10325476;
}

static void				combine_digest_with_store(uint32_t *d, uint32_t *s)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		d[i] += s[i];
		i++;
	}
}

static void				md5_process_block(struct s_hash_ctx *this)
{
	int			round;
	int			step;
	uint32_t	*digest;
	uint32_t	*block;
	uint32_t	digest_store[4];

	digest = this->digest;
	block = (uint32_t *)(this->block);
	xmemcpy(digest_store, digest, sizeof(digest_store));
	round = 0;
	while (round < 4)
	{
		step = 0;
		while (step < 16)
		{
			A += g_transform[round](B, C, D)
				+ block[K[round][step]] + T[round * 16 + step];
			A = B + LEFT_ROTATE(A, S[round][step % 4]);
			step++;
		}
		round++;
	}
	combine_digest_with_store(digest, digest_store);
}

struct s_hash_algorithm	*define_md5_algorithm(void)
{
	struct s_hash_algorithm	*md5;

	md5 = zalloc(sizeof(*md5));
	md5->is_big_endian = 0;
	md5->process_block = &md5_process_block;
	md5->finish_initialize = &set_initial_digest_values;
	md5->digest_size = 16;
	md5->word_size = 4;
	md5->block_size = 64;
	md5->algorithm_name = "md5";
	md5->algorithm_id = MD5;
	return (md5);
}
