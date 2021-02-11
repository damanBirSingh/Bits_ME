// Standard libraries
#include <stdio.h>
#include <stdlib.h>

//custom header
#include "helper.h"
#include "task.h"

struct edf_task_data{
    TaskHandle_t *handlers;
    TickType_t frame_size;
};

TaskHandle_t sched_handler=NULL;

int getEdfPriorityOfTask(UBaseType_t *arr, int arr_len, int task_number){
    // find at what the position of the abs_deadline will be if the abs_deadline arr was sorted
    int smaller_elements = 0;
    for(int i=0; i<arr_len; i++){
        if( (*(arr+i) < *(arr+task_number)) ||  (*(arr+i)==*(arr+task_number) && i<task_number) )
            smaller_elements++;
    }
    return NUM_TASKS-smaller_elements-1;
}

int getFrameSize(int *periods){ 
    int frame_size;
    if( SCHEDULER_FRAME_SIZE <= 0){
        frame_size = *(periods+0);
        for(int i=1; i<NUM_TASKS; i++)
            frame_size = getGcd(frame_size, *(periods+i));
    }
    else 
        frame_size = SCHEDULER_FRAME_SIZE;
    //printf("Frame Size calculated as %d\n",frame_size);
    return frame_size;
}

TickType_t getAbsoluteDeadlineInTicks(TickType_t  current_tick, TickType_t period_in_ticks){
    return (TickType_t)((current_tick/period_in_ticks)*period_in_ticks + period_in_ticks);
}

void vEdfSchedulerTask(void *p){  
    TickType_t curr_tick_number;
    TickType_t *abs_deadlines = (UBaseType_t *)malloc(sizeof(TickType_t) * NUM_TASKS);
    struct edf_task_data *task_data = p;
    
    while(1){
        curr_tick_number = xTaskGetTickCount();
        printf("\n\nScheduler task called on tick: %d\n",curr_tick_number);
        
        for(int i = 0; i< NUM_TASKS; i++)
            *(abs_deadlines+i) = getAbsoluteDeadlineInTicks(curr_tick_number, ((TickType_t)getPeriod(i))/portTICK_PERIOD_MS);
    
        //printf("Absolute Deadlines, T1: %d,  T2: %d,  T3: %d\n", *(abs_deadlines), *(abs_deadlines+1), *(abs_deadlines+2));
 
        int earliest_deadline_task_index = 0;
        TickType_t earliest_deadline = 0;
        int max_available_priority = NUM_TASKS;

        for(int i=0; i<NUM_TASKS; i++){
            int priority_i = getEdfPriorityOfTask(abs_deadlines, NUM_TASKS, i);
            printf("Task: %d Priority: %d\n", i+1, priority_i);
            vTaskPrioritySet(task_data->handlers[i], priority_i); 
        }
        
        vTaskDelay(task_data->frame_size/portTICK_PERIOD_MS); 
    }   
}

void vScheduleEDF(TaskHandle_t *handlers, int *task_periods){
    struct edf_task_data *task_data = malloc(sizeof(struct edf_task_data*));    
    task_data->handlers = handlers;
    task_data->frame_size = getFrameSize(task_periods);
    
    xTaskCreate(vEdfSchedulerTask, "SCHED", 200, (void *)task_data, (configMAX_PRIORITIES-1), &sched_handler); //Scheduler Task with max Priority
    vTaskStartScheduler();
    while(1);
}