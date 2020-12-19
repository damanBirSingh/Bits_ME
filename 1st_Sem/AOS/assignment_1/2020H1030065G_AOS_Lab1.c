/* To Compile c code using pthread library use -pthread option with gcc */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *row_worker_thread(void *);
void swap(int *, int *);
float get_median(int *, int );
void print_output(int num_rows);

struct thread_data{
   int *row_arr;
   int  size;
   float median;
};
struct thread_data *thread_data_array; // array of thread_data structs, Global

int main(int argc, char *argv[]){
    char *fileName = argv[1];
    FILE *fpointer;

    fpointer = fopen(fileName, "r");
    printf("%s ", fileName);
    if(fpointer == NULL ){
        printf("File not found/Cannot be opened/n");
        exit(0);
    }

    int row, col;
    fscanf(fpointer,"%d", &row); //read num of rows
    fscanf(fpointer, "%d", &col); //read num of columns
    thread_data_array = (struct thread_data *)malloc(row * sizeof(struct thread_data)); // one of each matrix row

    pthread_t *thread_id = malloc(row*sizeof(pthread_t)); // num of threads = num of rows

    for(int i=0; i< row; i++){
        thread_data_array[i].size = col;
        thread_data_array[i].row_arr = (int *)malloc(col * sizeof(int)); //each row will have col num of integers

        for(int j=0; j<col; j++)
            fscanf(fpointer, "%d", &thread_data_array[i].row_arr[j]); //read columns of row i

        
        pthread_create(&thread_id[i], NULL, row_worker_thread, &thread_data_array[i]); //call worker thread for every row
    }

    for(int i=0; i< row; i++) //wait for all threads to complete
        pthread_join(thread_id[i], NULL);   
    
    print_output(row);
    fclose(fpointer);
    free(fpointer);
    free(fileName);
    free(thread_data_array);
    free(thread_id);
    return 0;
}

void *row_worker_thread(void *thread_args){
    struct thread_data *data = (struct thread_data *)thread_args;
    int size = data->size;
    int *row_arr = data->row_arr;
    int  min;
    for (int i=0; i<size ; i++) {  //sort the row using selection sort
        min = i;
        for (int j=i+1; j<size; j++){
          if (row_arr[j] < row_arr[min])
            min = j;
        }
        swap(&row_arr[min], &row_arr[i]);
    }
    data->median = get_median(row_arr, size);
}

void swap(int *x, int *y){ //helper fn for sorting
    int temp = *x;
    *x = *y;
    *y = temp;
}

float get_median(int *sorted_row, int size){
    float median = 0;
    if(size%2==0){
        median = ((float)sorted_row[size/2 - 1] + (float)sorted_row[size/2])/2;
    } else{
        median = sorted_row[(size+1)/2 - 1] ;
    }
    return median;
}

void print_output(int row){
    printf("Row sorted matrix\n");
    for(int i=0; i< row; i++){
        int col = thread_data_array[i].size;
        for(int j=0; j<col; j++)
            printf("%d ", thread_data_array[i].row_arr[j]);
        printf("\n");
    }
    printf("\nMedian array\n");
    for(int i=0; i<row; i++)
        printf("%.1f ", thread_data_array[i].median);
    printf("\n");
}
