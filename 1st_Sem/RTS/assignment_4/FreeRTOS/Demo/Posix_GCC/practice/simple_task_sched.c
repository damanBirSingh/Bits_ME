#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t task_1_handler=NULL;
TaskHandle_t task_2_handler=NULL;

char *name_task_1 = "Task_1";
char *name_task_2 = "Task_2";


// In 1ms there are 1000/7=142.857 ticks 
void myTask_1(void *p){
    UBaseType_t priority;
    TickType_t ticks;
    while(1){
        priority=uxTaskPriorityGet(NULL);
        ticks = xTaskGetTickCount();
        printf("Hello world from %s and my priority is %ldi and tick number is %d\n", (char *)p, priority, ticks);
        fflush(stdout);
        vTaskPrioritySet(task_1_handler, tskIDLE_PRIORITY);
        vTaskPrioritySet(task_2_handler, tskIDLE_PRIORITY+1);
        vTaskDelay(142/portTICK_PERIOD_MS);
    }
}

void myTask_2(void *p){
    UBaseType_t priority;
    TickType_t ticks;
    while(1){
        priority=uxTaskPriorityGet(NULL);
        ticks = xTaskGetTickCount();
        printf("Hello world from %s and my priority is %ld and the tick number is %d\n", (char *)p, priority, ticks);
        fflush(stdout);
        vTaskPrioritySet(task_1_handler, tskIDLE_PRIORITY+1);
        vTaskPrioritySet(task_2_handler, tskIDLE_PRIORITY);
        vTaskDelay(284/portTICK_PERIOD_MS);
    }
}


void simple_task_sched( void )
{
    xTaskCreate(myTask_1, "T1", 200, (void *)name_task_1, tskIDLE_PRIORITY, &task_1_handler);
    xTaskCreate(myTask_2, "T2", 200, (void *)name_task_2, tskIDLE_PRIORITY+1, &task_2_handler);
    vTaskStartScheduler();
    while(1);
}

