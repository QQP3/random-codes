/*
merge sort 
Time: O(nlgn)
memo: O(1)
*/
#include <bits\stdc++.h>
using namespace std;

template <typename T>
void ssort(T* s, T* e) {
	if (s + 1 == e || s == e)	
		return ;
	--e;
	T* itrmi = s, * itrma = e;
	T ma, mi;
	for (T* i = s; i <= e; ++i) {
		if (*itrmi > *i) {
			itrmi = i;		
		}
		if (*itrma < *i) {
			itrma = i;
		}
	}
	ma = *itrma;
	mi = *itrmi;
	*itrmi = *s;
	*itrma = *e;
	*s = mi;
	*e = ma;
	ssort(s + 1, e);	
}
