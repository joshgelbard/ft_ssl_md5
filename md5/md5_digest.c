#include "md5.h"
#include "md5_internal.h"
#include "hash_algorithm.h"
#include "hash_ctx.h"
#include <stdint.h>
#include <string.h>

#define A digest[(0 + (4 - step % 4)) % 4]
#define B digest[(1 + (4 - step % 4)) % 4]
#define C digest[(2 + (4 - step % 4)) % 4]
#define D digest[(3 + (4 - step % 4)) % 4]
#define F md5_F
#define G md5_G
#define H md5_H
#define I md5_I
#define K md5_K
#define S md5_S
#define T md5_T
#define LEFT_ROTATE(x, n) (((x) << (n)) | (((x) & 0xffffffff) >> (32 - (n))))

typedef uint32_t (*t_md5_basic_transform)(uint32_t, uint32_t, uint32_t);

t_md5_basic_transform g_transform[4] = { &F, &G, &H, &I };

static void set_initial_digest_values(struct s_hash_ctx *this)
{
	uint32_t *digest;

	digest = this->digest;
	digest[0] = 0x67452301;
	digest[1] = 0xefcdab89;
	digest[2] = 0x98badcfe;
	digest[3] = 0x10325476;
}

static void md5_process_block(struct s_hash_ctx *this)
{
	int round;
	int step;
	uint32_t *digest;
	uint32_t *block;
	uint32_t digest_store[4];

	digest = this->digest;
	block = (uint32_t *)(this->block);
	memcpy(digest_store, digest, sizeof(digest_store));
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
	digest[0] += digest_store[0];
	digest[1] += digest_store[1];
	digest[2] += digest_store[2];
	digest[3] += digest_store[3];
}

struct s_hash_algorithm *define_md5_algorithm(void)
{
	struct s_hash_algorithm	*md5;

	md5 = malloc(sizeof(*md5));
	md5->is_big_endian = 0;
	md5->process_block = &md5_process_block;
	md5->finish_initialize = &set_initial_digest_values;
	md5->digest_size= 16;
	md5->word_size = 4;
	md5->block_size = 64;
	md5->algorithm_name = "md5";
	md5->algorithm_id = MD5;
	return (md5);
}
