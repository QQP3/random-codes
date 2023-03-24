/*
max heap tree <using arrys>
*/
#pragma once
#include <vector>
using namespace std;
template<typename T>
class arr_maxheap {
private:
	size_t heapsize;
	int comp = 0;
	vector<T> arr;

	void bubbleup(int pos) {
		if (pos == 0 || arr[pos] > arr[pos / 2])
			return;
		swap(arr[pos], arr[pos / 2]);
		bubbleup(pos / 2);
	}

	void bubbledown(int pos) {
		if (pos * 2 >= heapsize || ((pos * 2 + 1 >= heapsize || arr[pos] > arr[pos * 2 + 1]) && arr[pos] > arr[pos * 2]))
			return;
		if (arr[pos] <)
	}

public:
	arr_maxheap(int com) {
		comp = com;
		heapsize = 0;
		arr.reserve(comp);
		arr.shrink_to_fit();
	}

	size_t size() {
		return heapsize;
	}

	void insert(T val) {

	}

	void pop() {

	}

	T top() {
		return arr[0];
	}

	void heapify() {

	}

};
