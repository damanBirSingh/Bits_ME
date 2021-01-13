#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

// Sieve of eratothenes is one of the most efficient algo to find the prime numbers from 1 to n with time complexity of O(nlog(logn))

int main(){
    int n;
    bool *primes;
    scanf("%d", &n);
    primes = malloc(sizeof(bool)*(n));
    for(int i=0; i<n; i++)
        *(primes+i) = true; //initialise the primes bool array as true
    primes[0] = false;
    for(int i=1; i*i<=n; i++ ){  // first loop till sqrt(n) as till we reach sqrt(n) all above it that are composite would be marked as false.
        if(*(primes+i) == false) // if it is composite, skip
            continue;
        else{
            for(int j=i+(i+1); j<n; j+=(i+1)){ // mark every multiple of this prime number as composite.
                primes[j]=false;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(primes[i])
            printf("%d ",i+1);
    }
    puts("");
    free(primes);
}
