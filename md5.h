#ifndef SSL_MD5_H
# define SSL_MD5_H
# include <stdint.h>
# include <string.h>
# define MD5_DIGEST_LEN 16

struct		s_md5_state {
    uint32_t		digest[4];
    unsigned char	*message;
    size_t			wordcount;
};

uint32_t	F(uint32_t x, uint32_t y, uint32_t z);
uint32_t	G(uint32_t x, uint32_t y, uint32_t z);
uint32_t	H(uint32_t x, uint32_t y, uint32_t z);
uint32_t	I(uint32_t x, uint32_t y, uint32_t z);
extern		uint32_t T[64];
extern		int S[4][4];
extern		int K[4][16];

void		do_md5(void *message, size_t len);
#endif
