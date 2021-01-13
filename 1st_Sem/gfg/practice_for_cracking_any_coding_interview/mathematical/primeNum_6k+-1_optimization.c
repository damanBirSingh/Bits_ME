#include<stdbool.h>
#include<stdio.h>

//All numbers can be expressed as 6k+i, where i = -1, 0, 1, 2, 3, 4. In these all 6k-1 and 6k+1 numbers are prime except 2 & 3
//All of form 6k+0, 6k+2, 6k+4 are divisible by 2, all of form 6k+3 are divisible by 3. So we need to filter these first

bool isPrime(int);

int main(){
    int n;
    scanf("%d", &n);
    if(isPrime(n))
        printf("Yes\n");
    else
        printf("No\n");
}

bool isPrime(int n){
    if(n==1)
        return false;
    if(n<=3) // is either 2 or 3
        return true;
    if(n%2 == 0 || n%3 == 0) // is either divisible by 2 or 3
        return false;
    for(int i=5; i*i<n; i=i+6){ //check if it is divisible by the remaining any other prime num smaller than root(n)
        if(n%i || n%(i+2)==0) // 6k-1 & 6k+1 divisibility
            return false;
    }
    return true; //remaining numbers must be prime 
}
