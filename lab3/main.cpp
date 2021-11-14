#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;
struct tree
{
	int info;
	tree* LeftBranch;
	tree* RightBranch;
};
struct TurnNode
{
	tree* trans;
	TurnNode* next;
};
class Turn
{
private: TurnNode* Head;
public:
	Turn()
	{
		Head = NULL;
	}
	int isEmpty()
	{
		if (Head == NULL) return 1;
		else return 0;
	}
	void AddTurn(tree* tmp)
	{
		TurnNode* Ptr = new TurnNode;
		Ptr->trans = tmp;
		if (Head == NULL)
		{
			Head = Ptr;
			Ptr->next = NULL;
		}
		else
		{
			TurnNode* tmp_c = Head;
			while (tmp_c->next != NULL)
			tmp_c = tmp_c->next;
			tmp_c->next = Ptr;
			Ptr->next = NULL;
		}
	}
	tree* DeleteTurn()
	{
		TurnNode* cur = Head->next;
		tree* tmp_c = Head->trans;
		if (Head != NULL)
		{
			delete Head;
			Head = cur;
			return tmp_c;
		}
		else return NULL;
	}
};
	int u;
	tree* Root = 0;
	void TreeAss::insert(int element, tree **t)
	{
		if ((*t) == NULL)
		{
			(*t) = new tree;
			(*t)->info = element;
			(*t)->LeftBranch = 0;
			(*t)->RightBranch = 0;
			return;
		}
		if (element > (*t)->info) insert(element, &(*t)->RightBranch);
		else insert(element, &(*t)->LeftBranch);
	}
	void TreeAss::PrintTree(tree* t)
	{
		/*cout << endl;
		if (t)
		{
			PrintTree(t->LeftBranch, level + 1);
			for (int i = 0; i < level; i++) cout << "   ";
			cout << t->info << endl;
			PrintTree(t->RightBranch, level + 1);
		}*/
		if (t == 0) return;
		u++;
		PrintTree(t->LeftBranch);
		for (int i = 0; i < u; ++i) cout << " ";
		cout << t->info << endl;
		PrintTree(t->RightBranch);
		u--;
		return;
	}
	tree* TreeAss::contains(tree* r, int d)
	{
		if (r == NULL)
		{
			return NULL;  // не найден
		}
		if (r->info == d) return r; // нашли!!!
		if (d <= r->info)
		{
			// left
			if (r->LeftBranch != NULL) return contains(r->LeftBranch, d); // рекурсивный поиск влево
			else return NULL; // не найден
		}
		else
		{
			//right
			if (r->RightBranch) return contains(r->RightBranch, d);// рекурсивный поиск вправо
			else return NULL; // не найден
		}
	}
	tree* TreeAss::remove(tree* node, int val)
	{
		if (node == NULL) return node;
		if (val == node->info)
		{
			tree* tmp;
			if (node->RightBranch == NULL)
				tmp = node->LeftBranch;
			else 
			{
				tree* ptr = node->RightBranch;
				if (ptr->LeftBranch == NULL) 
				{
					ptr->LeftBranch = node->LeftBranch;
					tmp = ptr;
				}
				else {
					tree* pmin = ptr->LeftBranch;
					while (pmin->LeftBranch != NULL)
					{
						ptr = pmin;
						pmin = ptr->LeftBranch;
					}
					ptr->LeftBranch = pmin->RightBranch;
					pmin->LeftBranch = node->LeftBranch;
					pmin->RightBranch = node->RightBranch;
					tmp = pmin;
				}
			}
			delete node;
			return tmp;
		}
		else if (val < node->info)
			node->LeftBranch = remove(node->LeftBranch, val);
		else
			node->RightBranch = remove(node->RightBranch, val);
		return node;
	}
	void TreeAss::depthfirsttraverse(tree* root) {
		if (root) 
		{
			depthfirsttraverse(root->LeftBranch);
			depthfirsttraverse(root->RightBranch);
			printf("%d ", root->info);
		}
	}
	void TreeAss::breadthfirsttraverse()
	{
		Turn Universal;
		Universal.AddTurn(Root);
		tree* tmp;
		while (!Universal.isEmpty())
		{
			tmp = Universal.DeleteTurn();
			cout << tmp->info << " ";
			if (tmp->LeftBranch != NULL) Universal.AddTurn(tmp->LeftBranch);
			if (tmp->RightBranch != NULL) Universal.AddTurn(tmp->RightBranch);
		}
	}

int main()
{
	TreeAss berezka;
	int RandNum, n = 5, b;
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		RandNum = rand() % 10;
		if (i == 2) b = RandNum;
		cout << RandNum << " ";
		berezka.insert(RandNum, &berezka.Root);
	}
	cout << endl;
	berezka.PrintTree(berezka.Root);
	cout << endl;
	//berezka.contains(berezka.Root, 21);
	//berezka.remove(berezka.Root, b);
	//berezka.depthfirsttraverse(berezka.Root);
	berezka.breadthfirsttraverse();
	return 0;
}