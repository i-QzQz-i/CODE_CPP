#define _CRT_SECURE_NO_WARNINGS 

// 双向带头循环链表（双向链表）
#include <iostream>
#include <list>
using namespace std;

void test_list1()
{
	list<int> lt(10, 1);
	cout << lt.size() << endl;
	
	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << "  ";
		++it;
	}
	cout << endl;

	list<int> lt1(20);
	//list<int> lt1;

	cout << lt1.size() << endl;

	if (!lt1.empty())
	{
		for (auto x : lt1)
		{
			cout << x << "  ";
		}
		cout << endl;
	}
	

	/*lt1 = lt;
	cout << lt1.size() << endl;

	for (auto x : lt1)
	{
		cout << x << "  ";
	}
	cout << endl;*/

	cout << lt.max_size() << "  " << lt1.max_size() << endl;
}

void test_list2()
{
	list<char> lt(6, 'x');

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	lt.push_front('a');
	lt.push_back('z');

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	cout << lt.front() << endl;
	cout << lt.back() << endl;

	lt.front() = '1';
	lt.back() = '0';

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	lt.pop_front();
	lt.pop_back();

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;
}

void test_list3()
{
	list<double> lt(10, 1.1);

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	lt.emplace_back(1.2);
	lt.emplace_front(1.2);
	
	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	lt.insert(lt.begin(), 6.6);
	lt.insert(lt.end(), 5.5);

	lt.sort();
	/*double x = 0;
	cin >> x;
	list<double>::iterator it = find(lt.begin(), lt.end(), x);
	lt.insert(it, 4.4);*/

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	cout << lt.size() << endl;
	//lt.clear();
	lt.erase(++lt.begin(), --lt.end());

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;
	cout << lt.size() << endl;

	lt.resize(10, 9.9);
	//lt.resize(1);

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl;

	list<double> lt1(3, 3.3);

	for (auto x : lt1)
	{
		cout << x << "  ";
	}
	cout << endl;
}

int main()
{
	//test_list1();

	//test_list2();

	test_list3();


	return 0;
}