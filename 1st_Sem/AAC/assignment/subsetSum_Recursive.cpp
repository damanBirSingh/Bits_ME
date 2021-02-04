#include <stdio.h>
#include "functions.h"

bool isSubsetSum_recursive(ll* set, ll n, ll sum){
    //printf("%d, %d :: ", n, sum);
	if (sum==0)
		return true;
	if (n==0)
		return false;

	return isSubsetSum_recursive(set, n - 1, sum) || isSubsetSum_recursive(set, n - 1, sum - *(set + n-1)); //either we discard that number or take it.
}

/* int main() */
/* { */
/* 	int sum = 786; */
/*      ll max_size = 100000; */
/*     int max_val = 100; */
/*     for(ll i=100; i<max_size ; i+=100){ */
/*         ll* arr = getRandomArray(i, max_val); */
/*         /1* for(int ii=0; ii<i; ii++) *1/ */    
/*         /1*     printf("%lli ", *(arr+ii)); *1/ */
/*         if (isSubsetSum_recursive(arr, i, sum) == true) */
/* 		    printf("\n\nFound a subset with given sum\n\n"); */
/*     	else */
/* 		    printf("\n\nNo subset with given sum\n\n"); */

/*     } */
/* 	return 0; */
/* } */
