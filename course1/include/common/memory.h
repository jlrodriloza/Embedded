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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Takes two byte pointers (source and destination) and a length of 
 * bytes to move from the source to the destination, handling possible 
 * overlap of source and destination.
 * Returns a pointer to destination.
 *
 * @ param src Pointer to source to be copied
 * @ param dst Pointer to destination where data is to be copied
 *
 * @ return Pointer that will coincide with dst if no overlap occurred. 
 * Otherwise, a new pointer consecutive to the end of src will be returned.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @ brief Takes two byte pointers (source and destination) and a length 
 * of bytes to copy from source to destination. No overlapping handling
 * will be made, so data may be corrupted if there is overlap.
 *
 * Returns a pointer to destination.
 *
 * @ param src Pointer to source to be copied
 * @ param dst Pointer to destination where data is to be copied
 *
 * @ return Pointer that will coincide with dst. 
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @ brief Takes a byte pointer to a source and a length 
 * of bytes and sets all locations to a given value.
 *
 * Returns a pointer to the source.
 *
 * @ param src Pointer to source.
 *
 * @ return Pointer that will coincide with src. 
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @ brief Takes a byte pointer to a source and a length 
 * of bytes and sets all locations to a 0.
 *
 * Returns a pointer to the source.
 *
 * @ param src Pointer to source.
 *
 * @ return Pointer that will coincide with src. 
 */
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @ brief Takes a byte pointer to a source and a length 
 * of bytes and reverses the order of all the bytes.
 *
 * Returns a pointer to the source.
 *
 * @ param src Pointer to source.
 *
 * @ return Pointer that will coincide with src. 
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @ brief Takes a number of words to allocate in dynamic 
 * memory
 *
 * Returns a pointer to the memory if successful or a null pointer if not.
 *
 * @ param length number of words.
 *
 * @ return Pointer to the memory allocated. 
 */
int32_t * reserve_words(size_t length);

/**
 * @ brief Frees dynamic memory allocation, given a certain pointer
 *
 * @ param src memory to be freed.
 *
 * @ return void
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
