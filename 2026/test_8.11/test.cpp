#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	set<int> s;

	s.insert(1);
	//s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(0);

	for (const auto& x : s)
	{
		cout << x << " ";
	}
	cout << endl;

	s.insert({ 5,2,6 });

	auto i = s.begin();
	while (i != s.end())
	{
		cout << *i << ' ';
		i++;
	}
	cout << endl;

	/*cout << s.size() << endl;

	auto x = s.find(3);

	cout << *x << endl;*/

	//s.clear();

	auto x = s.find(3);
	s.erase(s.begin(), x);

	for (const auto& x : s)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << *(s.begin());

	return 0;
}