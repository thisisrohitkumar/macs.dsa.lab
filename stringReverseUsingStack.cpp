//3. Write a C++ program to reverse a string using stack
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
	string mystring; // creating string object for storing string
	stack<char> mystack; // creating stack object to store entered string
	cout<<"Enter a string :"<<endl;
	getline(cin, mystring); // getting the string from the user
	string::iterator itr; //declaring string iterator
	for(itr = mystring.begin(); itr != mystring.end(); itr++){
		mystack.push(*itr); //storing string in the stack char by char
	}
	cout<<"Reversed String :"<<endl;
	while(!mystack.empty()){
		cout<<mystack.top(); 
		mystack.pop();		
	}
	cout<<endl;
	return 0;
}
