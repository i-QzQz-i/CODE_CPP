#define _CRT_SECURE_NO_WARNINGS 

#include "HashBucket.h"
#include "Unorderedmap.h"
#include "Unorderedset.h"
#include <unordered_map>
#include <unordered_set>

void test_unorder()
{
	unordered_map<int, int> m;

	m.insert({ 1, 1 });
	m.insert({ 1, 11 });
	m.insert({ 1, 111 });
	m.insert({ 2, 2 });
	m.insert({ 2, 22 });
	m.insert({ 3, 3 });
	m.insert({ 4, 4 });
	m.insert({ 5, 0 });
	m.insert({ 12, 0 });
	m.insert({ 17, 0 });
	m.insert({ 110, 0 });
	m.insert({ 1110, 0 });

	for (auto& x : m)
	{
		cout << x.first << ":" << x.second << "  ";
	}
	cout << endl;

	cout << m[0];
}

void test_Unorder()
{
	//std::set<int> s;
	QzQz::Unordered_set<int> s;

	auto ret = s.insert(2);
	//std::cout << ret.first<< std::endl;

	int a[] = { 16, 3, 14, 7, 24, 11, 9, 26, 18, 15 };

	/*for (auto x : a)
	{
		s.insert(x);
	}
	cout << endl;*/

	//auto it = s.begin();
	int i = 0;
	while (i < (sizeof(a) / sizeof(a[0])))
	{
		s.insert(a[i]);
		++i;
	}
	//s.Print();

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << *s.find(3) << endl;
}


int main()
{
	//test_unorder();

	test_Unorder();


	return 0;
}