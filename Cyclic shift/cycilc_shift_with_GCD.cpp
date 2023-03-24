/*
cyclic_shift <using GCD>
Time: O(n)
Memo: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
template<typename T>
void cyclic_shift(vector<T> &a, int k) {
    int n = a.size();
    k %= n;
    int kn = __gcd(n, k);
    for (int i = 0; i < kn; ++i){
        int j = i;
        T ext = a[i];
        do {
            int next = (j + k) % n;
            swap(ext, a[next]);
            j = next;
        } while(j != i);
    }
}
int main() {
	for(int i = 1; i <= 40; ++i) {
		for(int j = 0; j <= i; ++j) {
			vector<char> a;
			a.reserve(i);
			for(int k = 0; k < i; ++k) a.emplace_back(k + 20);
			cyclic_shift(a, j);
			cout << i << "::" << 10 + j << ": ";
			for(auto k : a) cout << k << ' ';
			cout << '\n';
		}
		cout << "***************************************************************************************\n";
	}
	return 0;
}
