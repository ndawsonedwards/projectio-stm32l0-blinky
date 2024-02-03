#include "hardware-pin.h"
#include "pin-description.h"


/**
 * @brief Returns the port and pin nubmer from the enumerated pin
 * 
 * @param pin enumerated pin
 * @param port port value of the enumerated pin
 * @param pinNumber pin value of the enumerated pin
 * @return Error
 */
Error GpioPin_GetPinContext(GpioPin pin, GPIO_TypeDef ** port, uint16_t * pinNumber ) {

    switch(pin) {
        case GpioPin_Led:
            *pinNumber = LD3_Pin;
            *port = LD3_GPIO_Port;
            return ErrorNone;

        default:
            return ErrorNotSupported;
    }

    return ErrorNone;
}

