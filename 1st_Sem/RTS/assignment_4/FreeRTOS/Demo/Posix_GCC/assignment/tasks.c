// Standard libraries
#include <stdio.h>
#include <stdlib.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

//custom header
#include "helper.h"

void vScheduleEDF(TaskHandle_t *, int *);

void vTask_0(void *p){ //temperature task
    int temp; 
    TickType_t curr_tick_number;

    while(1){
        temp = getTemperature();
        curr_tick_number = xTaskGetTickCount();

        printf("Temperature: %d, current tick number: %d\n", temp, curr_tick_number);

        vTaskDelay(PERIOD_TEMP_TASK/portTICK_PERIOD_MS); // PERIOD_TEMP_TASK is in ms and dividing by portTICK_PERIOD_MS gives number of ticks for that period
    }
}

void vTask_1(void *p){ //pressure task 
    int pressure;
    TickType_t curr_tick_number;

    while(1){
        curr_tick_number = xTaskGetTickCount();
        pressure= getPressure();

        printf("Pressure: %d, current tick number : %d\n", pressure, curr_tick_number);

        vTaskDelay(PERIOD_PRESSURE_TASK/portTICK_PERIOD_MS);
    }
}

void vTask_2(void *p){ //height_task
    int height;
    TickType_t curr_tick_number;

    while(1){
        curr_tick_number = xTaskGetTickCount();
        height= getHeight();

        printf("Height: %d, current tick number: %d\n", height, curr_tick_number);

        vTaskDelay(PERIOD_HEIGHT_TASK/portTICK_PERIOD_MS); 
    }
}


void vScheduleTasks(){
    TaskHandle_t *handlers = (TaskHandle_t *)malloc(NUM_TASKS*sizeof(TaskHandle_t));
    int *task_periods = malloc(3*sizeof(int));
    for(int i=0 ; i<NUM_TASKS; i++)
        *(task_periods+i) = getPeriod(i);

    //create tasks for Temp, Pressure and Height readings 
    xTaskCreate(vTask_0, "T0", 200, (void *)0, PRIORITY_TEMP_TASK, handlers);
    xTaskCreate(vTask_1, "T1", 200, (void *)0, PRIORITY_PRESSURE_TASK, handlers+1);
    xTaskCreate(vTask_2, "T2", 200, (void *)0, PRIORITY_HEIGHT_TASK, handlers+2);

    if(EDF_SCHEDULER == 1)
        vScheduleEDF(handlers, task_periods); 
    else 
        vTaskStartScheduler();
}
