#include<stdio.h>

int main(){
    int n;
    unsigned long long int fact;
    scanf("%d", &n);
    fact=1;
    for(int i=n; i>0; i--){
        fact *= i;
    }
    printf("%llu\n", fact);
}
