/***************************************************************************************/
/***************************************************************************************/
/* Header Inclusions					     	    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

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
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
    
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinId >= DIO_u8_PIN0))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  switch(Copy_u8Value)    
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;  
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;   
                                }                            
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Value)
                                {       
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            
        }
    }
    else
    {
        
    }
}
/**
 * DIO_voidTogglePinValue - Toggle the value of a specific pin in a port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8PinId: An 8-bit unsigned integer representing the pin identifier in the port.
 *        Valid values are from 0 to 7, corresponding to the pin number in the port.
 * @return None.
 */
void DIO_voidTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinId >= DIO_u8_PIN0))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA: 
                TOG_BIT(DIO_u8_PORTB_REG, Copy_u8PinId); break;   
            case DIO_u8_PORTB: 
                TOG_BIT(DIO_u8_PORTB_REG, Copy_u8PinId); break;
            case DIO_u8_PORTC: 
                TOG_BIT(DIO_u8_PORTB_REG, Copy_u8PinId); break;
            case DIO_u8_PORTD: 
                TOG_BIT(DIO_u8_PORTB_REG, Copy_u8PinId); break;
            
        }
    }
    else
    {
        
    }
}

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
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
    
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinId >= DIO_u8_PIN0))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  switch(Copy_u8Direction)    
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;  
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;   
                                }                            
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Direction)
                                {       
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            
        }
    }
    else
    {
        
    }
}

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
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    
    u8 Local_u8PinValue = 5;
    
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_u8PinId >= DIO_u8_PIN0))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);  break;   
            case DIO_u8_PORTB:  Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);  break;
            case DIO_u8_PORTC:  Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);  break;
            case DIO_u8_PORTD:  Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);  break;
        }
    }
    else
    {
        
    }
    return Local_u8PinValue;    
}

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
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
    if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA: SET_PORT_VAL(DIO_u8_PORTA_REG, Copy_u8Value);  break;   
            case DIO_u8_PORTB: SET_PORT_VAL(DIO_u8_PORTB_REG, Copy_u8Value);  break;
            case DIO_u8_PORTC: SET_PORT_VAL(DIO_u8_PORTC_REG, Copy_u8Value);  break;
            case DIO_u8_PORTD: SET_PORT_VAL(DIO_u8_PORTD_REG, Copy_u8Value);  break;
        }
    }
    else
    {
        
    }    
   
}

/**
 * DIO_voidSetPortDirection - Set the direction of a specific port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 *        Valid values are DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, or DIO_u8_PORTD.
 * @param Copy_u8Direction: An 8-bit unsigned integer representing the direction to set for the port.
 *        Use DIO_u8_OUTPUT to set the port as output, or DIO_u8_INPUT to set it as input.
 * @return None.
 */
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
    if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  
                                SET_REG_VAL(DIO_u8_DDRA_REG, Copy_u8Direction);                           
                                break;
            case DIO_u8_PORTB:  
                                SET_REG_VAL(DIO_u8_DDRB_REG, Copy_u8Direction);                           
                                break;
            case DIO_u8_PORTC:  
                                SET_REG_VAL(DIO_u8_DDRC_REG, Copy_u8Direction);                           
                                break;
            case DIO_u8_PORTD: 
                                SET_REG_VAL(DIO_u8_DDRD_REG, Copy_u8Direction);                           
                                break;
        }
    }
    else
    {
        
    }  
   
}

/**
 * DIO_voidGetPortValue - Get the value of a specific port.
 *
 * @param Copy_u8PortId: An 8-bit unsigned integer representing the port identifier.
 * @return An 8-bit unsigned integer representing the value of the specified port.
 */
u8 DIO_voidGetPortValue(u8 Copy_u8PortId)
{
    u8 Local_u8PinValue = 5;
    
    if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PortId >= DIO_u8_PORTA))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  Local_u8PinValue = GET_REG_VAL(DIO_u8_PINA_REG);  break;   
            case DIO_u8_PORTB:  Local_u8PinValue = GET_REG_VAL(DIO_u8_PINB_REG);  break;
            case DIO_u8_PORTC:  Local_u8PinValue = GET_REG_VAL(DIO_u8_PINC_REG);  break;
            case DIO_u8_PORTD:  Local_u8PinValue = GET_REG_VAL(DIO_u8_PIND_REG);  break;
        }
    }
    else
    {
        
    }
    return Local_u8PinValue; 
}