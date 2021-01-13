#include<stdbool.h>
#include<stdio.h>

bool searchElement(int[], int);
bool insertElement(int[], int, int);
bool deleteElement(int[], int);

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        int arr[100];
        for(int i=0; i<n; i++)
            scanf("%d", arr[i]);
    }
}

bool searchElement(int arr[], int n){
    bool found = false;
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<arr_len; i++){
        if(arr[i] == n)
            found = true;
    }
    return found;
}

bool insertElement(int arr[], int n, int i){
    bool     inserted = false;
    for 
}


