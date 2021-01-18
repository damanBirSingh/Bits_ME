#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    int uniq_elements=0;
    int lastUnique = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] == lastUnique)
            continue;
        arr[++uniq_elements] = arr[i];
        lastUnique = arr[i];
    } 
    for(int i=0; i<uniq_elements+1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
