#include<stdio.h>

void print_n_x_times(int, int);

int main(){
    int n;
    scanf("%d", &n);
    int t = n;
    for(int i=10; i>0; i--){   
        while(t>0){
            print_n_x_times(t, i);
            t--;
        }
        printf("\n");
        t=n;
    }
}

void print_n_x_times(int n, int x){
    while(x>0){
        printf("%d ", n);
        x--;
    }
}
