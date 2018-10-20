#include <stdio.h>
#include "test.h"
int main(void)
{
	test_md5_digest();
	test_sha256_digest();
	printf("ok\n");
}
