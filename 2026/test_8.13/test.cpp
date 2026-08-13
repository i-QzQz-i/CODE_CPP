#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <set>
#include <map>
using namespace std;

//int main()
//{
//	set<int> s;
//
//	s.insert(1);
//	//s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(0);
//
//	for (const auto& x : s)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	s.insert({ 5,2,6 });
//
//	auto i = s.begin();
//	while (i != s.end())
//	{
//		cout << *i << ' ';
//		i++;
//	}
//	cout << endl;
//
//	/*cout << s.size() << endl;
//
//	auto x = s.find(3);
//
//	cout << *x << endl;*/
//
//	//s.clear();
//
//	auto x = s.find(3);
//	s.erase(s.begin(), x);
//
//	for (const auto& x : s)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	cout << *(s.begin());
//
//	return 0;
//}

//int main()
//{
//	multiset<int> s;
//
//	s.insert(1);
//	//s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(0);
//
//	for (const auto& x : s)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	s.insert({ 3,2,2,1 });
//
//	auto i = s.begin();
//	while (i != s.end())
//	{
//		cout << *i << ' ';
//		i++;
//	}
//	cout << endl;
//
//	cout << s.count(67) << endl;
//	
//	cout << "[ " << *s.lower_bound(1) << ", " << *s.upper_bound(3) << " )" << endl;
//
//	/*s.erase(s.lower_bound(1), s.upper_bound(3));
//	for (const auto& x : s)
//	{
//		cout << x << " ";
//	}
//	cout << endl;*/
//
//	auto ret = s.equal_range(3);
//	cout << "[ " << *ret.first << ", " << *ret.second << " )" << endl;
//
//	s.erase(ret.first, ret.second);
//	for (const auto& x : s)
//	{
//		cout << x << " ";
//	}
//	cout << endl; 
//
//	return 0;
//}

int main()
{
	//multimap<int,int> m;

	map<string,int> m;

	//m.insert("a", 1);
	m.insert({ "a", 1 });
	m.insert({ "b", 2 });
	m.insert({ "c", 3 });
	m.insert({ "d", 4 });
	m.insert({ "e", 0 });

	for (const auto& x : m)
	{
		cout << x.first << ":" << x.second << " ";
	}
	cout << endl;

	

	auto i = m.begin();
	while (i != m.end())
	{
		cout << (*i).first << ' ';
		i++;
	}
	cout << endl;

	//cout << m.count(67) << endl;

	//cout << "[ " << *m.lower_bound(1) << ", " << *m.upper_bound(3) << " )" << endl;

	
	/*auto ret = s.equal_range(3);
	cout << "[ " << *ret.first << ", " << *ret.second << " )" << endl;

	s.erase(ret.first, ret.second);
	for (const auto& x : s)
	{
		cout << x << " ";
	}
	cout << endl;*/

	return 0;
}