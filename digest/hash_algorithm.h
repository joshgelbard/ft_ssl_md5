#ifndef HASH_ALGORITHM_CLASS_H
# define HASH_ALGORITHM_CLASS_H
# include <string.h>

enum e_hash_algorithm
{
	MD5,
	SHA256,
	HASH_ALGORITHM_COUNT
};

struct s_hash_ctx;

struct s_hash_algorithm
{
	int is_big_endian;
	void (*finish_initialize)(struct s_hash_ctx *this);
	void (*process_block)(struct s_hash_ctx *this);
	char *(*to_string)(struct s_hash_ctx *this);
	size_t block_size;
	size_t word_size;
	size_t digest_size;
	char *algorithm_name;
	int algorithm_id;
};
#endif
