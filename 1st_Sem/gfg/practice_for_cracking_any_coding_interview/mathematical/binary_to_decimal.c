#include<stdio.h>
#include<math.h>

int main(){
    int binary, decimal;
    scanf("%d", &binary);
    decimal = 0;
    int i = 0;
    while(binary>0){
        decimal += (binary%10)*pow(2,i);
        binary /= 10;
        i++;
    }
    printf("%d\n", decimal);
    return 0;
}
