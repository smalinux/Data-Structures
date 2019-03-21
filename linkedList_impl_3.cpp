/*

*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
class DLLNode
{
public:
	T data;
	DLLNode<T> *next;		// self-referential : ))
    DLLNode<T> *prev;      // self-referential : ))
	DLLNode() {
		next = prev = 0;
	}
	DLLNode(const T& d, DLLNode<T> *n = 0, DLLNode<T> *p = 0) {
		data = d;
		next = n;
        prev = p;
	}
};

template<class T>
class DoublyLinkedList
{
protected:
	DLLNode<T> *head, *tail;
	int nodeCount = 0;

    // cout << Object;       // to print all nodes
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
        for (DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->data << ' ';
        return out;
    }
public:
	DoublyLinkedList() {
		head = tail = 0;
	}
	~DoublyLinkedList() {
        clear();
    };
	bool isEmpty()      { return head == 0; }
    void setToNull()    { head = tail = 0; }
	void addToHead(const T& val) {
		if (head != 0)
        {
            head = new DLLNode<T>(val, head, 0);
            head->next->prev = head;
        } else {
            head = tail = new DLLNode<T>(val);
        }
		//
		++nodeCount;
	}
    void addToTail(const T& val) {
    	if (tail != 0) {
            tail = new DLLNode<T>(val, 0, tail);
            tail->prev->next = tail;
    	} 
    	else {
    		head = tail = new DLLNode<T>(val);
        }
    	//
		++nodeCount;
    }
    T deleteFromHead() {
    	int val = head->data;
    	if( head == tail )             // if only one DLLNode on the list;
    		head = tail = 0;
    	else {                         // if more than one DLLNode in the list;
    		head = head->next;
            head->prev = 0;
    	}
        //
		--nodeCount;
    	return val;
    }
    T deleteFromTail() {
    	T val = tail->data;
    	if ( head == tail ) {          // if only one DLLNode on the list;
    		delete head;
    		head = tail = 0;
    	} else {                       // if more than one DLLNode in the list;
            tail = tail->prev;
    		delete tail->next;
    		tail->next = 0;
    	}
    	//
		--nodeCount;
    	return val;
    }
    // void deleteNode(int);
    T* find(int val) const {
    	DLLNode<T> * tmp = head;
    	for ( ; tmp != 0 && !(tmp->data == val); tmp = tmp->next );
        if ( tmp == 0 )
            return 0;
    	else &tmp->data;
    }
/*    void printAll() const {
    	for (DLLNode *tmp = head; tmp != 0; tmp = tmp->next)
	        cout << tmp->data << " ";
		cout << endl;
    }*/
    int nodeNum() {
    	return nodeCount;
    }
    T& firstEl() const {
        return head->data;
    }
    void clear() {
        for (DLLNode<T> *tmp; head != 0; ) {
            tmp = head;
            head = head->next;
            delete tmp;
            //
            --nodeCount;
        }
    }
    int getNthNode(int n) {		// Created by my mind : ))
    	if ( n < nodeCount ) {				// n from 0, nodeCount from 1
    		DLLNode<T> *p = head;
    		while( n-- > 0 ) p = p->next;
    		return p->data;
    	} else {
    		cout << "Out of the range\n";
    		return -1;
    	}
    }
};

int main(int argc, char const *argv[])
{	
	DoublyLinkedList<int> cuteList;
	cuteList.addToHead(5);
	cuteList.addToHead(50);
	cuteList.addToHead(500);
	cout << cuteList.nodeNum(  );
	cout << "\n";
    cout << cuteList;
    cuteList.clear();
    cout << "\n";
    cout << cuteList.nodeNum(  );
    cout << "\n";
    cout << "nth node :" << cuteList.getNthNode( 0 );
    cout << "\n";
	return 0;
}