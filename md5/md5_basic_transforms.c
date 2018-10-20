#include <stdint.h>
#include "md5_internal.h"

uint32_t md5_F(uint32_t x, uint32_t y, uint32_t z)
{
    return (((x) & (y)) | ((~(x)) & (z)));
}

uint32_t md5_G(uint32_t x, uint32_t y, uint32_t z)
{
    return (((x) & (z)) | ((y) & (~(z))));
}

uint32_t md5_H(uint32_t x, uint32_t y, uint32_t z)
{
    return ((x) ^ (y) ^ (z));
}

uint32_t md5_I(uint32_t x, uint32_t y, uint32_t z)
{
    return ((y) ^ ((x) | (~(z))));
}
