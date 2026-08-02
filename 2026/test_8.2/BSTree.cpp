#define _CRT_SECURE_NO_WARNINGS 

#include "BSTree.h"
// using namespace;

int main()
{
	const int a = 1;
	BSTree<int> tree(1);
	int arr[3] = { 5,4,2 };
	for (auto x : arr)
	{
		tree.Insert(x);
	}
	tree.InOrder();

	if (tree.Find(1))
	{
		cout << "ture" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}