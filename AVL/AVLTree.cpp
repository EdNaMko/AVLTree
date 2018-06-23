// AVLTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>

void print(const Tree& avl)
{
	std::cout << "Enter 0||1||2||3(Printing tree,1-Inorder,2-Postorder,3-Preorder)::";
	int a = 0;
	std::cin >> a;
	switch (a)
	{
	case 0:
		avl.print();
		break;
	case 1:
		avl.in_order();
		break;
	case 2:
		avl.post_order();
		break;
	case 3:
		avl.pre_order();
		break;
	}

}

int main()
{
	Tree avl;
	char c;
	while (std::cout << "Enter I/D/P(Insert,Delete,Print)::", std::cin >> c)
	{
		int a = 0;
		switch (c)
		{
		case 'i':
		case 'I':
			std::cout << "Enter Number that you want to add a tree::";
			std::cin >> a;
			avl.insert(a);
			break;
		case 'd':
		case 'D':
			std::cout << "Enter Number that you want to delete of tree::";
			std::cin >> a;
			avl.remove(a);
			break;
		case 'p':
		case'P':
			print(avl);
		}
		std::cout << "Enter ctrl+z or F6 for exit::" << std::endl;;
	}

	bool t = avl.find(5);
	std::cout << t;
	return 0;
}

