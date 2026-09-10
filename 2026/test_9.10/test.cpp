#define _CRT_SECURE_NO_WARNINGS 

#include "AVL_Tree.h"

int main()
{
	AVLTree<int, int> t;

	int a[] = { 16, 3, 2 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	for (auto e : a)
	{
		t.Insert({ e, e });
	}
	t.InOrder();
	//cout << t.IsBalanceTree() << endl;

	return 0;
}