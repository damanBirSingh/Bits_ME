#include<stdio.h>
#include<math.h>

int main(){
    int a, r, n;
    printf("a= ");
    scanf("%d", &a);
    printf("r= ");
    scanf("%d", &r);
    printf("n= ");
    scanf("%d", &n);
    unsigned long long int nth_term = a;
    for(int i=0; i<n-1; i++)
        nth_term = nth_term*r;
    printf("%d\n", nth_term%1000000007);
}
