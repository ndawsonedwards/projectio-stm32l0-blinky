#ifndef _ERRORS_H_
#define _ERRORS_H_

typedef enum
{

    ErrorNone = 0,

    ErrorBadParameter,

    ErrorBadState,

    ErrorIllegalPointer,

    ErrorTimeout,

    ErrorCrcFailure,
         
    ErrorInsufficientMemory,
         
    ErrorNotFound, 
         
    ErrorAlreadyExists,    
         
    ErrorResourceInUse,        
     
    ErrorNotSupported,      
    
    ErrorInvalidResponse,

    ErrorSystemApiFailed,
    
    ErrorCorruptionDetected,
    
    ErrorOperationCancelled,
    
    ErrorRequestFailed,

    ErrorDeviceNotPresentOrResponding,   
    
    ErrorNegativeAcknowledgement,

    ErrorBufferOverrun,   
    
    ErrorInvalidMeasurement,  

    ErrorInvalidFormat,      
    
    ErrorInvalidLength,        
       
    ErrorParity,
          
    ErrorFraming,        
           
    ErrorUnsupportedVersion,
         
    ErrorUnsupportedType,    
        
    ErrorHardwareFailure,      
          
    ErrorUnknownHost,      

    ErrorOutOfBounds,

    ErrorUnknown,

}Error;

#endif