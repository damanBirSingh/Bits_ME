#include<stdio.h>
#include<stdlib.h>

int* get_table(int);
void print_table(int*);

int main(){
    int n; 
    int *table;
    printf("N = ");
    scanf("%d", &n);
    table = get_table(n);
    print_table(table);
    free(table);
    table = NULL;
}

int* get_table(int n){
    int *temp= malloc(10*sizeof(int));
    for(int i=0; i<10; i++){
        temp[i] = n*(i+1);
    }
    return temp;
}

void print_table(int* table){
    for(int i=0; i<10; i++)
        printf("%d ", *(table+i));
    printf("\n");
}
