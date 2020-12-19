#include<stdio.h>

unsigned long long int fact(int);

int main(){
    int n; 
    scanf("%d", &n);
    printf("%llu\n", fact(n));
}

unsigned long long int fact(int n){
    unsigned long long int f=1;
    if(n == 1)
        return 1;
    f=n*fact(n-1);
    return f;
}
