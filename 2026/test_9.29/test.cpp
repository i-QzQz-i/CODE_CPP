#define _CRT_SECURE_NO_WARNINGS 

#include "HashTable.h"
#include "unordered_map"
#include "unordered_set"
#include "map"
#include "set"

void using_unorder()
{
	unordered_set<int> us;
	set<int> s;

	us.insert({ 5,2,6,4,22,33,66,0 });
	s.insert({ 5,2,6,4,22,33,66,0 });

	for (auto x : us)
	{
		cout << x << " ";
	}
	cout << endl;

	for (auto x : s)
	{
		cout << x << " ";
	}
	cout << endl;
}

void test_open()
{
	/*QzQz::HashTable_open<int, int> m;

	m.Insert({ 1, 1 });
	m.Insert({ 2, 2 });
	m.Insert({ 3, 3 });
	m.Insert({ 4, 4 });
	m.Insert({ 5, 0 });
	m.Insert({ 12, 0 });
	m.Insert({ 17, 0 });
	m.Insert({ 110, 0 });
	m.Insert({ 1110, 0 });

	for (auto x : m.Get_Table())
	{
		cout << x._kv.first << ":" << x._kv.second;
		cout << endl;
	}*/

	QzQz::HashTable_open<string, int> m;

	m.Insert({ "a", 1 });
	m.Insert({ "b", 2 });
	m.Insert({ "c", 3 });
	m.Insert({ "d", 4 });
	m.Insert({ "e", 0 });
	cout << endl;

	for (auto x : m.Get_Table())
	{
		cout << x._kv.first << ":" << x._kv.second;
		cout << endl;
	}
}

void test_link()
{
	hash_bucket::HashTable_link<int, int> m;

	m.Insert({ 1, 1 });
	m.Insert({ 1, 11 });
	m.Insert({ 1, 111 });
	m.Insert({ 2, 2 });
	m.Insert({ 2, 22 });
	m.Insert({ 3, 3 });
	m.Insert({ 4, 4 });
	m.Insert({ 5, 0 });
	m.Insert({ 12, 0 });
	m.Insert({ 17, 0 });
	m.Insert({ 110, 0 });
	m.Insert({ 1110, 0 });


}

int main()
{
	//using_unorder();

	//test_open();

	test_link();

	return 0;
}


