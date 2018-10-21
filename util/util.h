#ifndef UTIL_H
# define UTIL_H
# include <string.h>

size_t	xstrlen(char *s);
void	xputs(char *s);
void	xprint(char *s);
int		xstrcmp(char *s, char *t);
void	mem2string(void *p, size_t len, char *s);
void	reverse_byte_order(void *p, size_t len);
void	xmemcpy(void *dst, void *src, size_t len);
void	*zalloc(size_t len);
void	xzero(void *p, size_t len);
#endif
