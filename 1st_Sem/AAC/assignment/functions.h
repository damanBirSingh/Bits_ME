#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef long long int ll;

ll* getRandomArray(ll, ll);
bool isSubsetSum_recursive(ll*, ll, ll);
bool isSubsetSum_dp(ll*, ll, ll, bool**);
bool isSubsetSum_backtracking(ll*, ll, ll);

#endif
