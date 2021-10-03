#include "stats.h"
#include "stdio.h"

int main()
{
    unsigned int N = 6;
    unsigned char arr[N];
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

    print_statistics(arr, N);

	return 0;
}
