#ifndef RANDOMARRAY_H
#define RANDOMARRAY_H

#include<iostream>
#include<math.h>

typedef long long int ll;

using namespace std;

ll* getRandomArray(ll size, ll max){
    ll* array = new ll[size];
    for(int i=0; i<size; i++)
        *(array+i) = (rand() % max);
    return array;
}

#endif

/* int main(){ */
/*     ll* arr = getRandomArray(10, 256); */
/*     for(int i=0; i<10; i++) */
/*         cout<<*(arr+i)<<" "; */

/* } */
