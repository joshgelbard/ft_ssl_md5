#ifndef SHA_256_INTERNAL_H
# define SHA_256_INTERNAL_H
# include <stdint.h>

extern uint32_t sha256_K[64];
uint32_t sha256_CH(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha256_MAJ(uint32_t x, uint32_t y, uint32_t z);
uint32_t sha256_BSIG(uint32_t x, int r1, int r2, int r3);
uint32_t sha256_SSIG(uint32_t x, int r1, int r2, int s);
#endif
