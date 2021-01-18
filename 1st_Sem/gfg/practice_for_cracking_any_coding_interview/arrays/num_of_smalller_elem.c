#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr, x;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    scanf("%d", &x);
    int smaller_nums = 0;
    for(int i=0; i<n; i++)
        if(arr[i]<=x)
            smaller_nums++;
        else
            break;
    printf("%d\n", smaller_nums);
}
