#ifndef ADD_H
#define ADD_H
#include <iostream>
#include "iterator.h"
struct node
{
	int info;
    node* LeftBranch;
    node* RightBranch;
};
class Tree
{
public:
	void insert(int element, node** t);
	bool contains(int value);
    node* remove(node* node, int val);
	void PrintTree(node* t);
	int u;
    node* Root = 0;
    Iterator* create_bft_Iterator(node* elem);
    class bft_Iterator : public Iterator 
    {
        private: node* curr;
        public:
            bft_Iterator(node* root)
            {
                turn* elem = new turn;
                headq = elem;
                elem->key = root;
                elem->next = nullptr;
                last = elem;
                curr = root;
            };
            struct turn 
            {
                node* key;
                turn* next;
            };
            turn* headq;
            turn* last;
            void push(node* value);
            void pop();
            int next() override;
            bool has_next() override;
    };
    Iterator* create_dft_Iterator(node* elem);
    class dft_Iterator : public Iterator 
    {
        public:
            node* curr;
            dft_Iterator(node* root)
            {
                stack* elem = new stack;
                elem->key = root;
                elem->prev = nullptr;
                top = elem;
            };
            struct stack 
            {
                node* key;
                stack* prev;
            };
            stack* top;
            void push(node* value);
            void pop();
            int next() override;
            bool has_next() override;
    };
};
#endif