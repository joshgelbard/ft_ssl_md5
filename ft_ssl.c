#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("give an argument string");
        exit(0);
    }
    char *s = argv[1];
    do_md5(s, strlen(s));
    return 0;
}
