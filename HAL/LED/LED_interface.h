#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define HIGH        1
#define LOW         0

#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0
/**
 * typedef struct LED - define led
 * @param led_port: the port that led connected with.
 * @param led_pin: the pin that led connected with.
 * @param active_state: active High or active low.
 * @param start_state: led start state (on or off).
*/
typedef struct LED
{
    u8 led_port;
    u8 led_pin;
    u8 active_state;
    u8 start_state;
}LED;

void led_init(LED led);
void led_on(LED led);
void led_off(LED led);
void led_toggle(LED led);

#endif