#ifndef HASH_CTX_H
# define HASH_CTX_H
# include <stdlib.h>

struct s_hash_algorithm;

struct s_hash_ctx
{
	struct s_hash_algorithm *class;
	size_t message_bitsize;
	unsigned char *block;
	size_t block_offset;
	size_t processed_blocks;
	void *digest;
};
#endif

