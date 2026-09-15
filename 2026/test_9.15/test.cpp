#define _CRT_SECURE_NO_WARNINGS 

#include "RBTree.h"

void Test1()
{
	RBTree<int, int> t;

	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	for (auto e : a)
	{
		t.Insert({ e, e });
	}
	t.InOrder();
	cout << endl;

	cout << "¸ß¶È£º" << t.Height() << endl;

}

int main()
{
	Test1();

	return 0;
}