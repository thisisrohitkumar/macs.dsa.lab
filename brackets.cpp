//3. Write a C++ program to reverse a string using stack
#include<iostream>
#include<string>
#include<stack>
using namespace std;
char inverse(char);
int main(){
	string mystring; // creating string object for storing string
	stack<char> mystack; // creating stack object to store entered string
	cout<<"Enter a string :"<<endl;
	getline(cin, mystring); // getting the string from the user
	string::iterator itr; //declaring string iterator
	//pushing open brackets into the stack
	for(itr = mystring.begin(); itr != mystring.end(); itr++){
		if(*itr == '[' || *itr == '{' || *itr == '('){
			mystack.push(*itr);
			continue;
		}
		if(*itr == inverse(mystack.top())){
			mystack.pop();
			continue;
		}
	}
	if(mystack.empty())
		cout<<"Brackets are Balanced"<<endl;
	else
		cout<<"Brackets are Not Balanced"<<endl;
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
