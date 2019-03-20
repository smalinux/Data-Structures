/*

*/
#include<bits/stdc++.h>
using namespace std;
class IntSLLNode
{
public:
	int data;
	IntSLLNode * next;
	IntSLLNode() {
		next = 0;
	}
	IntSLLNode(int d, IntSLLNode * ptr = 0) {
		data = d;
		next = ptr;
	}
};

class IntSLList
{
private:
	IntSLLNode *head, *tail;
	int nodeCount = 0;
public:
	IntSLList() {
		head = tail = 0;
	}
	// ~IntSLList();
	bool isEmpty() { return head == 0; }
	void addToHead(int val) {
		head = new IntSLLNode(val, head);
		if(tail == 0)
			tail = head;
		//
		++nodeCount;
	}
    void addToTail(int val) {
    	if (tail != 0) {
    		tail->next = new IntSLLNode(val);
    		tail = tail->next;
    	} 
    	else
    		head = tail = new IntSLLNode(val);
    	//
		++nodeCount;
    }
    int deleteFromHead() {
    	int val = head->data;
    	IntSLLNode *tmp = head;
    	if( head == tail )
    		head = tail = 0;
    	else
    		head = head->next;
    	//
		--nodeCount;
    	delete tmp;
    	return val;
    }
    int deleteFromTail() {
    	int val = tail->data;
    	if ( head == tail ) {
    		delete head;
    		head = tail = 0;
    	} else {
    		IntSLLNode * tmp;
    		for ( tmp = head; tmp->next != tail; tmp = tmp->next );
    		delete tail;
    		tail = tmp;
    		tail->next = 0;
    	}
    	//
		--nodeCount;
    	return val;
    }
    // void deleteNode(int);
    bool isInList(int val) const {
    	IntSLLNode * tmp;
    	for ( tmp = head; tmp != 0 && !(tmp->data == val); tmp = tmp->next );
    	return tmp != 0;
    }
    void printAll() const {
    	for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
	        cout << tmp->data << " ";
		cout << endl;
    }
    int nodeNum() {
    	return nodeCount;
    }
};

int main(int argc, char const *argv[])
{	
	IntSLList cuteList;
	cuteList.addToHead(5);
	cuteList.addToHead(50);
	cuteList.addToHead(500);
	cuteList.printAll();
	cuteList.deleteFromTail();
	cuteList.printAll();
	cout << cuteList.nodeNum(  );
	return 0;
}