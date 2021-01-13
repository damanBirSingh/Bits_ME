#include<stdio.h>
#include<math.h>

// brute force approach would be to divisibilty by every number smaller than n 
// This can be made a little efficient looking at: n = a*b. For a & b to be max : a=b=root(n). This means  that a & b together can't be bigger than sqrt(n),
// If n is not divisible any number below sqrt(n), it won't be divisible by any above sqrt(n) as those will be either prime or multiple of the smaller we already tested.
// other impementation can be using the obervation that every prime is of form 6k+1 or 6k-1; made another program.

int isPrime(int);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", isPrime(n));
    return 0;
}

int isPrime(int n){
    int isPrimeNum = 1;
    if(n==1)
        return 0;
    if(n<=3)
        return 1;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            isPrimeNum = 0;
            break;
        }
    }
    return isPrimeNum;
}
