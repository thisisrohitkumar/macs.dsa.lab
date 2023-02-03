//3. Write a C++ program to reverse a string using stack
#include<iostream>
#include<string>
#include<stack>
using namespace std;
char inverse(char);
int main(){
	string infixString;
	string postfixString = "";
	stack<char> mystack;
	cout<<"Enter infix expression :"<<endl;
	getline(cin, infixString); 
	cout<<infixString<<endl;
	string::iterator itr; //declaring string iterator
	
	
	while(!mystack.empty()){
		postfixString.push_back(mystack.top());
		mystack.top();
	}
	
	cout<<"Postfix Expression :"<<postfixString<<endl;
	
	
	cout<<endl;
	return 0;
}

char inverse(char brac){
	char inv;
	if(brac == '[')
		inv = ']';
	if(brac == '{')
		inv = '}';
	if(brac == '(')
		inv = ')';
	return inv;
}
