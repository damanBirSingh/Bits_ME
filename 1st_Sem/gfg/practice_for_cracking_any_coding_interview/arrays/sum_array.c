#include<stdio.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    *arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=*(arr+i);
    printf("%d\n", sum);
    return 0;
}
