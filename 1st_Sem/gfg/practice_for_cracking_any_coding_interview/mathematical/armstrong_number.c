#include<stdio.h>
#include<math.h>
#define D 3

int main(){
    int n, cube_sum;
    scanf("%d", &n);
    int num[D],i , temp; //one's ten's & hundreth's place  number
    temp = n;
    i = 0;
    while(temp>0){
        num[i] = temp%10;
        temp = temp/10;
        i++;
    }
    cube_sum = 0;
    for(int j=0; j<D; j++){
        cube_sum = cube_sum + pow(num[j], 3); 
    }
    if(n==cube_sum)
        printf("%d is an armstrong number\n", n);
    else 
        printf("%d is not an armstrong number\n", n);
}
