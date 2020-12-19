#include<stdio.h>
#include<math.h>
// prints the kth digit from the right of a^b

int main(){
    int a, b, k, kth_digit;
    scanf("%d %d %d", &a, &b, &k);
    int a_pow_b = pow(a, b);
    int i=1;
    while(i<=k){
        kth_digit = a_pow_b%10;
        a_pow_b /= 10;
        i++;
    }
    printf("%d\n", kth_digit);
    return 0;
}
