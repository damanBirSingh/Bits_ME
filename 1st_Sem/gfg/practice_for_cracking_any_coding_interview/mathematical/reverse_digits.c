#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int n, temp, reverse, n_len;
    scanf("%d", &n);
    temp=n; reverse= 0;
    n_len = floor(log10(abs(n))) + 1;
    while(temp>0){
        reverse += (temp%10)*pow(10, n_len-1);
        temp /= 10;
        n_len--;
    }
    printf("%d\n", reverse);
    return 0;
}
