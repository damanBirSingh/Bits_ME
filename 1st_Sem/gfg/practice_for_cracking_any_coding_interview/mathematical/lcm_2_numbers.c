#include<stdio.h>

// brute force method can be to find the union of all the common prime factors of both numbers
// OR we can use the formula, a*b = lcm(a,b)*gcd(a,b) && we can find the gcd using euclidean algo.
// Important: The above formula is ony valid for two numbers. For more than two numbers do it pair wise as the formula still holds for a pair of numbers.

int gcd(int, int);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int lcm = (a*b)/gcd(a,b);
    printf("%d\n", lcm);

}

int gcd(int a, int b){
    if(a == 0)
        return b;
    if(b>a)
        return gcd(b%a, a);
    else 
        return gcd(a%a, b);
}
