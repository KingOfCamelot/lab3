#ifndef ADD_H
#define ADD_H
#include <iostream>
class TreeAss
{
public:
	void insert(int element, tree** t);
	tree* contains(tree* r, int d);
	tree* remove(tree* node, int val);
	void depthfirsttraverse(tree* root);
	void breadthfirsttraverse();
	void PrintTree(tree* t);
	int u;
	tree* Root = 0;
};
#endif