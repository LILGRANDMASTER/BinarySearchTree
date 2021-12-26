#ifndef __BINTREE__
#define __BINTREE__


#include "Node.h"


template <typename T>
struct BinTree{
private:
	Node<T>* root;
	void printPrefix(Node<T>*, int level = 0);	
	void printPostfix(Node<T>*, int level = 0);
	void printInfix(Node<T>*, int level = 0);
	T findMostleft(Node<T>*);

public:

	BinTree();
	void insert(T x);
	void deleteNode(T x);
	void print(int mode);
	Node<T>* searchNode(T x);
};




#endif