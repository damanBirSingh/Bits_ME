#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int mod = n%m;
    float temp = m/2;
    if(mod>temp){
        printf("%d\n",n+(m-mod));
    } else if(abs(mod) == temp){
        printf("%d\n",n+mod);
    } else{
        printf("%d\n",n-mod);
    }
}
