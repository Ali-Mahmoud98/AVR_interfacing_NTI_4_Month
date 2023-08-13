#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"

#include "DIO_Interface.h"


void led_init(LED led)
{
    /*initialization of led*/
    DIO_voidSetPinDirection(led.led_port, led.led_pin, DIO_u8_OUTPUT);
    switch (led.active_state)
    {
    case ACTIVE_HIGH:
        switch (led.start_state)
        {
        case HIGH:
            DIO_voidSetPinValue(led.led_port, led.led_pin, HIGH);
            break;
        case LOW:
            DIO_voidSetPinValue(led.led_port, led.led_pin, LOW);
            break;
        }
        break;
    case ACTIVE_LOW:
        switch (led.start_state)
        {
        case HIGH:
            DIO_voidSetPinValue(led.led_port, led.led_pin, LOW);
            break;
        case LOW:
            DIO_voidSetPinValue(led.led_port, led.led_pin, HIGH);
            break;
        }
        break;
    }
}
void led_on(LED led)
{
    switch (led.active_state)
    {
    case ACTIVE_HIGH:
        DIO_voidSetPinValue(led.led_port, led.led_pin, HIGH);
        break;
    case ACTIVE_LOW:
        DIO_voidSetPinValue(led.led_port, led.led_pin, LOW);
        break;
    }
}
void led_off(LED led)
{
   switch (led.active_state)
    {
    case ACTIVE_HIGH:
        DIO_voidSetPinValue(led.led_port, led.led_pin, LOW);
        break;
    case ACTIVE_LOW:
        DIO_voidSetPinValue(led.led_port, led.led_pin, HIGH);
        break;
    } 
}
void led_toggle(LED led)
{
    if (DIO_voidGetPinValue(led.led_port, led.led_pin) == LOW)
    {
        led_on(led);
    }
    else if (DIO_voidGetPinValue(led.led_port, led.led_pin) == HIGH)
    {
        led_off(led);
    }
}