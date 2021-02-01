/*
 * sys_main.c
 *
 * The purpose of this file is to... 
 *      a) Figure out which charging state we are in (ON/OFF)
 *      b) to call on the function that sends the message to the charger. So we are actually sending the message to the charger via this.
 * 
 * Created on: Jan 31, 2021
 * Author: Elena Soboleva
 */

#include <stdio.h>
#include "charger_main.c"            //This has the functions that actually set the values that we send to the charger, when we want to send those values, and stores the incoming information from CAN based on pointers.
#include "charger_main.h"
#include "VCU_reading_of_GPIO_pin.c" //These GPIO files will be the one Gabe has that defines and reads this GPIO in. Replace them with the actual file names.
#include "VCU_reading_of_GPIO_pin.h"
#include "phantom_can.c"             //This has the main function where we put together the strucutred message to send to charger.
#include "phantom_can.h"

//while(1) means an infinite loop
while(1){ 
    // 1 means the interlock is in, therefore, we are in charging state.
    if(GPIO_pin_17 == 1){   //Replace GPIO_pin_17 with the actual GPIO pin name
        sendChargerMsg1(incoming_data[2] = 0);  //From phantom_can.c. This is BYTE 5 control. 0 means turn ON charger. 256 means turn OFF charger.
        delayms(1500);
    }
    else{
        incoming_data[2] = 256
    }
}