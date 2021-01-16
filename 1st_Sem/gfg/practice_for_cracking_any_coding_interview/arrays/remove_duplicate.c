#include<stdio.h>

int main(){
    int n, *arr; 
    scanf("%d", &n);
    *arr = (int *)malloc(sizeof(int)*n);
    int *arr = malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    for(int i=1; i<n; i++){
        if()
    }
    return 0;
}
