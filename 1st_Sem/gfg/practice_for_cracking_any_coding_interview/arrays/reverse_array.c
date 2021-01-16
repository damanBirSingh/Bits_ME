#include<stdio.h>

int main(){
    int t, n, *arr;
    scanf("%d", &t);
    *arr = (int *)malloc(sizeof(int)*n);
    while(t-->0){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", arr+i);
        for(int i=n-1; i>=0; i--)
            printf("%d ", *(arr+i));
        printf("\n");
    }
    return 0;
}
