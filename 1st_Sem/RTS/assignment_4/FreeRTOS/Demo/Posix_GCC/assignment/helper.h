#ifndef HELPER_H
#define HELPER_H

#include "FreeRTOS.h"

/* constants for the random reading limits.*/
#define TEMP_UPPER_LIMIT 100
#define TEMP_LOWER_LIMIT 20
#define PRESSURE_UPPER_LIMIT 10
#define PRESSURE_LOWER_LIMIT 1
#define HEIGHT_UPPER_LIMIT 100
#define HEIGHT_LOWER_LIMIT 0


/* Constants to configure Periodic Tasks*/
#define TASK_TEMPERATURE 0
#define TASK_PRESSURE 1
#define TASK_HEIGHT 2

#define NUM_TASKS 3

// periods in ms
#define PERIOD_TEMP_TASK 2
#define PERIOD_PRESSURE_TASK 3
#define PERIOD_HEIGHT_TASK 4

// Default Priority, will not matter when using EDF Scheduler
#define PRIORITY_TEMP_TASK (tskIDLE_PRIORITY) 
#define PRIORITY_PRESSURE_TASK (tskIDLE_PRIORITY+1)
#define PRIORITY_HEIGHT_TASK (tskIDLE_PRIORITY+2)

// To give a custom frame size for EDF scheduler task set it here, else gcd will be used if this is 0
#define SCHEDULER_FRAME_SIZE 0

// default 1, to use default scheduler set as 0
#define EDF_SCHEDULER 1

int getTemperature();

int getPressure();

int getHeight();

int getPeriod(int);

int getGcd(int, int);

#endif 

