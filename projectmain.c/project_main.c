/**
 * @file main.c
 * @author Vishesh.Y()
 * @brief Project to Blink an LED at 1000ms ON and 500 ms OFF Interval when the two inputs are low
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

#include "user_utils.h"
#include "blinky.h"
/**
 * @brief Initialize all the peripherals and pin configurations
 * 
 */

void peripheral_init(void)
{
    /* Configure LED and Input pins */

	DDRB &= ~(1 << PB0);
    DDRC &= ~(1 << PC0);
    DDRD |= (1 << PD0);
    PORTB |= (1 << PB0);
    PORTC |= (1 << PC0);
}

void change_led_state(uint8_t state)
{
    /* Turn the LED on and off */

	LED_PORT = (state << LED_PIN);
}

/**
 * @brief Main function where the execution starts
 * @note Port B and C are the input ports (by defult high)
 * @note Port D is the output port 
 * @return int Return 0 if program completes successfully 
 */

int main(void)
{
    /* Initialize peripherals */
	peripheral_init();

	 for(;;)
    {
        /* If PORTB0 and PORTC0 are low then glow the led */
        if((!(PINB & (1<<PB0))) && (!(PINC & (1<<PC0))))
    {
        change_led_state(LED_ON);
		delay_ms(LED_ON_TIME);
    }

    /* If PORTB0 is low and  PORTC0 is high then turn off the led */
    else if((!(PINB & (1<<PB0))) && ((PINC & (1<<PC0))))
    {
        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
    }

    /* If PORTB0 is high and PORTC0 is low then turn off the led */
    else if(((PINB & (1<<PB0))) && (!(PINC & (1<<PC0))))
    {
        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
    }

    /* If PORTB0 and PORTC0 are high then turn off the led */
    else if(((PINB & (1<<PB0))) && ((PINC & (1<<PC0))))
        {
            change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
    }

    }

	return 0;
}
