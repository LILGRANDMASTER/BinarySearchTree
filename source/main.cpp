#include <iostream>
#include "BinTree.h"
#include <stdio.h>


int main(){

	BinTree<int> tree;
	tree.insert(1);
	tree.insert(10);
	tree.insert(-10);
	tree.insert(5);
	tree.insert(6);
	tree.insert(3);
	tree.insert(20);
	tree.insert(-20);
	tree.insert(-4);
	tree.print(3);
	tree.deleteNode(5);
	std::cout<<"================================"<<std::endl;
	tree.print(3);
	
	return 0;
}