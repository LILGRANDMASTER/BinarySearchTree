#ifndef __NODE__
#define __NODE__


template <typename T>
struct Node{

	Node(T x):data(x), right(nullptr), left(nullptr){}
	T data;
	Node<T>* right;
	Node<T>* left;
};


#endif