#include "stats.h"
#include "stdio.h"

int main()
{
    unsigned int N = 6;
    unsigned char* arr = new unsigned char[N];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 1;
    arr[3] = 24;
    arr[4] = 28;
    arr[5] = 238;

	print_array(arr, N);
		
	printf("\nSorting...\n\n"); 
	sort_array(arr, N);
	
    print_array(arr, N);

    unsigned int min = find_minimum(arr, N);
    unsigned int max = find_maximum(arr, N);
    unsigned int median = find_median(arr, N);
    unsigned int mean = find_mean(arr, N);

    printf("Max is %u \n", max);
    printf("Min is %u \n", min);
    printf("Median is %u \n", median);
    printf("Mean is %u \n", mean);

	return 0;
}