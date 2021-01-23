#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    scanf("%d %d", &x, &y);
    int first_x=0, first_y=0; //first occurence index for x & y
    int min_x=n+1, min_y=n+1; //min starting from x & min starting from y
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            first_x = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]==y){
            first_y=i;
            break;
        }
    }        
    for(int i=first_x+1; i<n; i++){
        if(arr[i]==x)
            first_x = i;
        else if(arr[i]==y && i-first_x<min_x)
            min_x = i-first_x;

    }
    for(int i=first_y+1; i<n; i++){
        if(arr[i]==y)
            first_y=i;
        else if(arr[i]==x && i-first_y<min_y)
            min_y = i-first_y;
    }
    printf("%d\n", min_x<min_y?min_x:min_y);
    return 0;
}
