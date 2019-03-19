/*
	Reference : https://www.geeksforgeeks.org/linked-list-set-1-introduction/
*/
#include<bits/stdc++.h>
using namespace std;

class Node { // ---------------------------------- Start Node
	public:
		int data;				// any data, int in this case
		Node * next;			// class pointer
}; // -----------------------------------------------  End Node

int main(int argc, char const *argv[])
{
	Node * head 	= NULL; // Pointer of Node
	Node * Second 	= NULL;
	Node * Third 	= NULL;

	
	/*
	-----------// allocation
	
			head         second         third  
	        |             |             |  
	        |             |             |  
	    +---+-----+     +----+----+     +----+----+  
	    | # | # |     	| # | # |     	| # | # |  
	    +---+-----+     +----+----+     +----+----+
	*/
	head 	= new Node();
	Second 	= new Node();
	Third 	= new Node();
	
	/*
	-----------// Assign & Link
	
	head      
    |  
    |  
	+---+---+     +---+---+     +----+------+  
	| 1 | o------>| 2 | o------>| 3 | NULL |  
	+---+---+     +---+---+     +----+------+    
	*/
	head->data = 1;			// assign any random data in first node
	head->next = Second;	// Link first node with the second node
	Second->data	= 2;
	Second->next	= third;
	Third->data		= 3;
	Third->next		= NULL;


	return 0;
}