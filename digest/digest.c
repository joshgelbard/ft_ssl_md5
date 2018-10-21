#include "digest.h"
#include <stdlib.h>
#include <string.h>
#include "algorithm_lookup.h"
#include "hash_digest_common.h"
#include "hash_ctx.h"
#include "util.h"

static struct s_hash_ctx g_current_ctx;

void do_hash_digest(char *algo_name, char *input)
{
	struct s_hash_algorithm *algorithm;

	algorithm = get_hash_algorithm_by_name(algo_name);
	hash_initialize(algorithm, &g_current_ctx);
	hash_update(&g_current_ctx, input, xstrlen(input));
	hash_finalize(&g_current_ctx);
}

char *get_last_digest_string(void)
{
	return (hash_get_string(&g_current_ctx));
}
