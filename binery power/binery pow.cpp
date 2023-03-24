/*
binary power
Time: O(lgn)
Memo: O(1)
*/
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7; 
long long binpow(long long a, long long b){
    a %= MOD;
    long long out = 1;
    while (b > 0) {
        if (b & 1) out = out * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
  return out;
}
int main () {
	
	
	
	return 0;
}
