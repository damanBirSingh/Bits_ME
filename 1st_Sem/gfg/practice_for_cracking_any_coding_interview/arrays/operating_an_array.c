#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

bool searchElement(int *, int, int);
//Used pointer to pointer because in C arguments are passed by value, so i cannot assign a different location to the pointer in the function.
bool insertElement(int **, int, int, int);
bool deleteElement(int **, int, int);
void printArray(int *, int);

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(sizeof(int)*n);
        int op_ints[4];
        for(int ii=0; ii<n; ii++)
            scanf("%d", (arr+ii));
        for(int ii=0; ii<4; ii++)
            scanf("%d", (op_ints+ii));
        printArray(arr, n);
        searchElement(arr, op_ints[0], n);
        insertElement(&arr, op_ints[1], op_ints[2], n);
        deleteElement(&arr, op_ints[3], n+1);
    }
}

bool searchElement(int *arr, int n, int arr_len){
    bool found = false;
    for(int i=0; i<arr_len; i++){
        if( *(arr+i) == n)
            found = true;
    }
    return found;
}

bool insertElement(int **arr, int num, int insertIndex, int arr_len){
    bool inserted = false;
    int *arr_new = (int *)malloc(sizeof(int)*(arr_len+1));

    for(int i=0; i<insertIndex ; i++)
        *(arr_new+i) = *(*arr+i);
    arr_new[insertIndex] = num;
    int remainingElements = arr_len-insertIndex; 
    for(int i=0; i<remainingElements; i++)
        *(arr_new + i+insertIndex+1) = *(*arr + i+insertIndex);
    inserted = true;
    int *temp;
    temp = *arr;
    *arr = arr_new;
    printArray(*arr, arr_len+1);
    return inserted;
}

bool deleteElement(int **arr, int num, int arr_len){
    bool deleted = false;
    int deleteIndex = -1;
    for(int i=0; i<arr_len; i++){
        printf("%d ", *(*arr+i));
        if(*(*arr+i) == num){
            deleteIndex = i;
            break;
        }
    }
    if(deleteIndex == -1)
        return true;
    else{
        int *arr_new = (int *)malloc(sizeof(int)*(arr_len-1));
        for(int i=0; i<deleteIndex; i++)
            *(arr_new+i) = *(*arr+i);
        int remainingElements = arr_len-deleteIndex-1;
        for(int i=0; i<remainingElements; i++)
            *(arr_new+ (i+deleteIndex)) = *(*arr+ (i+deleteIndex+1));
        deleted = true;
        free(*arr);
        *arr = arr_new;
    }
    printArray(*arr, arr_len-1);
    return deleted;
}

void printArray(int *arr, int arr_len){
    printf("Present Array: ");
    for(int i=0; i<arr_len; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}
