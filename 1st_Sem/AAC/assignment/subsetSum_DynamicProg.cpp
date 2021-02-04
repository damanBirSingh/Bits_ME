#include<stdio.h>
#include "functions.h"

bool isSubsetSum_dp(ll* set, ll n, ll sum, bool **subset){
    //printf("%d,  %d :: ", n, sum);
	//bool subset[n + 1][sum + 1];
    /* bool **subset=(bool **)new bool*[n+1]; */
    /* for(int i=0; i<n+1; i++) */
    /*     subset[i] = new bool[sum+1]; */
   
	for (int i = 0; i <= n; i++) //colomn zero
		subset[i][0] = true;
    //printf("1st column made zero\n");
	for (int i = 1; i <= sum; i++) //row zero
		subset[0][i] = false;
    //printf("1st row made zero\n");
	for (int i = 1; i <= n; i++) { //set loop 
		for (int j = 1; j <= sum; j++) { //sum loop
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

	return subset[n][sum];
}

/* int main() */
/* { */
/* 	int sum = 786; */
/*      ll max_size = 100000; */
/*     int max_val = 100; */
/*     for(ll i=100; i<max_size ; i+=100){ */
/*         ll* arr = getRandomArray(i, max_val); */
/*         printf("got a random array of size %d\n", i); */
/*         /1* for(int ii=0; ii<i; ii++) *1/ */    
/*         /1*     printf("%lli ", *(arr+ii)); *1/ */
/*         if (isSubsetSum_dp(arr, i, sum) == true) */
/* 		    printf("\n\nFound a subset with given sum\n\n"); */
/*     	else */
/* 		    printf("\n\nNo subset with given sum\n\n"); */
/*         delete [] arr; */
/*     } */
/* 	return 0; */
/* } */
