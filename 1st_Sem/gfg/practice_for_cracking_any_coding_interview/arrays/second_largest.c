#include<stdio.h>
#include<limits.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    *arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int first_larg, sec_larg;
    first_larg = INT_MIN;
    for(int i=0; i<n ; i++ ){
        if(*(arr+i)> first_larg){
            sec_larg = first_larg;
            first_larg = *(arr+i);
        }
    }
    printf("%d\n", sec_larg);
    return 0;
}
