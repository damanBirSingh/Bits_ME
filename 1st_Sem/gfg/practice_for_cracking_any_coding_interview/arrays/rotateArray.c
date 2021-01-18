#include<stdio.h>
#include<stdlib.h>

int main(){
    int t, n, d, *arr;
    scanf("%d", &t);
    while(t-->0){
        scanf("%d %d", &n, &d);
        int *arr = (int *)malloc(sizeof(int)*n);
        for(int i=0; i<n; i++)
            scanf("%d", arr+i);
        int start = d;
        int i = 0;
        while(i<n){
            printf("%d ", *(arr+start));
            start = (start+1)%n;
            i++;
        }
        printf("\n");
    }

}
