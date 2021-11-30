#include "user_utils.h"

/**
 * @brief Function to generate delay in microseconds
 * 
 * @param delay_time 
 */

void delay_ms(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}
