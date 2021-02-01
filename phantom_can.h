#include "phantom_can.h"
#include "can.h"
#include "stdlib.h"
#include "sys_main.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_main.c" 

uint16 outgoing_data[4];
int maxVoltage;
int maxCurrent;
uint16 outgoing_data_ptr;
uint16 incoming_data[4];
int outputVoltage;
int outputCurrent;
int outputState;
uint16 incoming_data_ptr;

void sendChargerMsg1();
void canTransmit();
void receiveChargerMsg2();
void canReceive();
