#include "stats.h"
#include "stdio.h"

// sorts the element given in the position "index_to_attack" in the array "arr" of size "arr_size"
char sort_array_one_number(unsigned char* arr, unsigned int arr_size, unsigned int index_to_attack)
{
	char already_ordered = 1;
	for (unsigned int i = index_to_attack; i < arr_size - 1; ++i)
	{
		if (arr[i] < arr[i + 1])
		{
			already_ordered = 0;
			unsigned char aux = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = aux;
		}
	}

	return already_ordered;
}

void sort_array(unsigned char* arr, unsigned int arr_size)
{
	/*  1 3 2
		1 3 2 --> 3 1 2
		3 1 2 --> 3 2 1
	*/

	/*  1 2 3
		1 2 3 --> 2 1 3 --> 2 3 1
		2 3 1 --> 3 2 1
	*/

	/*
		2 1 3 --> 2 1 3 --> 2 3 1
		2 3 1 --> 3 2 1
	*/

	for (unsigned int index_to_attack = 0; index_to_attack < arr_size - 1; ++index_to_attack)
	{
		char already_ordered = sort_array_one_number(arr, arr_size, 0);

		if (already_ordered == 1)
			break;
	}
}

void print_array(unsigned char* arr, unsigned int arr_size)
{
	for (unsigned int i = 0; i < arr_size; ++i)
	{
		printf("%u", arr[i]);
		printf("\n");
	}
}

unsigned char find_maximum(unsigned char* arr, unsigned int arr_size)
{
	sort_array(arr, arr_size);

	return arr[0];
}

unsigned char find_minimum(unsigned char* arr, unsigned int arr_size)
{
	sort_array(arr, arr_size);

	return arr[arr_size - 1];
}

unsigned int find_median(unsigned char* arr, unsigned int arr_size)
{
	sort_array(arr, arr_size);

	unsigned int median = 0;

	if (arr_size % 2 == 0)
	{
		/*
		 * 0 1 2 3 --> [1]/2 + [2]/2
		 * * 0 1 2 3 4 5 --> [2]/2 + [3]/2
		 */
		unsigned int index1 = arr_size / 2 - 1;
		unsigned int index2 = arr_size / 2;
		median = (unsigned int)((arr[index1]/2 + arr[index2]/2));
	}
	else
	   /*
		* 0 1 2 --> [1] = 3/2 --> 1.5 --> 1
		* 0 1 2 3 4--> [2] = 5/2 --> 2.5 --> 2
		*/
		median = arr[arr_size/2];
		
	return median;
}

unsigned int find_mean(unsigned char* arr, unsigned int arr_size)
{
	unsigned int mean = 0.0;

	for (unsigned int i = 0; i < arr_size; ++i)	
		mean += arr[i];
	
	return mean / arr_size;
}