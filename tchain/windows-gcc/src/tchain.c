#include "tchain/types.h"

/* tchain code common to all libraries (ewl and newlib) */

/* These asserts are here, instead of the tchain/types.h header, to avoid
 * conpiler warnings about this file being an empty translation unit. */
static_assert(sizeof(char_t) == 1, "Invalid char_t size");
static_assert(sizeof(int8_t) == 1, "Invalid int8_t size");
static_assert(sizeof(uint8_t) == 1, "Invalid uint8_t size");
static_assert(sizeof(int16_t) == 2, "Invalid int16_t size");
static_assert(sizeof(uint16_t) == 2, "Invalid uint16_t size");
static_assert(sizeof(int32_t) == 4, "Invalid int32_t size");
static_assert(sizeof(uint32_t) == 4, "Invalid uint32_t size");
static_assert(sizeof(float32_t) == 4, "Invalid float32_t size");
static_assert(sizeof(float64_t) == 8, "Invalid float64_t size");
