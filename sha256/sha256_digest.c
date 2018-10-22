/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_digest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:08 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:08 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "algorithm_lookup.h"
#include "hash_ctx.h"
#include "hash_algorithm.h"
#include "sha256_internal.h"
#include "util.h"

static void				set_initial_digest_values(struct s_hash_ctx *this)
{
	uint32_t *digest;

	digest = this->digest;
	digest[0] = 0x6a09e667;
	digest[1] = 0xbb67ae85;
	digest[2] = 0x3c6ef372;
	digest[3] = 0xa54ff53a;
	digest[4] = 0x510e527f;
	digest[5] = 0x9b05688c;
	digest[6] = 0x1f83d9ab;
	digest[7] = 0x5be0cd19;
}

static uint32_t			g_message_schedule[64];
#define SSIG1(x) g_sha256_ssig(x, 17, 19, 10)
#define SSIG0(x) g_sha256_ssig(x, 7, 18, 3)
#define BSIG0(x) g_sha256_bsig(x, 2, 13, 22)
#define BSIG1(x) g_sha256_bsig(x, 6, 11, 25)
#define CH g_sha256_ch
#define K g_sha256_k
#define MAJ g_sha256_maj
#define W g_message_schedule
#define A digest[0]
#define B digest[1]
#define C digest[2]
#define D digest[3]
#define E digest[4]
#define F digest[5]
#define G digest[6]
#define H digest[7]

void					fill_message_schedule(struct s_hash_ctx *this)
{
	uint32_t	*block;
	int			i;

	block = (uint32_t *)(this->block);
	i = 0;
	while (i < 16)
	{
		W[i] = block[i];
		reverse_byte_order(&W[i], sizeof(W[i]));
		i++;
	}
	while (i < 64)
	{
		W[i] =
			SSIG1(W[i - 2])
			+ W[i - 7]
			+ SSIG0(W[i - 15])
			+ W[i - 16];
		i++;
	}
}

static void				do_one_block_process_step(uint32_t *digest, int i)
{
	uint32_t	tmp[2];

	tmp[0] = H + BSIG1(E) + CH(E, F, G) + K[i] + W[i];
	tmp[1] = BSIG0(A) + MAJ(A, B, C);
	H = G;
	G = F;
	F = E;
	E = D + tmp[0];
	D = C;
	C = B;
	B = A;
	A = tmp[0] + tmp[1];
}

static void				sha256_process_block(struct s_hash_ctx *this)
{
	size_t		i;
	uint32_t	*digest;
	uint32_t	digest_store[8];

	fill_message_schedule(this);
	digest = (uint32_t *)(this->digest);
	xmemcpy(digest_store, digest, sizeof(digest_store));
	i = 0;
	while (i < 64)
	{
		do_one_block_process_step(digest, i);
		i++;
	}
	i = 0;
	while (i < this->class->digest_size / this->class->word_size)
	{
		digest[i] += digest_store[i];
		i++;
	}
}

struct s_hash_algorithm	*define_sha256_algorithm(void)
{
	struct s_hash_algorithm	*sha256;

	sha256 = zalloc(sizeof(*sha256));
	sha256->is_big_endian = 1;
	sha256->process_block = &sha256_process_block;
	sha256->finish_initialize = &set_initial_digest_values;
	sha256->digest_size = 32;
	sha256->word_size = 4;
	sha256->block_size = 64;
	sha256->algorithm_name = "sha256";
	sha256->algorithm_id = SHA256;
	return (sha256);
}
