#include <iostream>
#include <ctime>
#include "ClassTree.h"
#include "iterator.h"
using namespace std;
void BinarySearchTree::PrivateInsert(int value, node** temp)
{
	if ((*temp) == NULL)
	{
		(*temp) = new node;
		(*temp)->info = value;
		(*temp)->LeftBranch = 0;
		(*temp)->RightBranch = 0;
		return;
	}
	if (value > (*temp)->info) PrivateInsert(value, &(*temp)->RightBranch);
	else PrivateInsert(value, &(*temp)->LeftBranch);
}
	void BinarySearchTree::insert(int value)
	{
		PrivateInsert(value, &Root);
	}
	void BinarySearchTree::PrintTree(node* temp)
	{
		if (temp == 0) return;
		ValueOutputLevel++;
		PrintTree(temp->LeftBranch);
		for (int i = 0; i < ValueOutputLevel; ++i) cout << " ";
		cout << temp->info << endl;
		PrintTree(temp->RightBranch);
		ValueOutputLevel--;
		return;
	}
	bool BinarySearchTree::contains(int value)
	{
		node* pointer = Root;
		while (pointer != nullptr && pointer->info != value)
		{
			if (pointer->info > value) pointer = pointer->LeftBranch;
			else pointer = pointer->RightBranch;
		}
		return pointer != nullptr;
	}
	node* BinarySearchTree::remove(node* node2, int value)
	{
		if (Root == NULL) throw invalid_argument("BinarySearchTree is empty");
		if (!contains(value)) throw invalid_argument("This element not found");
		if (node2 == NULL) return node2;
		if (value == node2->info)
		{
			node* temp;
			if (node2->RightBranch == NULL)
				temp = node2->LeftBranch;
			else 
			{
				node* pointer = node2->RightBranch;
				if (pointer->LeftBranch == NULL)
				{
					pointer->LeftBranch = node2->LeftBranch;
					temp = pointer;
				}
				else {
					node* min = pointer->LeftBranch;
					while (min->LeftBranch != NULL)
					{
						pointer = min;
						min = pointer->LeftBranch;
					}
					pointer->LeftBranch = min->RightBranch;
					min->LeftBranch = node2->LeftBranch;
					min->RightBranch = node2->RightBranch;
					temp = min;
				}
			}
			delete node2;
			return temp;
		}
		else if (value < node2->info) node2->LeftBranch = remove(node2->LeftBranch, value);
		else node2->RightBranch = remove(node2->RightBranch, value);
		return node2;
	}

  void BinarySearchTree::bft_Iterator::push(node* value)
  {
	  turn* element = new turn;
	  element->key = value;
	  element->next = nullptr;
	  if (Head == nullptr)
	  {
		  Head = element;
		  Head->next = nullptr;
		  Last = element;
	  }
	  else 
	  {
		  Last->next = element;
		  Last = Last->next;
	  }
  }
  void BinarySearchTree::bft_Iterator::pop()
  {
	  turn* pointer = Head->next;
	  Head->next = nullptr;
	  delete Head;
	  Head = pointer;
  }
  int BinarySearchTree::bft_Iterator::next()
  {
	  Current = Head->key;
	  int temp = Head->key->info;
	  pop();
	  if (Current->RightBranch)push(Current->LeftBranch);
	  if (Current->RightBranch)push(Current->RightBranch);
	  return temp;
  }
  bool BinarySearchTree::bft_Iterator::has_next()
  {
	  return Head != nullptr;
  }
  Iterator* BinarySearchTree::create_bft_Iterator(node* elem)
  {
	  return new bft_Iterator(elem);
  }

  void BinarySearchTree::dft_Iterator::push(node* value)
  {
	  stack* elem = new stack;
	  elem->key = value;
	  if (Head == nullptr)
	  {
		  Head = elem;
		  Head->Previous = nullptr;
	  }
	  else 
	  {
		  elem->Previous = Head;
		  Head = elem;
	  }
  }
  void BinarySearchTree::dft_Iterator::pop()
  {
	  stack* pointer = Head;
	  node* temp = Head->key;
	  Head = pointer->Previous;
	  pointer->Previous = nullptr;
	  delete pointer;
  }
  bool BinarySearchTree::dft_Iterator::has_next()
  {
	  return Head != nullptr;
  }
  int BinarySearchTree::dft_Iterator::next()
  {
	  int temp;
	  Current = Head->key;
	  temp = Head->key->info;
	  pop();
	  if (Current->RightBranch) push(Current->RightBranch);
	  if (Current->LeftBranch) push(Current->LeftBranch);
	  return temp;
  }
  Iterator* BinarySearchTree::create_dft_Iterator(node* elem)
  {
	  return new dft_Iterator(elem);
  }
int main()
{
	BinarySearchTree berezka;
	srand(time(0));
	int array[10];
	for (int i = 0; i < 10; ++i)
	{
		array[i] = rand() % 10;
		berezka.insert(array[i]);
	}
	berezka.PrintTree(berezka.Root);
	berezka.contains(array[6]);
	berezka.remove(berezka.Root, array[5]);
	berezka.PrintTree(berezka.Root);
	Iterator* elem = berezka.create_bft_Iterator(berezka.Root);
	Iterator* elem2 = berezka.create_dft_Iterator(berezka.Root);
	return 0;
}