/*
 * charger_main.c
 *
 * The purpose of this file is to... 
 *      a) Set the values at which we want to charge (maxVoltage, maxCurrent)
 *      b) Define when we send the message
 *      c) Read and store the incoming values over CAN via pointers (output current, output voltage, any faults)
 * 
 * Created on: Jan 31, 2021
 * Author: Elena Soboleva
 */

#include <stdio.h>
#include "sys_main.c"
#include "sys_main.h"
#include "phantom_can.c"
#include "phantom_can.h"

void function_to_charge(){
    int maxVoltage = 3.3;    //in Volts
    int maxCurrent = 10.5;   //in Amps
    int minCurrent = 0.1;    //This is out cut off current. So when the current output falls below or hits that value, we stop charging.
    int outputCurrent = checkChargerCurrent();

    while(outputCurrent > minCurrent){
        sendChargerMsg1(maxVoltage, maxCurrent);
        delay(1);            //This is how often we send this message. Every 1 second.
    }

    //This is to write the data we have to a CSV file.
    int write_data_to_file(struct MyData *data, char const *fileName) 
    { 
        FILE *f = fopen(fileName, "w"); 
        if (f == NULL) return -1; 
        while (1) { 
        // you might want to check for out-of-disk-space here, too 
            fprintf(f, "%d,%s,%f\n", max, data->someString, data->someSample); 
            ++data; 
        } 
        fclose(f); 
    return 0; 
    } 
}
