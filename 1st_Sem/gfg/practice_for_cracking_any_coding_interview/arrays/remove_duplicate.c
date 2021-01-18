#include<stdio.h>
#include<stdlib.h>

void spliceArray(int *, int, int, int);
void printArray(int *, int);

int main(){
    int n, *arr; 
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int startIndex, endIndex, i=0;
    while(i<n){
        startIndex = i;
        endIndex = i;
        int numStart = *(arr+i);
        for(int ii=i+1; ii<n; ii++){
            if(*(arr+ii) != *(arr+startIndex))
                break;
            endIndex=ii;
        }
        i++;
        if(startIndex == endIndex)
            continue;
        spliceArray(arr, startIndex, endIndex, n);
        n=n-(endIndex-startIndex);
    }
    printArray(arr, n);
    free(arr);
    return 0;
}

void spliceArray(int *arr, int startIndex, int endIndex, int arr_len){
    int elemToShift = arr_len-endIndex;;
    for(int i=0; i<elemToShift-1; i++){
        arr[i+startIndex+1] = arr[i+endIndex+1];        
    }
}

void printArray(int *arr, int arr_len){
    printf("Unique elements in the array: ");
    for(int i=0; i<arr_len; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}
