/*main() - The main entry point for your program

print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.

print_array() - Given an array of data and a length, prints the array to the screen

find_median() - Given an array of data and a length, returns the median value

find_mean() - Given an array of data and a length, returns the mean

find_maximum() - Given an array of data and a length, returns the maximum

find_minimum() - Given an array of data and a length, returns the minimum

sort_array() 
*/

//- Given an array of data and a length, sorts the array from largest to smallest.  
// (The zeroth Element should be the largest value, and the last element(n - 1) should be the smallest value.)
void sort_array(unsigned char* arr, unsigned int arr_size);

void print_array(unsigned char* arr, unsigned int arr_size);

unsigned char find_maximum(unsigned char* arr, unsigned int arr_size);

unsigned char find_minimum(unsigned char* arr, unsigned int arr_size);

unsigned int find_median(unsigned char* arr, unsigned int arr_size);

unsigned int find_mean(unsigned char* arr, unsigned int arr_size);



