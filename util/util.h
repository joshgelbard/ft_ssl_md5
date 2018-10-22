#ifndef UTIL_H
# define UTIL_H
# include <string.h>

extern char	*g_progname;
extern char	*g_modulename;

size_t		xstrlen(char *s);
void		xprint(char *s);
void		xprinterr(char *s);
void		xputs(char *s);
void		xputserr(char *s);
int			xstrcmp(char *s, char *t);
void		mem2string(void *p, size_t len, char *s);
void		reverse_byte_order(void *p, size_t len);
void		xmemcpy(void *dst, void *src, size_t len);
void		*zalloc(size_t len);
void		xzero(void *p, size_t len);
void		xperror(char *s);
void		xp_myerror(char *s);
#endif
