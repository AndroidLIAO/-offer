#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack {
public:
	stack<int> s;
	stack<int> min_stack;
	MinStack() {
		min_stack.push(INT_MIN);
	}

	void push(int x) {
		s.push(x);
		int Min = min_stack.top() > x ? x : min_stack.top();
		min_stack.push(Min);
	}

	void pop() {
		s.pop();
		min_stack.pop();
	}

	int top() {
		return s.top();
	}

	int min() {
		return min_stack.top();
	}
};