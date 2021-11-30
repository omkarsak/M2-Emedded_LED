# Blinky Project In Action

## ON (Both the input are low)
<img src="https://github.com/VisheshYadav288037/Activity_1/blob/main/simulation/Both%20input%20off.png" > <br/>
## OFF (One input high and one low)
<img src="https://github.com/VisheshYadav288037/Activity_1/blob/main/simulation/either%20input%20on.png" > <br/>
## OFF (One input high and one low)
<img src="https://github.com/VisheshYadav288037/Activity_1/blob/main/simulation/either%20input%20on%202.png" > <br/>
## OFF (Both the input are high)
<img src="https://github.com/VisheshYadav288037/Activity_1/blob/main/simulation/Both%20input%20on.png" > <br/>

## Code 
```
	for(;;)
    {
        if((!(PINB & (1<<PB0))) && (!(PINC & (1<<PC0))))
    {
        change_led_state(LED_ON);
		delay_ms(LED_ON_TIME);
    }

    else if((!(PINB & (1<<PB0))) && ((PINC & (1<<PC0))))
    {
        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
    }

    else if(((PINB & (1<<PB0))) && (!(PINC & (1<<PC0))))
    {
        change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
    }

    else if(((PINB & (1<<PB0))) && ((PINC & (1<<PC0))))
        {
            change_led_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
    }

    }
```
