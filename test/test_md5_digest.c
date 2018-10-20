#include "test.h"
#include "md5.h"
#include "hash_ctx.h"
#include "hash_algorithm.h"
#include "hash_digest_common.h"

void test_md5_digest()
{
	printf("%s... ", __func__);
	struct s_hash_algorithm *md5;

	md5 = define_md5_algorithm();
	char *md5_tests[7][2] = {
		{"", "d41d8cd98f00b204e9800998ecf8427e" },
		{"a", "0cc175b9c0f1b6a831c399e269772661" },
		{"abc", "900150983cd24fb0d6963f7d28e17f72" },
		{"message digest", "f96b697d7cb7938d525a2f31aaf161d0" },
		{"abcdefghijklmnopqrstuvwxyz", "c3fcd3d76192e4007dfb496cca67e13b" },
		{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", "d174ab98d277d9f5a5611c2c9f419d9f" },
		{"12345678901234567890123456789012345678901234567890123456789012345678901234567890", "57edf4a22be3c955ac49da2e2107b67a" }
	};
	struct s_hash_ctx ctx;
	for (int i = 0; i < 7; i++)
	{
		char *input = md5_tests[i][0];
		hash_initialize(md5, &ctx);
		hash_update(&ctx, input, strlen(input));
		hash_finalize(&ctx);
		char *expected = md5_tests[i][1];
		char *got = hash_get_string(&ctx);
//		printf("test %d: string ->%s<- (len %lu)\n%s<--got\n%s<--expected\n",
//				i, input, strlen(input), got, expected);
		assert(!strcmp(expected, got));
	}
}

