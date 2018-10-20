#include <stdio.h>
#include <stdlib.h>
#include "algorithm_lookup.h"
#include "digest.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("give an argument string");
        exit(0);
    }
	char *algo_name = "md5";
    char *input_arg = argv[1];
	define_digest_algorithms();
	do_hash_digest(algo_name, input_arg);
	char *d = get_last_digest_string();
	printf("%s\n", d);
    return 0;
}
