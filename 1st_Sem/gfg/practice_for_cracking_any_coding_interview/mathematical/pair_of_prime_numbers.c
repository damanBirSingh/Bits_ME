#include<stdio.h>
#include<stdlib.h>

int main(){
    int t, *n;
    scanf("%d", &t);
    n = malloc(sizeof(int)*t);
    for(int i=0; i<t; i++)
        scanf("%d", n+i);
    
    free(n);
    return 0;
}
