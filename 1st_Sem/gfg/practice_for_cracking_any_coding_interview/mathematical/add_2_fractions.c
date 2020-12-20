#include<stdio.h>
#include<math.h>

int main(){
    int n1, n2, d1, d2;
    scanf("%d %d %d %d", &n1, &d1, &n2 ,&d2 );
    int sum_n = n1+n2;
    int d1_len = floor(log10(d1))+1;
    int d2_len = floor(log10(d2))+1;
    if(d1_len > d2_len){
        d2 = d2*pow(10, (d1_len-d2_len));
    } else if(d2_len > d1_len)
        d1 = d1*pow(10, (d2_len-d1_len));
    int sum_d = d1 + d2;
    if(sum_d > 999){
        sum_d -= 1000;
        sum_n += 1;    
    }
    printf("%d/%d\n", sum_n , sum_d);
}
