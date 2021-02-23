#include<stdio.h>

int gcd_subtraction(int, int);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    //if(a > b)
       // printf("%d\n", gcd_subtraction(b, a)); No need for this check coz if b<a then it recursive function will correct it in the first recursive call
    //else 
        printf("%d\n", gcd_subtraction(a, b));
}

int gcd_subtraction(int a, int b){
    if(a == 0)
        return b ;
    return gcd_subtraction(b%a, a);
}