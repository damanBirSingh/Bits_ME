#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int leader=arr[n-1];
    printf("%d ", leader);
    for(int i=n-2; i>=0; i--){
        if(arr[i] > leader){
            leader = arr[i];
            printf("%d ", leader);
        }
    }
    printf("\n");
}
