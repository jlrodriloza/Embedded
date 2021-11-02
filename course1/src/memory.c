/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	if((src >= dst) && (src-dst < length*sizeof(uint8_t*)) ||
	   (src <  dst) && (dst-src < length*sizeof(uint8_t*))){
	
		// there is overlap, we have to copy data after the source
	
		dst = src + length*sizeof(uint8_t*);
	}

	// once we have set our destination to a safe place, we copy the data.
	//
	// Should we allocate memory???

	unsigned int i;
	for (i=0; i < size_t; i++) {
		*dst = *src;
		++src;
		++dst;
	}

	return dst-length*sizeof(uint8_t*);
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);
{
	
	unsigned int i;
	for (i=0; i < size_t; i++) {
		*dst = *src;
		++src;
		++dst;
	}

	return dst-length*sizeof(uint8_t*);
}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	unsigned int i;
	for (i=0; i < size_t; i++) {
		*src = value;
		++src;	
	}

	return src - length*sizeof(uint8_t*);
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	// just call to my_memset with value = 0.
	
	return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	
	size_t end = -1;
	if(length % 2 == 0)
		end = length/2;
	else
		end = length/2 + 1;

	// we run through the array up to its middle point
	// and swap a position with its symmetrical

	unsigned int i;
	for (i=0; i < end; i++) {
		uint8_t aux = *(src + i);
		*(src + i) = *(src + length - i - 1);
	}

	return src;
}

int32_t * reserve_words(size_t length)
{
	return malloc(length*sizeof(int32_t*));
}

void free_words(int32_t * src)
{
	free(src);
}
