// Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// FreeRTOS libraries
#include <FreeRTOS.h>

//custom header
#include "helper.h"

int generateRandomNumber(int upper, int lower){
    srand(time(0));
    return (rand() % (upper - lower + 1)) + lower; 
}

int getTemperature(){
    return generateRandomNumber(TEMP_UPPER_LIMIT, TEMP_LOWER_LIMIT);
}

int getPressure(){
    return generateRandomNumber(PRESSURE_UPPER_LIMIT, PRESSURE_LOWER_LIMIT);
}

int getHeight(){
    return generateRandomNumber(HEIGHT_UPPER_LIMIT, HEIGHT_LOWER_LIMIT);
}

int getPeriod(int task_num){
    switch(task_num){
        case TASK_TEMPERATURE: 
            return PERIOD_TEMP_TASK;
        case TASK_PRESSURE: 
            return PERIOD_PRESSURE_TASK;
        case TASK_HEIGHT:
            return PERIOD_HEIGHT_TASK;
    }
}

int getGcd(int x, int y){
    if(y == 0){
        return x;
    }
    return getGcd(y, x%y);
}


