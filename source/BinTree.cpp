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


	Node<T>* current = searchNode(x);

	if(x > current->data)
		current->right = new Node<T>(x);
	else if(x < current->data)
		current->left = new Node<T>(x);
	else
		return;

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
		printInfix(node->left, level + 1);

		for(int i = 0; i<level; i++) std::cout<<"--";
		std::cout<<" "<<node->data <<std::endl;

		printInfix(node->right, level + 1);
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
T BinTree<T>::findMostleft(Node<T>* node){
	while(node->left != nullptr)
		node = node->left;

	return node->data;
}

template <typename T>
void BinTree<T>::deleteNode(T x){
	
	Node<T>* current = root;
	Node<T>* previous = root;

	while(current != nullptr && current->data != x){
		previous = current;
		if(x > current->data)
			current = current->right;
		else if(x < current->data)
			current = current->left;
	}

	if(current == nullptr)
		return;


	if(current->left == nullptr && current->right == nullptr){

		if(current != root){

			if(previous->left == current)
				previous->left = nullptr;
			else
				previous->right = nullptr;
		}
		else
			root = nullptr;

		delete current;
	}
	else if(current->left && current->right){
		T mostLeft = findMostleft(current->right);
		deleteNode(mostLeft);
		current->data = mostLeft;
	}
	else{
		Node<T>* child = (current->right)? current->right : current->left;

		if(current != root){
			if(current == previous->right)
				previous->right = child;
			else
				previous->left = child;
		}
		else
			root = child;

		delete current;
	}

}


template struct BinTree<int>;
template struct BinTree<std::string>;

