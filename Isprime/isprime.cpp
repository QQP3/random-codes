/*
Isprime
Time: O(sqrt(n))
memo: O(1)
*/
#include <iostream>
using namespace std;
bool isprime(int a){
	for (int i = 2; i * i <= a; ++i)
		if (a % i == 0) {
		cout << "** its devided by " << i << " ** ";
		return 0;
	} 
	return 1;
}
int main () {
	while (1) {
		int n;
		cin >> n;
		cout << "is " << n << " prime: " << isprime(n) << '\n';
	}
	
	return 0;
}
