#include<stdio.h>
#include<stdlib.h>

int main(){
    int t, *x;
    scanf("%d", &t);
    x = malloc(sizeof(int) * t);
    for(int i=0; i<t; i++)
        scanf("%d", x+i);
    for(int i=0; i<t; i++){
        printf("%d\n", *(x+i));
    }
    free(x);
}
