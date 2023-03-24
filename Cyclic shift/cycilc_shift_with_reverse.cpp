/*
cyclic_shift  <using reverse>
Time: O(n)
Memo: O(1)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
void cyclic_shift(vector<T>& a, int k) {
	int n = a.size();
	k %= n;
	reverse(a.begin(), a.end());
	reverse(a.begin(), a.begin() + k);
	reverse(a.begin() + k, a.end());
}

