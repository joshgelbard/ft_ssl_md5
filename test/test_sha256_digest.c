#include "test.h"
#include "sha256.h"
#include "hash_ctx.h"
#include "hash_algorithm.h"
#include "hash_digest_common.h"

void test_sha256_digest()
{
	printf("%s... ", __func__);
	struct s_hash_algorithm *sha256;

	sha256 = define_sha256_algorithm();
	char *sha256_tests[7][2] = {
		{"", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855" },
		{"a", "ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb" },
		{"abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad" },
		{"message digest", "f7846f55cf23e14eebeab5b4e1550cad5b509e3348fbc4efa3a1413d393cb650" },
		{"abcdefghijklmnopqrstuvwxyz", "71c480df93d6ae2f1efad1447c66c9525e316218cf51fc8d9ed832f2daf18b73" },
		{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", "db4bfcbd4da0cd85a60c3c37d3fbd8805c77f15fc6b1fdfe614ee0a7c8fdb4c0" },
		{"12345678901234567890123456789012345678901234567890123456789012345678901234567890", "f371bc4a311f2b009eef952dd83ca80e2b60026c8e935592d0f9c308453c813e" }
	};
	struct s_hash_ctx ctx;
	for (int i = 0; i < 7; i++)
	{
		char *input = sha256_tests[i][0];
		hash_initialize(sha256, &ctx);
		hash_update(&ctx, input, strlen(input));
		hash_finalize(&ctx);
		char *expected = sha256_tests[i][1];
		char *got = hash_get_string(&ctx);
		//printf("test %d: string ->%s<- (len %lu)\n%s<--got\n%s<--expected\n",
		//		i, input, strlen(input), got, expected);
		assert(!strcmp(expected, got));
	}
	printf("ok\n");
}

