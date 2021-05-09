#pragma once
#ifndef STACK
#define STACK
using namespace std;  // use the namespace called std
#include <random> // include random number generator
#include <iostream> // include Standard input/output
#include <string> // include string

template <typename T> class Stack {
	// set member variables
	int max;
	int stack_top;
	T* elements;

public:
	explicit Stack(int size) {
		// set max size to the given size, and create
		// array of that size, if the given size
		// is less than 0, use the default of 4
		if (size > 0) {
			max = size;
			stack_top = 0;
			elements = new T[max];
		}
		else {
			max = 4;
			stack_top = 0;
			elements = new T[max];
		}
	}

	Stack() {
		// no argument constructor, sets
		// everything to the default size of 4
		max = 4;
		stack_top = 0;
		elements = new T[max];
	}

	~Stack() {
		// destructor
		delete[] elements;
	}

	T top() {
		// return the value at the top of the stack
		return elements[stack_top - 1];
	}

	void push(T item) {
		if (check_full()) {
			// if the stack is full, nothing can be pushed
			cout << "Stack is full, cannot push any more elements" << endl;
		}
		else {
			// add the new value to the top of the stack
			elements[stack_top] = item;
			stack_top++;
		}
	}
	void pop() {
		if (!check_empty()) {
			// decrease the stack top
			stack_top--;
		}
		else {
			cout << "Stack is empty, cannot remove from empty stack." << endl;
		}

	}
	bool check_empty() {
		// return true if empty
		return(stack_top == 0);
	}

	bool check_full() {
		// return true if full
		return (stack_top == max);
	}
	void list_all_elements() {
		// go thru the list and print every value
		for (int i = 0; i < max; ++i) {
			cout << elements[i] << endl;
		}
	}
	void change_element_value() {
		// using random number generator to get a random position in the stack
		random_device rd;
		mt19937 bl(rd());
		uniform_int_distribution<int> int_dist(0, stack_top);
		int pos_to_change = int_dist(bl);

		T changed_val =0;
		T old_val =0;

		// go thru the list to come up with a way to change the value
		for (int i = 0; i < pos_to_change; ++i) {
			// add all values up to the changed value to create a unique value
			changed_val += elements[i];

			// set position in stack to changed value
			if (i == pos_to_change - 1) {
				old_val = elements[i + 1];
				elements[i + 1] = changed_val;
			}
		}

		// print changed postion and new value
		cout << "Changed postition: " << pos_to_change << endl;
		cout << "Previous Value: " << old_val << " Changed value: " << changed_val << endl;
	}
	
};

#endif //STACK
