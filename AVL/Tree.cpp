#include "stdafx.h"
#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}


Tree::~Tree()
{
	delete root;
}

bool Tree::findHelp(AVLNode* root, int it) const
{
	if (root == NULL) return false;
	if (it < root->element()) return findHelp(root->lc(), it);
	else if (it > root->element()) return findHelp(root->rc(), it);
	else return true;
}
AVLNode* Tree::insertHelp(AVLNode* root, int it)
{
	if (root == NULL)
		return new AVLNode(it);
	
	else if (it < root->element())
		root->setLeft(insertHelp(root->lc(), it));
	
	else 
		root->setRight(insertHelp(root->rc(), it));

	root->setHeight(1+(height(root->lc())>height(root->rc())?height(root->lc()):height(root->rc())));

	int balance = height(root->lc()) - height(root->rc());

	if (balance<-1 && it > root->rc()->element())
	{
		return leftRotation(root);
	}

	else if (balance > 1 && it < root->lc()->element())
		return rightRotation(root);
	
	else if (balance > 1 && it > root->lc()->element())
	{
		root->setLeft(leftRotation(root->lc()));
		return rightRotation(root);
	}
	
	else if (balance < -1 && it < root->rc()->element())
	{
		root->setRight(rightRotation(root->rc()));
		return leftRotation(root);
	}
	
	return root;
}


AVLNode* Tree::deletemin(AVLNode* root)
{
	if (root->rc() == NULL)
		return root->lc();
	else
	{
		root->setRight(deletemin(root->rc()));
		return root;
	}
}

AVLNode* Tree::getmin(AVLNode* root)
{
	if (root->rc() == NULL)
		return root;
	else
		return getmin(root->rc());
}

void Tree::printHelp(AVLNode* root,int level)const
{
	if (root == NULL)
		return;
	printHelp(root->lc(), level + 1);
	for (int i = 0; i < level; i++)
		std::cout << " ";

	std::cout << root->element() << "\n";
	printHelp(root->rc(), level + 1);
}

AVLNode* Tree::removeHelp(AVLNode* root,int it)
{
	if (root == NULL) return root;

	else if (it < root->element())
		root->setLeft(removeHelp(root->lc(), it));
	else if (it > root->element())
		root->setRight(removeHelp(root->rc(), it));
	else
	{
		AVLNode* temp = root;
		if (root->lc() == NULL) 
		{
			root = root->rc();
			delete temp;
		}
		else if (root->rc() == NULL)
		{
			root = root->lc();
			delete temp;
		}
		else
		{
			AVLNode* temp = getmin(root->lc());
			root->setElement(temp->element());
			root->setLeft(deletemin(root->lc()));
			delete temp;
		}
	}

	if (root == NULL)
		return root;

	root->setHeight((height(root->lc())>height(root->rc()) ? height(root->lc()) : height(root->rc())) +1);

	int balance = height(root->lc()) - height(root->rc());

	if (balance<-1 && height(root->rc())<=0)
	{
		return leftRotation(root);
	}
	else if (balance > 1 && height(root->lc()) >= 0)
	{
		return rightRotation(root);
	}
	else if (balance > 1 && height(root->lc())<0)
	{
		root->setLeft(leftRotation(root->lc()));
		return rightRotation(root);
	}
	else if (balance < -1 &&  height(root->rc())>0)
	{
		root->setRight(rightRotation(root->rc()));
		return leftRotation(root);
	}
	return root;
}

int Tree::height(AVLNode* root)
{
	if (root == NULL)
		return 0;
	return root->getHeight();
}

AVLNode* Tree::leftRotation(AVLNode* root)
{
	AVLNode* temp1 = root->rc();
	AVLNode* temp2 = temp1->lc();

	temp1->setLeft(root);
	root->setRight(temp2);

	return temp1;
}

AVLNode* Tree::rightRotation(AVLNode* root)
{
	AVLNode* temp1 = root->lc();
	AVLNode* temp2 = temp1->rc();

	temp1->setRight(root);
	root->setLeft(temp2);

	return temp1;
}

void Tree::insert(const int it)
{
	root = insertHelp(root, it);
}

bool Tree::find(const int it) const
{
	return findHelp(root, it);
}

void Tree::print() const
{
	if (root == NULL)
		std::cout << "The empty\n";
	else
		printHelp(root, 0);
}

int Tree::remove(const int it)
{
	int temp = findHelp(root, it);
	if (temp != -1)
	{
		root = removeHelp(root, it);
	}
	return temp;
}

void Tree::in_orderHelper(AVLNode* root)const
{
	if (root == NULL)
		return;
	in_orderHelper(root->lc());

	std::cout << root->element() << " ";

	in_orderHelper(root->rc());
}

void Tree::pre_orderHelper(AVLNode* root)const
{
	if (root == NULL)
		return;

	std::cout << root->element() << " ";

	pre_orderHelper(root->lc());

	pre_orderHelper(root->rc());
}

void Tree::post_orderHelper(AVLNode* root)const
{
	if (root == NULL)
		return;
	post_orderHelper(root->lc());

	post_orderHelper(root->rc());

	std::cout << root->element() << " ";
}

void Tree::in_order() const
{
	in_orderHelper(root);
}

void Tree::post_order() const
{
	post_orderHelper(root);
}

void Tree::pre_order() const
{
	pre_orderHelper(root);
}