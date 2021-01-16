#include<stdio.h>
#include<limits.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    *arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int min, max;
    min= INT_MAX;
    max= INT_MIN;
    for(int i=0; i< n; i++){
        if(*(arr+i) > max)
            max = *(arr+i);
        if(*(arr+i) < min)
            min = *(arr+i);
    }
    printf("min: %d & max : %d\n", min, max);
    return 0;
}
