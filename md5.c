#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "md5.h"

typedef uint32_t	(*t_md5_basic_transform)(uint32_t, uint32_t, uint32_t);
static struct s_md5_state g_state =
{
	.digest = { 0, 0, 0, 0 },
	.message = NULL,
	.wordcount = 0
};
static t_md5_basic_transform g_transform[4] = { &F, &G, &H, &I };
static int g_step_idx = 0;

void	print_digest(void)
{
	int i;

	i = 0;
	while (i < 16)
	{
		printf("%02x", ((unsigned char *)g_state.digest)[i]);
		i++;
	}
	printf("\n");
}

void	md5_init(void *orig_message, size_t orig_len)
{
	size_t		padding_bytes;
	size_t		result_message_size;
	uint64_t	bits;

	free(g_state.message);
	g_state.digest[0] = 0x67452301;
	g_state.digest[1] = 0xefcdab89;
	g_state.digest[2] = 0x98badcfe;
	g_state.digest[3] = 0x10325476;
	padding_bytes = 56 - orig_len % 56;
	result_message_size = orig_len + padding_bytes + sizeof(uint64_t);
	g_state.message = malloc(result_message_size);
	bzero(g_state.message, result_message_size);
	memcpy(g_state.message, orig_message, orig_len);
	g_state.message[orig_len] = 0x80;
	bits = orig_len * 8;
	memcpy(g_state.message + orig_len + padding_bytes, &bits, sizeof(bits));
	g_state.wordcount = (orig_len + padding_bytes + sizeof(uint64_t)) / 4;
}

#define A g_state.digest[(0 + (4 - g_step_idx % 4)) % 4]
#define B g_state.digest[(1 + (4 - g_step_idx % 4)) % 4]
#define C g_state.digest[(2 + (4 - g_step_idx % 4)) % 4]
#define D g_state.digest[(3 + (4 - g_step_idx % 4)) % 4]
#define LEFT_ROTATE(x, n) (((x) << (n)) | (((x) & 0xffffffff) >> (32 - (n))))


void	process_16word_block(int i)
{
	uint32_t	digest_store[4];
	uint32_t	current_block[16];
	int			round;
	int			step;

	memcpy(digest_store, g_state.digest, sizeof(digest_store));
	memcpy(current_block, g_state.message + i * 64, 64);
	round = 0;
	while (round < 4)
	{
		step = 0;
		while (step < 16)
		{
			g_step_idx = step;
			A += g_transform[round](B, C, D)
				+ current_block[K[round][step]] + T[round * 16 + step];
			A = B + LEFT_ROTATE(A, S[round][step % 4]);
			step++;
		}
		round++;
	}
	g_state.digest[0] += digest_store[0];
	g_state.digest[1] += digest_store[1];
	g_state.digest[2] += digest_store[2];
	g_state.digest[3] += digest_store[3];
}

void	do_md5(void *message, size_t len)
{
	unsigned int i;

	md5_init(message, len);
	i = 0;
	while (i < g_state.wordcount / 16)
	{
		process_16word_block(i);
		i++;
	}
	print_digest();
}
