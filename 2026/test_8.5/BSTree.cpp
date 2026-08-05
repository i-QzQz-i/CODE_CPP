#define _CRT_SECURE_NO_WARNINGS 

#include "BSTree.h"
// using namespace;

//int main()
//{
//	const int a = 1;
//	Key::BSTree<int> tree;
//	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	for (auto x : arr)
//	{
//		tree.Insert(x);
//	}
//	//tree.InOrder();
//
//	/*if (tree.Find(1))
//	{
//		cout << "ture" << endl;
//	}
//	else
//	{
//		cout << "false" << endl;
//	}*/
//
//	//cout << tree.Find(8)->_date << endl;
//	/*tree.Erase(1);
//	tree.InOrder();
//	tree.Erase(3);
//	tree.InOrder();*/
//
//	for (int i = 0;i < sizeof(arr)/sizeof(int);i++)
//	{
//		tree.InOrder();
//		tree.Erase(arr[i]);
//	}
//	
//
//	return 0;
//}

int main()
{
	Key::BSTree<int> tree;
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto x : arr)
	{
		tree.Insert(x);
	}
	Key::BSTree<int> t = tree;
	t.InOrder();

	tree.Erase(8);
	t = tree;
	t.InOrder();

	return 0;
}