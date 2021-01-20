# charger-firmware

This is the code to send messages to the charger so that we can charger our battery stack.

The sys_main.c file contains the code that needs to be append to our primary sys_main.c file for phantom. This is so that the charger code is called upon when needed.

The can_main.c file also needs to be appended to the primary can_main.c file for phantom. This code will send structured messages to the charger.

The charger.c file has all the functions needed to carry out the charging process. This will SET values, send messages, and receive messages.

Messages we are sending to the charger:
1. Enable charging
2. Voltage & Current we want to charge at.

Messages we are receiving from the charger:
1. Any faults
2. The output voltage and current from the charger.
