
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

// Converts from integer to ASCII string using pointer arithmetic
// (not array indexing) 
// data: the number that we need to convert
// base: unsigned integer between 2 and 16 that represents the base
// in which intepret the integer. Example: 11 --> "11" if the base is 10 or
// --> "3" if base is 2.
// ptr: holds the new ASCII string
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif // __DATA_H__
