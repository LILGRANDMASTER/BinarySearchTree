#include <iostream>
#include "BinTree.h"


template <typename T>
BinTree<T>::BinTree():root(nullptr){}

template <typename T>
void BinTree<T>::insert(T x){
	if(root == nullptr){
		root = new Node<T>(x);
		return;
	}


	Node<T>* current = root;
	Node<T>* previous = root;
	
	while(current != nullptr){
		previous = current;
		if(x > current->data)
			current = current->right;
		else if(x < current->data)
			current = current->left;
		else
			return;
	}

	if(x > previous->data)
		previous->right = new Node<T>(x);
	else
		previous->left = new Node<T>(x);

}

template <typename T>
void BinTree<T>::printPostfix(Node<T>* node, int level){

	if(node != nullptr){
		printPostfix(node->left, level + 1);
		printPostfix(node->right, level + 1);

		for(int i = 0; i<level; i++) std::cout<<"--";

		std::cout<<" "<<node->data <<std::endl;
	}
}

template <typename T>
void BinTree<T>::printPrefix(Node<T>* node, int level){

	if(node != nullptr){
		for(int i = 0; i<level; i++) std::cout<<"--";
		std::cout<<" "<<node->data <<std::endl;

		printPrefix(node->left, level + 1);
		printPrefix(node->right, level + 1);
	}
}

template <typename T>
void BinTree<T>::printInfix(Node<T>* node, int level){

	if(node != nullptr){
		printPrefix(node->left, level + 1);

		for(int i = 0; i<level; i++) std::cout<<"--";
		std::cout<<" "<<node->data <<std::endl;

		printPrefix(node->right, level + 1);
	}

}

template <typename T>
void BinTree<T>::print(int mode){

	switch(mode){

		case 1:		printPrefix(root);
					break;

		case 2:		printPostfix(root);
					break;

		case 3:		printInfix(root);
					break;

		default: 	std::cout<<"ERROR: unknown command"<<std::endl;
	}

}

template <typename T>
Node<T>* BinTree<T>::searchNode(T x){

	
	Node<T>* current = root;
	Node<T>* previous = root;

	while(current != nullptr){
		previous = current;
		if(x > current->data)
			current = current->right;
		else if(x < current->data)
			current = current->left;
		else
			return current;
	}

	return previous;

}

template <typename T>
void BinTree<T>::deleteNode(T x){

}


template struct BinTree<int>;
template struct BinTree<std::string>;

