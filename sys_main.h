#include <stdio.h>
#include "charger_main.c"            //This has the functions that actually set the values that we send to the charger, when we want to send those values, and stores the incoming information from CAN based on pointers.
#include "charger_main.h"
#include "VCU_reading_of_GPIO_pin.c" //These GPIO files will be the one Gabe has that defines and reads this GPIO in. Replace them with the actual file names.
#include "VCU_reading_of_GPIO_pin.h"
#include "phantom_can.c"             //This has the main function where we put together the strucutred message to send to charger.
#include "phantom_can.h"

int GPIO_pin_17;
int incoming_data[2];

void sendChargerMsg1();