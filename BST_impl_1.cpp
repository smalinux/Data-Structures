/*
Double linked list
Ref:    Data-Structures-Algorithms-Adam-Drozdek

Features:
- advanced averloaded function: operator<<
- Template data type
*/
#include<bits/stdc++.h>
using namespace std;

template<class T>
class BSTNode {
public:
	T data;
	BSTNode<T> *left;		// self-referential : ))
    BSTNode<T> *right;      // self-referential : ))
	BSTNode() {
		left = right = 0;
	}
	BSTNode(const T& d, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
		data = d; left = l; right = r;
	}
};

template<class T>
class BST {
protected:
	BSTNode<T> *root;
public:
	BST() { root = 0; }
	// ~BST() { clear(); };       // <<<<<< clear() !!!
    bool isEmpty() const { return root == 0 }
    bool isLeaf() const { return (this->left == 0 && this->right == 0); }
    int length() const;     // Recursion
};

int main(int argc, char const *argv[])
{	
	BST<int> cuteList;
	cuteList.addToHead(5);
	return 0;
}