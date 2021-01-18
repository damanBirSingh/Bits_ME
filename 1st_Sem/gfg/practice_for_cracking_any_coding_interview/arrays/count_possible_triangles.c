#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int count_brute_force(int *, int);
int count_optimized(int *, int);
bool check_if_triangle(int, int, int);
int compare(const void *, const void *);

int main(){
    int n, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int count = count_optimized(arr, n); 
    printf("%d\n", count);
    return 0;
}

bool check_if_triangle(int a, int b, int c){
    bool is_triangle = false;
    if(a+b > c){
        if(b+c > a){
            if(c+a > b)
                is_triangle = true;
        }
    }
    return is_triangle;
}

// Time Complexity : O(n^3)
int count_brute_force(int *arr, int arr_len){
    int num_triangles = 0;
    for(int i=0; i<arr_len; i++){
        int side_1=arr[i];
        for(int ii=i+1; ii<arr_len; ii++){
            int side_2 = arr[ii];
            for(int iii=ii+1; iii<arr_len; iii++){
                int side_3 = arr[iii];
                if(check_if_triangle(side_1, side_2, side_3)){
                    printf("a: %d, b: %d, c:%d \n", side_1 ,side_2 ,side_3);
                    num_triangles++;
                }
            }
        }
    }
    return num_triangles;
}

int compare(const void *a, const void *b){
    return *(int *)a > *(int *)b;
}

//Time complexity: O(n^2). Although it appears to have 3 loops but j is initialised in every first loop so the while loop is not nested under the second rather the first in a way making it O(n^2)
int count_optimized(int *arr, int arr_len){
    int num_triangles = 0;
    qsort(arr, arr_len, sizeof(int), compare);
    printf("sorted array:");
    for(int i=0; i<arr_len; i++)
        printf("%d ", *(arr+i));
    printf("\n");
    for(int i=0; i<arr_len-2; i++){
        int j=i+2;
        for(int ii=i+1; ii<arr_len-1; ii++){
            while(j<arr_len && arr[j]<arr[i]+arr[ii])
                j++;
            //Rather than running the loop everytime for the second loop, we will add all possible triangles
            //possible till the sum of sides is greater than the j, since this is a sorted array.
            num_triangles+=j-ii-1;
        }
    }
    return num_triangles;
}
