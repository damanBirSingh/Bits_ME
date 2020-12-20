#include<stdio.h>
#include<stdlib.h>

int find_gcd(int, int);

int main(){
    int n, *arr;
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int gcd = *arr;
    for(int i=1; i<n; i++){
        gcd = find_gcd(gcd, *(arr+i));
    }
    printf("%d\n", gcd);
    free(arr);
    return 0;
}

int find_gcd(int a, int b){
    if(a == 0)
        return b;
    if(b>a)
        return find_gcd(b%a, a);
    else
        return find_gcd(a%b, b);
}
