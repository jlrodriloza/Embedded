
#include "data.h"
#include <stddef.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int32_t maximum_exponent = 10;
	size_t i = maximum_exponent; // current figure index. Starts in maximum exponent and 
				  //decreases by one in each step
	int32_t number_proxy = 0; // partial sum of (base raised to indexes) multiplied by figures
	int32_t factor = 1; // base raised to current index

	if(data < 0) // apply minus sign first
	{
		*ptr = '-'; // lets pray for it to the way of casting '-' to unit8_t
		++ptr;
	}

	short first_non_zero_figure_detected = 0;
	uint8_t length = 0;
	while(i > -1)
	{

		for(size_t j = 0; j < i; ++j)
			factor *= base;

		// calculate current figure as the remaining of the division between 
		// the input number and the current factor
		
		int32_t figure = (data-number_proxy)/factor;

		if (figure != 0)
			first_non_zero_figure_detected = 1;

		if(first_non_zero_figure_detected == 1)
		{
			// cast figure from integer to "char"
			*ptr = figure;

			// update number proxy with the base raised to the current index, 
			// times the current figure
			number_proxy += factor*figure;

			// increase pointer and length
			++ptr;
			++length;
		}

		// decrase string position index
		--i;
	}

	// must be a null pointer terminated string
	*ptr = 0;

	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	return 0;
}
