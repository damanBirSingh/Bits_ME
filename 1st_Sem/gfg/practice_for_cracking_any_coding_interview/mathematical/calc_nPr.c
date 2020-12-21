#include<stdio.h>

int factorial(int);

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", factorial(n)/factorial(n-r));
}

int factorial(int x){
    if(x == 1)
        return 1;
    return x*factorial(x-1);
}
