#pragma once
#ifndef STACKNODE
#define STACKNODE
#include <iostream> // include Standard input/output
using namespace std;// use the namespace called std

// A linked list node
class StackNode
{
public:
	int data; //int data
	StackNode* next; // pointer to the next node

};
// Create a new node and return its address
StackNode* newNode(int data)
{
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}
//Add root data to the stack
void push(StackNode** root, int data)
{
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << " pushed to stack\n";
}
//Check if the stack is empty or not
int isEmpty(StackNode* root)
{
	return !root;
}
//Pop at the top element of the stack
int pop(StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}
//Return the top element of the stack
int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}



#endif //STACKNODE