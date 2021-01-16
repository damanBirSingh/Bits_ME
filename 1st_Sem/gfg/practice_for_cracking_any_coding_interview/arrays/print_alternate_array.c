#include<stdio.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    *arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    for(int i=0; i<n; i=i+2)
        printf("%d ", *(arr+i));
    printf("\n");
    return 0;
}
