#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;
int size = 0;

struct node* createNode(){
	struct node *ptr;
	int value;
	ptr = (struct node*) malloc(sizeof(struct node));
	cout<<"Enter Node Value : ";
	cin>>value;
	ptr->data = value;
	ptr->next = NULL;
	cout<<"Node Successfully Created!"<<endl;
	size++;
	return ptr;	
}

void insertAtEnd(){
	struct node *newNode;
	newNode = createNode();
	if(head != NULL){
		struct node *ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newNode;
	}
	else{
		head = newNode;
		cout<<"Head is initialized"<<endl;
	}
}

void insertAtStart(){
	struct node *newNode;
	newNode = createNode();
	if(head != NULL){
		struct node *temp = head;
		head = newNode;
		newNode->next = temp;
		cout<<"Node added at start!"<<endl;
	}
	else{
		head = newNode;
		cout<<"Head is initialized"<<endl;
	}
}

void insertAtPos(){
	struct node *newNode, *temp;
	struct node *ptr = head;
	int pos, loop;
	cout<<"Enter Position : "<<endl;
	cin>>pos;
	if(pos < 0 || pos > size){
		cout<<"Invalid Position"<<endl;
	}
	else{
		if(pos == 0)
			insertAtStart();
		else if(pos == size)
			insertAtEnd();
		else{
				newNode = createNode();
				loop = pos-1;
				while(loop > 0){
					ptr = ptr->next;
					loop--;	
				}
				temp = ptr->next;
				ptr->next = newNode;
				newNode->next = temp;
				cout<<"New Node added after Node No. "<<pos<<endl;
		}
	}	
}

void displayList(){
	if(head != NULL){
		struct node *ptr = head;
			cout<<"Start <- ";
			while(ptr != NULL){
				cout<<ptr->data<<" <- ";
				ptr = ptr->next;
			}
			cout<<"End"<<endl;
		}
	else{
		cout<<"Linked List is Empty"<<endl;
	}
}

void searchByValue(){
	struct node *ptr = head;
	int element, pos = 1;
	if(head != NULL){
		cout<<"Enter value to be search : "<<endl;
		cin>>element;
		while(ptr != NULL){
			if(ptr->data == element){
				cout<<element<<" exists in the linked list at position no. "<<pos<<endl;
				return;
			}
			ptr = ptr->next;
			pos++;
		}
		cout<<element<<" does not exists in the linked list"<<endl;
	}
	else{
		cout<<"Linked list is empty"<<endl;
	}
}

void searchByPos(){
	struct node *ptr = head;
	int element, pos, loop;
	if(head != NULL){
		cout<<"Enter Position : "<<endl;
		cin>>pos;
		if(pos < 0 || pos > size){
		cout<<"Invalid Position"<<endl;
		}
		else{
			loop = pos-1;
			while(loop > 0){
				ptr = ptr->next;
				loop--;
			}
			element = ptr->data;
			cout<<element<<" is at position no. "<<pos<<endl;
		}
	}
	else{
		cout<<"Linked list is empty"<<endl;
	}
}

void deleteFromStart(){
	if(head != NULL){
		struct node *ptr = head;
		head = ptr->next;
		cout<<"Node deleted from the start"<<endl;
	}
	else{
		cout<<"Linked list is Empty"<<endl;
	}
}


void deleteFromEnd(){
	if(head != NULL){
		struct node *ptr = head, *prev;
		while(ptr->next != NULL){
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		cout<<"Node deleted from the end"<<endl;
		
	}
	else{
		cout<<"Linked list is Empty"<<endl;
	}
}

void deleteFromPos(){
	
	if(head != NULL){
		struct node *prev;
		struct node *ptr = head;
		int pos, loop;
		cout<<"Enter Position : "<<endl;
		cin>>pos;
		if(pos < 1 || pos > size){
			cout<<"Invalid Position"<<endl;
		}
		else{
			if(pos == 1)
				deleteFromStart();
			else if(pos == size)
				deleteFromEnd();
			else{
					loop = pos-1;
					while(loop > 0){
						prev = ptr;
						ptr = ptr->next;
						loop--;	
					}
					prev->next = ptr->next;
					cout<<"Node delete from the position no."<<pos<<endl;
			}
		}
	}
	else{
		cout<<"Linked list is Empty"<<endl;
	}
}


int main(){

	int choice;	
	
	while(1){
		cout<<"Press 1 to insert at the end"<<endl;
		cout<<"Press 2 to insert at start"<<endl;
		cout<<"Press 3 to insert at specific position"<<endl;
		cout<<"Press 4 to display Linked List"<<endl;
		cout<<"Press 5 to search by value"<<endl;
		cout<<"Press 6 to search by position"<<endl;
		cout<<"Press 7 to delete from start"<<endl;
		cout<<"Press 8 to delete from End"<<endl;
		cout<<"Press 9 to delete from specific position"<<endl;
		cin>>choice;
		if(choice == 1){
			insertAtEnd();
		}
		else if(choice == 2){
			insertAtStart();	
		}
		else if(choice == 3){
			insertAtPos();
		}
		else if(choice == 4){
			displayList();
		}
		else if(choice == 5){
			searchByValue();
		}
		else if(choice == 6){
			searchByPos();
		}
		else if(choice == 7){
			deleteFromStart();
		}
		else if(choice == 8){
			deleteFromEnd();
		}
		else if(choice == 9){
			deleteFromPos();
		}
		else{
			free(head);
			exit(0);
		}
	}
		
	return 0;
}
