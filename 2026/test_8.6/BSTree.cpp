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

//int main()
//{
//	Key::BSTree<int> tree;
//	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	for (auto x : arr)
//	{
//		tree.Insert(x);
//	}
//	Key::BSTree<int> t = tree;
//	t.InOrder();
//
//	tree.Erase(8);
//	t = tree;
//	t.InOrder();
//
//	return 0;
//}

//int main()
//{
//	KeyValue::BSTree<int,int> tree;
//	
//	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	int i = 0;
//	for (auto x : arr)
//	{
//		//tree.Insert(x, i++);
//		tree.Insert(x, x-1);
//	}
//	
//	tree.InOrder();
//
//	tree.Erase(1);
//	tree.InOrder();
//	cout << endl;
//
//	KeyValue::BSTree<int, int> t = tree;
//	t.InOrder();
//
//	tree.Erase(8);
//	t = tree;
//	t.InOrder();
//
//
//	return 0;
//}


// 应用场景1 --- 字典
//int main()
//{
//	KeyValue::BSTree<string, string> dict;
//	//BSTree<string, string> copy = dict;
//	dict.Insert("left", "左边");
//	dict.Insert("right", "右边");
//	dict.Insert("insert", "插入");
//	dict.Insert("string", "字符串");
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.Find(str);
//		if (ret)
//		{
//			cout << "->" << ret->_value << endl;
//		}
//		else
//		{
//			cout << "无此单词，请重新输入" << endl;
//		}
//	}
//
//	return 0;
//}


// 应用场景2 --- 统计个数
int main()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", 
			"苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" , "Q"};
	KeyValue::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找该水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的结点中水果对应的次数++
		
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
		countTree.InOrder();

		return 0;
	}
