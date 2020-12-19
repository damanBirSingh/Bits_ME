#include<stdio.h>
#include<math.h>

int main(){
    int n, temp, sum, sum_digits;
    scanf("%d", &n);
    temp=n; sum=0; sum_digits=0;
    while(temp>0){
        sum_digits++;
        sum  = sum + (temp%n);
        temp = temp/10;
    }
    int sum_reverse=0;
    temp = sum;
    for(int i=sum_digits; i>0; i--){
        sum_reverse += (temp%10)*pow(10, i);
        temp /= 10;
    }
    if(sum == sum_reverse)
        printf("1");
    else
        printf("0");
    return 0;
}
