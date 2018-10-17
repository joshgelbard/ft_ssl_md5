#include <stdint.h>
#include "md5.h"

uint32_t F(uint32_t x, uint32_t y, uint32_t z)
{
    return (((x) & (y)) | ((~(x)) & (z)));
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z)
{
    return (((x) & (z)) | ((y) & (~(z))));
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z)
{
    return ((x) ^ (y) ^ (z));
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z)
{
    return ((y) ^ ((x) | (~(z))));
}
