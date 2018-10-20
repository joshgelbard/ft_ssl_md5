#ifndef MEMPRINT_H
# define MEMPRINT_H
# include <string.h>

void mem2string(void *p, size_t len, char *s);
void memprint(void *p, size_t len);
#endif
