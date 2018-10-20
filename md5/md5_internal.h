#ifndef MD5_INTERNAL_H
# define MD5_INTERNAL_H
# include <stdint.h>

uint32_t	md5_F(uint32_t x, uint32_t y, uint32_t z);
uint32_t	md5_G(uint32_t x, uint32_t y, uint32_t z);
uint32_t	md5_H(uint32_t x, uint32_t y, uint32_t z);
uint32_t	md5_I(uint32_t x, uint32_t y, uint32_t z);
extern		uint32_t md5_T[64];
extern		int md5_S[4][4];
extern		int md5_K[4][16];
#endif
