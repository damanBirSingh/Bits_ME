#include<stdbool.h>
#include<stdio.h>
typedef unsigned long long int ull;

// time complexity : O(n*root(n))

bool isPrime(int);

int main(){
    ull n, sum = 0;
    scanf("%llu", &n);
    for(ull i=2; i<=n; i++){
        if(isPrime(i)){
            sum += i;
            printf("%llu ", i);}
    }
    printf("\n%llu\n", sum);
}

bool isPrime(int n){
    if(n == 1)
        return false;
    if(n <= 3)
        return true;
    for(ull i = 2; i*i<=n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
