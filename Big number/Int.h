/*
Big Int
*/
#pragma once
#include<bits/stdc++.h>
using namespace std;
class Int{
  private:
	string reverse(string r) {
		int n = r.size();
		for (int i = 0; i < n / 2; ++i) {
			swap(r[i], r[n - i - 1]);
		}
		return r;	
	}
  public:
	vector<short> num;
	void printI(char a = 0) {
		for(int i = size() - 1; i >= 0; --i) cout << num[i];
		cout << a;
	}
	int size() {
		return num.size();
	}
	void clean() {
		for(int i = 0; i < num.size() - 1; ++i) {
			if(num[i] > 9) {
				num[i + 1] += num[i] / 10;
				num[i] %= 10;
				if(i == num.size() - 2 && num[i + 1] > 9) num.push_back(0);
			}
		}
		for (int i = num.size() - 1; i > 0 && num[i] == 0; --i){
			num.pop_back();
		}
	}
	void makeempty() {
		num.clear();
	}
	void reverseI() {
		int size = num.size() - 1;
		for (int i = 0; i <= size / 2; ++i) {
			swap(num[i], num[size - i]);
		}
	}
	string to_str(Int a) {
		string r = "";
		for(int i = 0; i < a.num.size(); ++i) {
			r += to_string(a.num[i]);
		}
		return reverse(r);
	}
	string to_str() {
		string r = "";
		for(int i = 0; i < num.size(); ++i) {
			r += to_string(num[i]);
		}
		return reverse(r);
	}
	short operator[](int a) {
		return num[a];
	}
	void operator()(int size_) {
		num.resize(size_);
	}
	void operator=(Int b) {
		num.resize(b.size());
		for(int i = 0; i < b.size(); ++i) num[i] = b.num[i];
	}
	void operator=(int b_) {
		if(b_ == 0) {
			num.resize(1);
			num[0] = 0;
			return ;
		}
		int size = 0;
		for(int i = b_; i > 0; i /= 10) {
			++size;
		}
		num.resize(size);
		for(int i = b_, j = 0; i > 0; i /= 10, j++) {
			num[j] = i % 10;
		}
	}
	void operator=(string b) {
		b = reverse(b);
		num.resize(b.size());
		for(int i = 0; i < b.size(); ++i)
			num[i] = short(b[i] - int('0'));
	}
	Int operator+(Int b) {
		int size_ = min(b.num.size(), num.size()), size_2 = max(b.num.size(), num.size());
		bool v = size_ == num.size();
		Int c;
		c(size_2);
		if(v){
			c.num = b.num;
			for(int i = 0; i < size_; ++i) {
				c.num[i] += num[i];
			}
		}
		else {
			c.num = num;
			for(int i = 0; i < size_; ++i) {
				c.num[i] += b.num[i];
			}
		}
		c.num.push_back(0);
		c.clean();
		return c;
	}
	Int operator+(int b_){
		Int b, a;
		a.num = num;
		b = b_;
		return a + b;
	}
	void operator+=(vector<short> b_) {
		Int b, a, c;
		a.num = num;
		b.num = b_;
		c = a + b;
		num = c.num;
	}
	void operator+=(Int b) {
		Int a, c;
		a.num = num;
		c = a + b;
		num = c.num;
	}
	void operator+=(int b) {
		Int a, c;
		a.num = num;
		c = a + b;
		num = c.num;
	}
	void operator++(){
		Int c;
		c.num = num;
		c += 1;
		num = c.num;
	}
	Int multten(short b, int n) {
		Int c;
		if(b > 9) {
			cerr << "\tERROR!!! --> Int multten(short b, int n) :: b > 9\n\tmultten is number * b * pow(10, n) wich b <= 9";
			exit (EXIT_FAILURE);
		}
		c.num = num;
		for(int i = 0; i < c.size(); ++i) c.num[i] *= b;
		while(n--) c.num.insert(c.num.begin(), 0);
		c.clean();
		return c;
	}
	Int operator*(Int b) {
		Int c;
		c = 0;
		c(num.size() + b.size());
		clean();
		b.clean();
		for (int i = 0; i < num.size(); ++i) {
			c += b.multten(num[i], i);
	}
		return c;
	}
	Int operator*(int b_) {
		Int b, a;
		a.num = num;
		b = b_;
		return a * b;
	}
	void operator*=(vector<short> b_) {
		Int b, a, c;
		a.num = num;
		b.num = b_;
		c = a * b;
		num = c.num;
	}
	void operator*=(Int b) {
		Int a, c;
		a.num = num;
		c = a * b;
		num = c.num;
	}
	void operator*=(int b) {
		Int a, c;
		a.num = num;
		c = a * b;
		num = c.num;
	}
	Int operator/(Int b) {
		Int c, r, i;
		r = 0;
		c.num = num;
		i = b;
		for(; i <= c; i += b) {
			++r;
		}
		if(c < b) r = 0;
		return r;
	}
	Int operator/(int b_) {
		Int b, a;
		a.num = num;
		b = b_;
		return a / b;
	}
	bool operator!=(Int b) {
		clean();
		b.clean();
		if(num.size() != b.size()) return 1;
		for(int i = 0; i < b.size(); ++i) if(b[i] != num[i]) return 1;
		return 0;
	}
	bool operator!=(int b_) {
		Int b, a;
		a.num = num;
		b = b_;
		return a != b;
	}
	bool operator==(Int b) {
		Int a;
		a.num = num;
		return !(a != b);
	}
	bool operator==(int b_) {
		Int a, b;
		a.num = num;
		b = b_;
		return a == b;
	}
	bool operator>(Int b) {
		if(num.size() > b.size()) return 1;
		if(num.size() < b.size()) return 0;
		for(int i = num.size() - 1; i >= 0; --i) {
			if(num[i] > b[i]) return 1;
			if(num[i] < b[i]) return 0;
		}
		return 0;
	}
	bool operator>(int b_) {
		Int a, b;
		a.num = num;
		b = b_;
		return a > b;
	}
	bool operator>=(Int b) {
		Int a;
		a.num = num;
		return a > b || a == b;
	}
	bool operator>=(int b) {
		Int a;
		a.num = num;
		return a > b || a == b;
	}
	bool operator<(Int b) {
		Int a;
		a.num = num;
		return b > a;
	}
	bool operator<(int b_) {
		Int a, b;
		a.num = num;
		b = b_;
		return b > a;
	}
	bool operator<=(Int b) {
		Int a;
		a.num = num;
		return b >= a;
	}
	bool operator<=(int b_) {
		Int a, b;
		a.num = num;
		b = b_;
		return b >= a;
	}
};

