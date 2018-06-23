#pragma once

class AVLNode
{
	int item;
	AVLNode* left;
	AVLNode* right;
	int height;
public:
	AVLNode() 
	{
		left = nullptr;
		right = nullptr;
	};
	AVLNode(int it, AVLNode*l = nullptr, AVLNode*r = nullptr)
	{
		item = it;
		left = l;
		right = r;
		height = 1;
	}
	
	void setHeight(int it)
	{
		height = it;
	}

	int getHeight() const
	{
		return height;
	}

	~AVLNode() {};

	int element() { return item; }

	void setElement(int it) { item = it; }

	AVLNode* lc() { return left; }

	AVLNode* rc() { return right; }

	void setLeft(AVLNode* l) { left = l; }

	void setRight(AVLNode* r) { right = r; }

	bool isLeaf() { return (left == nullptr && right == nullptr); }
};