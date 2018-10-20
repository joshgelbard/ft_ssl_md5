#include "algorithm_lookup.h"
#include <stdlib.h>
#include "hash_algorithm.h"
#include "md5.h"
#include "sha256.h"

static struct s_hash_algorithm **g_algos;

struct s_hash_algorithm *get_hash_algorithm_by_name(char *name)
{
	int	i;

	i = 0;
	while (i < HASH_ALGORITHM_COUNT)
	{
		if (!strcmp(g_algos[i]->algorithm_name, name))
			return (g_algos[i]);
		i++;
	}
	return (NULL);
}

void define_digest_algorithms(void)
{
	g_algos = malloc(HASH_ALGORITHM_COUNT * sizeof(struct s_hash_algorithm *));
	g_algos[HASH_ALGORITHM_COUNT] = NULL;
	g_algos[0] = define_md5_algorithm();
	g_algos[1] = define_sha256_algorithm();
}
