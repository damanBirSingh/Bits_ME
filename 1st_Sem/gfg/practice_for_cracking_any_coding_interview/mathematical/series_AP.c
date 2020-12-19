// finds the nth term of an AP with first two elements being A1 & A2 
#include<stdio.h>

int main(){
    int a1, a2, n;
    printf("A1 = ");
    scanf("%d", &a1);
    printf("A2 = ");
    scanf("%d", &a2);
    printf("N = ");
    scanf("%d", &n);
    int diff = a2-a1;
    int nth_term = a1 + ((n-1)*diff);
    printf("%d\n",nth_term);
}
