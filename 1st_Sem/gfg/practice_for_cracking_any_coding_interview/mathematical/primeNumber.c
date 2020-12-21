#include<stdio.h>
#include<math.h>

int isPrime(int);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", isPrime(n));
    return 0;
}

int isPrime(int n){
    int root_n = sqrt(n)+1;
    int isPrimeNum = 1;
    for(int i=2; i<=root_n; i++){
        if(n%i == 0){
            isPrimeNum = 0;
            break;
        }
    }
    return isPrimeNum;
}
