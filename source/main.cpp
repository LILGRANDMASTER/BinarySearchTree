#include <iostream>
#include "BinTree.h"

void menu(){
    std::cout<<"1.             ADD NODE"<<std::endl;
    std::cout<<"2.          DELETE NODE"<<std::endl;
    std::cout<<"3.    PRINT PREFIX TREE"<<std::endl;
    std::cout<<"4.   PRINT POSTFIX TREE"<<std::endl;
    std::cout<<"5.     PRINT INFIX TREE"<<std::endl;
    std::cout<<"6.          END PROGRAM"<<std::endl;
}

int main(){

	BinTree<int> tree;
    
    while(true){
        
        menu();
        int comm;
        std::cout<<"Command: ";
        std::cin>>comm;
        int x = 0;

        switch(comm){

            case 1:     std::cout<<"Enter node you want to add: ";
                        std::cin>>x;
                        tree.insert(x);
                        break;

            case 2:     std::cout<<"Enter node you want to delete: ";
                        std::cin>>x;
                        tree.deleteNode(x);
                        break;

            case 3:     tree.print(1);
                        break;

            case 4:     tree.print(2);
                        break;

            case 5:     tree.print(3);
                        break;

            case 6:     return 0;
                        break;

            default:    std::cout<<"Unknown command!!!"<<std::endl;
                        break;


        }
    }
	
	return 0;
}
