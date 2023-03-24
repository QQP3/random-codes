/*
min & max heap tree <using linked list>
*/
#pragma once
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
template<typename T>
class max_heap {
private:
	int heap_size;
	max_heap* next_right, * next_left, * pre;
	T val;
	void bubbleup() {
		if (pre == nullptr || pre->val > val)
			return;
		swap(pre->val, val);
		pre->bubbleup();
	}

	void bubbledown() {
		if ((next_left == nullptr && next_right == nullptr))
			return;
		else {
			if (next_left == nullptr) {
				if (next_right->val < val)
					return;
				std::swap(val, next_right->val);
				next_right->bubbledown();
			}
			else {
				if (next_right == nullptr) {
					if (next_left->val < val)
						return;
					std::swap(val, next_left->val);
					next_left->bubbledown();
				}
				else {
					if (max(next_left->val, next_right->val) < val)
						return;
					else {
						if (max(next_left->val, next_right->val) == next_left->val) {
							std::swap(val, next_left->val);
							next_left->bubbledown();
						}
						else {
							std::swap(val, next_right->val);
							next_right->bubbledown();
						}
					}
				}
			}
		}
	}

	max_heap* root() {
		if (pre == nullptr)
			return this;
		return pre->root();
	}

	max_heap* popswap(max_heap* root) {
		--heap_size;
		if (pre == nullptr && next_right == nullptr && next_left == nullptr) {
			heap_size = 0;
			return nullptr;
		}
		if (next_right == nullptr)
			if (next_left == nullptr) {
				std::swap(root->val, val);
				return this;
			}
			else {
				std::swap(root->val, next_left->val);
				return next_left;
			}
		else if (next_left == nullptr) {
			std::swap(root->val, next_right->val);
			return next_right;
		}
		else
			next_right->heap_size > next_left->heap_size ? next_right->popswap(root) : next_left->popswap(root);
	}
/*-----------------------------------------------------------------------------------------------------------------------------------*/
public:
	max_heap(int h = 0, max_heap* nr = nullptr, max_heap* nl = nullptr, max_heap* pr = nullptr) {
		heap_size = h;
		next_right = nr;
		next_left = nl;
		pre = pr;
	}

	int size() {
		return heap_size;
	}

	T top() {
		if (!heap_size) {
			exit(EXIT_FAILURE);
		}
			
		return val;
	}

	bool empty() {
		return !heap_size;
	}

	void push(T val_) {
		++heap_size;
		if (heap_size == 1) {
			val = val_;
			return;
		}
		if (next_right == nullptr) {
			//next_right = new max_heap{1, nullptr, nullptr, this, val_};
			next_right = new max_heap<T>(1, nullptr, nullptr, this);
			next_right->val = val_;
			next_right->bubbleup();
			return;
		}
		if (next_left == nullptr) {
			//next_left = new max_heap{ 1, nullptr, nullptr, this, val_ };
			next_left = new max_heap<T>(1, nullptr, nullptr, this);
			next_left->val = val_;
			next_left->bubbleup();
			return;
		}
		next_right->heap_size < next_left->heap_size ? next_right->push(val_) : next_left->push(val_);
		return;
	}

	void pop() {
		max_heap* mainroot = this;
		max_heap* leaf = popswap(mainroot);
		if (leaf == nullptr)
			return;
		leaf->pre->next_left == leaf ? leaf->pre->next_left = nullptr : leaf->pre->next_right = nullptr;
		delete leaf;
		mainroot->bubbledown();
	}
};

















template<typename T>
class min_heap {
private:
	int heap_size;
	min_heap* next_right, * next_left, * pre;
	T val;
	void bubbleup() {
		if (pre == nullptr || pre->val < val)
			return;
		swap(pre->val, val);
		pre->bubbleup();
	}

	void bubbledown() {
		if ((next_left == nullptr && next_right == nullptr))
			return;
		else {
			if (next_left == nullptr) {
				if (next_right->val > val)
					return;
				std::swap(val, next_right->val);
				next_right->bubbledown();
			}
			else {
				if (next_right == nullptr) {
					if (next_left->val > val)
						return;
					std::swap(val, next_left->val);
					next_left->bubbledown();
				}
				else {
					if (min(next_left->val, next_right->val) > val)
						return;
					else {
						if (min(next_left->val, next_right->val) == next_left->val) {
							std::swap(val, next_left->val);
							next_left->bubbledown();
						}
						else {
							std::swap(val, next_right->val);
							next_right->bubbledown();
						}
					}
				}
			}
		}
	}

	min_heap* root() {
		if (pre == nullptr)
			return this;
		return pre->root();
	}

	min_heap* popswap(min_heap* root) {
		--heap_size;
		if (pre == nullptr && next_right == nullptr && next_left == nullptr) {
			heap_size = 0;
			return nullptr;
		}
		if (next_right == nullptr)
			if (next_left == nullptr) {
				std::swap(root->val, val);
				return this;
			}
			else {
				std::swap(root->val, next_left->val);
				return next_left;
			}
		else if (next_left == nullptr) {
			std::swap(root->val, next_right->val);
			return next_right;
		}
		else
			next_right->heap_size > next_left->heap_size ? next_right->popswap(root) : next_left->popswap(root);
	}
/*-----------------------------------------------------------------------------------------------------------------------------------*/
public:
	min_heap(int h = 0, min_heap* nr = nullptr, min_heap* nl = nullptr, min_heap* pr = nullptr) {
		heap_size = h;
		next_right = nr;
		next_left = nl;
		pre = pr;
	}

	int size() {
		return heap_size;
	}

	T top() {
		if (!heap_size)
			return NULL;
		return val;
	}

	bool empty() {
		return !heap_size;
	}

	void push(T val_) {
		++heap_size;
		if (heap_size == 1) {
			val = val_;
			return;
		}
		if (next_right == nullptr) {
			//next_right = new min_heap(1, nullptr, nullptr, this, val_);
			next_right = new min_heap<T>(1, nullptr, nullptr, this, val_);
			next_right->bubbleup();
			return;
		}
		if (next_left == nullptr) {
			//next_left = new min_heap{ 1, nullptr, nullptr, this, val_ };
			next_left = new min_heap<T>{ 1, nullptr, nullptr, this, val_ };
			next_left->bubbleup();
			return;
		}
		next_right->heap_size < next_left->heap_size ? next_right->push(val_) : next_left->push(val_);
		return;
	}

	void pop() {
		min_heap* mainroot = this;
		min_heap* leaf = popswap(mainroot);
		if (leaf == nullptr)
			return;
		leaf->pre->next_left == leaf ? leaf->pre->next_left = nullptr : leaf->pre->next_right = nullptr;
		delete leaf;
		mainroot->bubbledown();
	}
};
