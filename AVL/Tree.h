#pragma once
#include "AVLNode.h"
#include <iostream>
class Tree
{
private:
	AVLNode* root; 

	AVLNode* insertHelp(AVLNode*, const int);

	//delete min leaf
	AVLNode* deletemin(AVLNode*);
	AVLNode* removeHelp(AVLNode*, const int);
	
	// find next element after deleteing one
	AVLNode* getmin(AVLNode*);
	bool findHelp(AVLNode*, const int)const;
	
	//rotatetion helper functions
	AVLNode* leftRotation(AVLNode*);
	AVLNode* rightRotation(AVLNode*);

	// printing helper functions
	void printHelp(AVLNode*, int)const;
	void in_orderHelper(AVLNode*)const;
	void pre_orderHelper(AVLNode*)const;
	void post_orderHelper(AVLNode*)const;

public:
	Tree();
	~Tree();

	int height(AVLNode*); // return a height of tree

	void insert(const int it);

	bool find(const int it) const;

	int remove(const int it);

	void print() const;

	void in_order() const;

	void post_order() const;

	void pre_order() const;

};

