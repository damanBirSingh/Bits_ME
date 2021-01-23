#include<stdio.h>
#include<stdlib.h>

void brute_force(int *, int);
void optimized(int *, int);

int main(){
    int n, *arr;
    scanf("%d", &n);
    arr=(int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    return 0;
}

void brute_force(int *arr, int arr_len){
    int a, b, c;
    for(int i=0; i<arr_len-2; i++){
        a=*(arr+i);
        b=0; c=0;
        for(int ii=i+1; ii<arr_len-1; ii++){
            if(*(arr+ii)<=a)
                continue;
            else
                b=*(arr+ii);
            for(int iii=ii+1; iii<arr_len; iii++){
                printf("i: %d, ii: %d, iii: %d\n", i, ii, iii);
                if(*(arr+iii)<=a || *(arr+iii)<=b)
                    continue;
                else{
                    c=*(arr+iii);
                    printf("\na: %d, b: %d, c: %d\n\n", a, b, c);
                }
            }
        }
    }
}

// we find the elements with smaller elements to the left, the elements with bigger elements to the right
// The common elements in the above arrays is our result., Just gives us the number of subsequences possible, not the subsequences themselves.
// Time complexity: O(n)
void optimized(int *arr, int arr_len){
    int *left_smaller, *right_bigger;
    left_smaller=(int *)malloc(sizeof(int)*(arr_len-1));
    right_bigger=(int *)malloc(sizeof(int)*(arr_len-1));
    int min=arr[0], max=arr[arr_len-1], left_i=0, right_i=0;
    for(int i=1; i<arr_len; i++){
         if(arr[i]<min)
             min=arr[i];
         else if(arr[i]>min)
             left_smaller[left_i++]=arr[i];
    }
    for(int i=arrlen-2; i>=0; i--){
         if(arr[i]>max)
             max=arr[i];
         else if(arr[i]<max)
             right_bigger[right_i++]=arr[i];
    }
    int total_sequences=0;
    for

}
