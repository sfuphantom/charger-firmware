#include <stdio.h>
#include "sys_main.c"
#include "sys_main.h"
#include "phantom_can.c"
#include "phantom_can.h"

int maxVoltage;
int maxCurrent;
int minCurrent;
int outputCurrent;

void function_to_charge();
void sendChargerMsg1();
void write_data_to_file();