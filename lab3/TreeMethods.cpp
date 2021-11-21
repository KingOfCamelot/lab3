#include <iostream>
#include <ctime>
#include "ClassTree.h"
#include "iterator.h"
using namespace std;
	void Tree::insert(int element, node**t)
	{
		if ((*t) == NULL)
		{
			(*t) = new node;
			(*t)->info = element;
			(*t)->LeftBranch = 0;
			(*t)->RightBranch = 0;
			return;
		}
		if (element > (*t)->info) insert(element, &(*t)->RightBranch);
		else insert(element, &(*t)->LeftBranch);
	}
	void Tree::PrintTree(node* t)
	{
		if (t == 0) return;
		u++;
		PrintTree(t->LeftBranch);
		for (int i = 0; i < u; ++i) cout << " ";
		cout << t->info << endl;
		PrintTree(t->RightBranch);
		u--;
		return;
	}
	bool Tree::contains(int value)
	{
		node* tmp_ptr = Root;
		while (tmp_ptr != nullptr && tmp_ptr->info != value) 
		{
			if (tmp_ptr->info > value) tmp_ptr = tmp_ptr->LeftBranch;
			else tmp_ptr = tmp_ptr->RightBranch;
		}
		return tmp_ptr != nullptr;
	}
	node* Tree::remove(node* node2, int val)
	{
		if (Root == NULL) throw invalid_argument("Tree is empty");
		if (!contains(val)) throw invalid_argument("This element not found");
		if (node2 == NULL) return node2;
		if (val == node2->info)
		{
			node* tmp;
			if (node2->RightBranch == NULL)
				tmp = node2->LeftBranch;
			else 
			{
				node* ptr = node2->RightBranch;
				if (ptr->LeftBranch == NULL) 
				{
					ptr->LeftBranch = node2->LeftBranch;
					tmp = ptr;
				}
				else {
					node* pmin = ptr->LeftBranch;
					while (pmin->LeftBranch != NULL)
					{
						ptr = pmin;
						pmin = ptr->LeftBranch;
					}
					ptr->LeftBranch = pmin->RightBranch;
					pmin->LeftBranch = node2->LeftBranch;
					pmin->RightBranch = node2->RightBranch;
					tmp = pmin;
				}
			}
			delete node2;
			return tmp;
		}
		else if (val < node2->info) node2->LeftBranch = remove(node2->LeftBranch, val);
		else node2->RightBranch = remove(node2->RightBranch, val);
		return node2;
	}

  void Tree::bft_Iterator::push(node* value)
  {
	  turn* elem = new turn;
	  elem->key = value;
	  elem->next = nullptr;
	  if (headq == nullptr) 
	  {
		  headq = elem;
		  headq->next = nullptr;
		  last = elem;
	  }
	  else 
	  {
		  last->next = elem;
		  last = last->next;
	  }
  }
  void Tree::bft_Iterator::pop()
  {
	  turn* tmp_ptr = headq->next;
	  headq->next = nullptr;
	  delete headq;
	  headq = tmp_ptr;
  }
  int Tree::bft_Iterator::next()
  {
	  curr = headq->key;
	  int rmbr_elem = headq->key->info;
	  pop();
	  if (curr->RightBranch)push(curr->LeftBranch);
	  if (curr->RightBranch)push(curr->RightBranch);
	  return rmbr_elem;
  }
  bool Tree::bft_Iterator::has_next()
  {
	  return headq != nullptr;
  }
  Iterator* Tree::create_bft_Iterator(node* elem)
  {
	  return new bft_Iterator(elem);
  }

  void Tree::dft_Iterator::push(node* value)
  {
	  stack* elem = new stack;
	  elem->key = value;
	  if (top == nullptr) 
	  {
		  top = elem;
		  top->prev = nullptr;
	  }
	  else 
	  {
		  elem->prev = top;
		  top = elem;
	  }
  }
  void Tree::dft_Iterator::pop()
  {
	  stack* tmp_ptr = top;
	  node* rmbr_key = top->key;
	  top = tmp_ptr->prev;
	  tmp_ptr->prev = nullptr;
	  delete tmp_ptr;
  }
  bool Tree::dft_Iterator::has_next()
  {
	  return top != nullptr;
  }
  int Tree::dft_Iterator::next()
  {
	  int rmbr_elem;
	  curr = top->key;
	  rmbr_elem = top->key->info;
	  pop();
	  if (curr->RightBranch) push(curr->RightBranch);
	  if (curr->LeftBranch) push(curr->LeftBranch);
	  return rmbr_elem;
  }
  Iterator* Tree::create_dft_Iterator(node* elem)
  {
	  return new dft_Iterator(elem);
  }
int main()
{
	Tree berezka;
	srand(time(0));
	int array[10];
	for (int i = 0; i < 10; ++i)
	{
		array[i] = rand() % 10;
		berezka.insert(array[i], &berezka.Root);
	}
	berezka.PrintTree(berezka.Root);
	berezka.contains(array[6]);
	berezka.remove(berezka.Root, array[5]);
	berezka.PrintTree(berezka.Root);
	Iterator* elem = berezka.create_bft_Iterator(berezka.Root);
	Iterator* elem2 = berezka.create_dft_Iterator(berezka.Root);
	return 0;
}