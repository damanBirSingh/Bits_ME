#include<stdio.h>
// gcd(a,b) be gcd of a & b 
// a = x*gcd(a,b) & b = y*gcd(a,b)
// then a-b will be (x-y)*gcd(a,b); Thus gcd does not change. This is called Euclidean Algorithm.
// This can take a number of steps to calculate. it can be made efficient using modulo operator.

int gcd_subtraction(int, int);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd_subtraction(a, b));
}

int gcd_subtraction(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;
    if(b > a)
        return gcd_subtraction(b-a, a);
    else
        return gcd_subtraction(a-b, b);
}
