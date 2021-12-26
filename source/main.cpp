#include <iostream>
#include "BinTree.h"
#include <stdio.h>

int main(){

	BinTree<int> tree;
	tree.insert(1);
	tree.print(3);
	tree.insert(10);
	tree.insert(-10);
	tree.insert(5);
	tree.insert(6);
	tree.insert(3);
	tree.insert(20);
	tree.insert(-20);
	tree.insert(-4);
	tree.print(3);
	if(3 == (tree.searchNode(3))->data) std::cout<<"Ok"<<std::endl;
	return 0;
}