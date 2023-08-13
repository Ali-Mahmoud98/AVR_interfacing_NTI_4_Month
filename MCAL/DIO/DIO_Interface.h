/***************************************************************************************/
/***************************************************************************************/
//File guard 
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

//Registers macros
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

//Pins macros
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

//Other macros
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1
 
#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1

/**
 * DIO_voidSetPinValue - Set the value of a specific pin in a port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8PinId: An 8-bit unsigned integer representing the pin identifier in the port.
 *        Valid values are from 0 to 7, corresponding to the pin number in the port.
 * @param Copy_u8Value: An 8-bit unsigned integer representing the value to be set for the pin.
 *        The value should be either HIGH (1) or LOW (0) to set the pin to the desired output state.
 * @return None.
 */
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);

/**
 * DIO_voidTogglePinValue - Toggle the value of a specific pin in a port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8PinId: An 8-bit unsigned integer representing the pin identifier in the port.
 *        Valid values are from 0 to 7, corresponding to the pin number in the port.
 * @return None.
 */
void DIO_voidTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/**
 * DIO_voidSetPinDirection - Set the direction of a specific pin in a port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8PinId: An 8-bit unsigned integer representing the pin identifier in the port.
 *        Valid values are from 0 to 7, corresponding to the pin number in the port.
 * @param Copy_u8Direction: An 8-bit unsigned integer representing the direction to set for the pin.
 *        Use DIO_u8_OUTPUT to set the pin as output, or DIO_u8_INPUT to set it as input.
 * @return None.
 */
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);

/**
 * DIO_voidGetPinValue - Get the value of a specific pin in a port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8PinId: An 8-bit unsigned integer representing the pin identifier in the port.
 *        Valid values are from 0 to 7, corresponding to the pin number in the port.
 * @return An 8-bit unsigned integer representing the value of the specified pin.
 *         The function returns either HIGH (1) or LOW (0) based on the pin's input state.
 */
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/**
 * DIO_voidSetPortValue - Set the value of a specific port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8Value: An 8-bit unsigned integer representing the value to be set for the port.
 *        The value should be a combination of HIGH and LOW (1 and 0) bits representing
 *        the desired output state for each pin in the port.
 * @return None.
 */
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);

/**
 * DIO_voidSetPortDirection - Set the direction of a specific port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8Direction: An 8-bit unsigned integer representing the direction to set for the port.
 *        Use DIO_u8_OUTPUT to set the port as output, or DIO_u8_INPUT to set it as input.
 * @return None.
 */
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);

/**
 * DIO_voidGetPortValue - Get the value of a specific port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 * @return An 8-bit unsigned integer representing the value of the specified port.
 */
u8 DIO_voidGetPortValue(u8 Copy_u8PortId);

#endif
/***************************************************************************************/