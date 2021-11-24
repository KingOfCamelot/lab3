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
class BinarySearchTree
{
private: void PrivateInsert(int element, node** t);
public:
	void insert(int value);
	bool contains(int value);
    node* remove(node* node, int value);
	void PrintTree(node* temp);
	int ValueOutputLevel;
    node* Root = 0;
    Iterator* create_bft_Iterator(node* elem);
    class bft_Iterator : public Iterator 
    {
        private: node* Current;
        public:
            bft_Iterator(node* root)
            {
                turn* elem = new turn;
                Head = elem;
                elem->key = root;
                elem->next = nullptr;
                Last = elem;
                Current = root;
            };
            struct turn 
            {
                node* key;
                turn* next;
            };
            turn* Head;
            turn* Last;
            void push(node* value);
            void pop();
            int next() override;
            bool has_next() override;
    };
    Iterator* create_dft_Iterator(node* elem);
    class dft_Iterator : public Iterator 
    {
        private: node* Current;
        public:
            dft_Iterator(node* root)
            {
                stack* elem = new stack;
                elem->key = root;
                elem->Previous = nullptr;
                Head = elem;
            };
            struct stack
            {
                node* key;
                stack* Previous;
            };
            stack* Head;
            void push(node* value);
            void pop();
            int next() override;
            bool has_next() override;
    };
};
#endif