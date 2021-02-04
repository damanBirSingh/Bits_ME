#include <iostream>
#include "functions.h"
using namespace std;

static int total_nodes;

int comparator(const void *pLhs, const void *pRhs){
	ll *lhs = (ll *)pLhs;
	ll *rhs = (ll *)pRhs;
	return *lhs > *rhs;
}

bool subset_sum(ll *s, ll *t, ll s_size, ll t_size, ll sum, ll ite, ll target_sum){
	total_nodes++;
    bool found = false;
	if( target_sum == sum )
	{
		found = true; // We found sum
		if( ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum ){ // constraint check
			// Exclude previous added item and consider next candidate
			subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
		}
		return found;
	}
	else{
		if( ite < s_size && sum + s[ite] <= target_sum ){ // constraint check
		
			// generate nodes along the breadth
			for( int i = ite; i < s_size; i++ ){
				t[t_size] = s[i];
				if( sum + s[i] <= target_sum ){
					// consider next level node (along depth)
					subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
				}
			}
		}
	}
}

bool isSubsetSum_backtracking(ll *s, ll size, ll target_sum){
	ll *tuplet_vector = new ll[size];
	int total = 0;
    bool found = false;
	// sort the set
	qsort(s, size, sizeof(int), &comparator);
	for( int i = 0; i < size; i++ )
		total += s[i];

	if( s[0] <= target_sum && total >= target_sum )
		found = subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
	
	delete [] tuplet_vector;
    return found;
}
