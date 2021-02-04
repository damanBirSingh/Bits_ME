#include<iostream>
#include<chrono>
#include<fstream>
#include "functions.h"


using namespace std;
using namespace std::chrono;

int main(){
    ll max_size = 500;
    int max_val = 10;
    ofstream file_r, file_dp, file_b;
    file_r.open("recursive.txt", ios::out);
    file_dp.open("dynamicProg.txt", ios::out);
    //file_b.open("backtracking.txt", ios::out);
    for(ll i=10; i<max_size ; i+=10){
        ll* arr = getRandomArray(i, max_val);
                
        cout<<"calling Recursive solution\n";
        auto start = high_resolution_clock::now(); 
        bool x = isSubsetSum_recursive(arr, i, 56);
        auto end = high_resolution_clock::now();
        auto duration_r = duration_cast<microseconds>(end - start);
        file_r <<i<<","<<duration_r.count()<<endl;

        bool **subset=(bool **)new bool*[i+1];
        for(int ii=0; ii<i+1; ii++)
            subset[ii] = new bool[56+1];
        /* for (int ii = 0; ii <= i; ii++) //colomn zero */
		    /* subset[ii][0] = true; */
        /* //printf("1st column made zero\n"); */
	    /* for (int ii = 1; ii <= 56; ii++) //row zero */
		    /* subset[0][ii] = false; */
        cout<<"calling dp solution\n";
        start = high_resolution_clock::now();
        bool y = isSubsetSum_dp(arr, i, 56, subset);
        end = high_resolution_clock::now();
        auto duration_dp = duration_cast<microseconds>(end - start);
        file_dp<<i<<","<<duration_dp.count()<<endl;
//         cout<<"calling backtracking solution\n";
//         start = high_resolution_clock::now();
//         bool z = isSubsetSum_backtracking(arr, i, 56);
//         end = high_resolution_clock::now();
//         auto duration_b = duration_cast<microseconds>(end - start);
//         file_b<<z<<","<<duration_b.count()<<endl;

        delete [] arr;
    }
    file_r.close();
    file_dp.close();

}
