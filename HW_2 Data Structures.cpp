// HW_2 Data Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // include Standard input/output
#include<string> // include string
#include"Stack.h" // include "Stack.h" file
#include"StackNode.h" // include "StackNode.h" file
#include <fstream> // include read & write on files
#include <stack> //include stack container class (class template)
using namespace std; // use the namespace called std

double evaluate_prefix(string e) {

	Stack <int> stack;
	int episode_1, episode_2;

	//start at the expressexion on the top until the button 
	for (int i = e.size(); i >= 0; i--) {
	
		// Is it a digit?
		if (isdigit(e[i])) {
			stack.push(e[i] - '0');//Put it at the stack if it is a digit
		}

		// Is it an operator?
		else {
			
			episode_1 = stack.top(); // Save the data of the top-stack 
			stack.pop(); // Then delete it 

			//Is is the stack empty?
			if (stack.check_empty()) {
				cout << "No more operations" << endl;
			}
			// Is it the stack NOT empty? 
			else {
			
				episode_2 = stack.top(); // Save the data of the new top-stack 
				stack.pop(); //Then delete it

				//Depending of which operator do the following cases 
				switch (e[i]) {
				case '+':
					// push op1 + op2
					stack.push(episode_1 + episode_2);
					break;
				case '-':
					// push op1 - op2
					stack.push(episode_1 - episode_2);
					break;
				case '*':
					// push op1 * op2
					stack.push(episode_1 * episode_2);
					break;
				case '/':
					// push op1 / op2
					stack.push(episode_1 / episode_2);
					break;
				case '%':
					// push op1  % op 2 
					stack.push(episode_1 % episode_2);
					break;
				}

			}

		}
		
	
	}

	// return the top-stack (result)
	return stack.top();

}




int main()
{
	// Question-2 -->Write a prefix stack and show how it works (in main).
	//This operation can only capture 1 digit 

	cout << "Question 2" << endl;
	string expression;
	expression = "*43";
	cout << expression << "= " << evaluate_prefix(expression) << endl;
	expression = "+43";
	cout << expression << "= " << evaluate_prefix(expression) << endl;
	expression = "%43";
	cout << expression << "= " << evaluate_prefix(expression) << endl;
	expression = "%96";
	cout << expression << "= " << evaluate_prefix(expression) << endl;
	expression = "+-*3321";
	cout << expression << "= " << evaluate_prefix(expression) << endl;

	cout << endl;
	//Question 3- Which is faster a an array based stack or a linked list based stack. (Arrays are faster than Linked list)
	cout << "Question 3" << endl;
	//ARRAY BASED STACK
	Stack <int> s;
	s.push(3);
	s.push(2);
	s.push(1);
	//Do I want to delete value 1?
	//s.pop();
	s.push(4);
	s.list_all_elements();
	
	cout << endl;
	//LINKED LIST STACK
	StackNode* root = NULL;
	push(&root, 111);
	push(&root, 222);
	push(&root, 333);
	cout << "--------------------------------\n";
	cout << pop(&root) << " popped from stack\n";
	cout << "--------------------------------\n";

	cout << "Top element is " << peek(root) << endl;

	cout << "Elements present in stack : ";
	//print all elements on the stack :
	while (!isEmpty(root))
	{
		// print top element on the stack
		cout << peek(root) << " ";
		// remove top element on the stack
		pop(&root);
	}

	cout << endl<<endl;


	/*	Question-4 --> Create your own stack functions to do the following:
		a. List all the elements in the stack
		b. Iterate through the stack and change one of the values based on its position
	*/	
	cout << "Question 4" << endl;

	int size; //variable int
	cout << "What size do you want in your stack:\n ";
	cin >> size; //ask user for size 
	Stack<int> a(size); 
	for (int i = 0; i < size ; i++)
	{
		// push i numbers into stack until the lenght size
		a.push(i);
	}

	a.list_all_elements(); // print all elements
	a.change_element_value(); // change the elements random

	cout << "Here is changed it:" << endl;
	a.list_all_elements(); // print allthe changed elements



	/*
		Question 6 
		Read text file include stack to be more easy and reverse
		Create a text file that you input of
		Chuck Norris jokes and have the program reverse each of the jokes.
	*/
	ifstream myfile; //stream class that reads files 
	myfile.open("jokes.txt"); // open the file 
	stack <char> lines; // create a stack
	char temp; // variable 

	// if file is FOUND
	if (myfile) {
		//extract characters from the stream
		while (myfile.get(temp)) {
			cout << temp; // print temp(character)
			lines.push(temp); // push temp(character) on the stack

		} myfile.close(); //close the file 

	}
	// If file is NOT FOUND
	else {
		cout << "Such file is not found.";
	}
	
	cout << endl;

	//Reverse the characters of the stack 
	while (!lines.empty()) {
		cout << lines.top(); // Print the character at the Top
		lines.pop(); //Delete the character at the Top
	}

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
