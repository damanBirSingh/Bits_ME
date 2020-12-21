#include<stdio.h>

int factorial(int);

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    if(r > n)
        printf("0\n"); return 0;
    printf("%d\n", factorial(n)/(factorial(r)*factorial(n-r)));
    return 0;
}

int factorial(int x){
    if(x == 1)
        return 1;
    return x*factorial(x-1);
}
