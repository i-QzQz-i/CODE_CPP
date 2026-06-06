#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void test_stack()
{
	/*stack<int> st;
	cout << st.size() << endl;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.size() << endl;

	st.pop();
	cout << st.top() << endl;*/

	vector<int> v(6, 1);
	vector<int> v1 = { 1,2,3,4 };

	stack<int, vector<int>> st1(v);

	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	cout << st1.size() << endl;

	//st1.push(v);
	//st1.pop();
}

void test_queue()
{
	int arr[5] = { 1,2,3,4,5 };
	//queue<int*> qu(&arr[4]);
	//stack<int*> st;
	queue<int*> qu;
	
	qu.push(&arr[0]);
	qu.push(&arr[1]);
	qu.push(&arr[2]);
	qu.push(&arr[3]);
	cout << qu.size() << endl;

	//qu.pop();
	cout << qu.front() << endl;

	vector<int> v(6, 1);
	vector<int> v1 = { 1,2,3,4 };

	queue<int, vector<int>> qu1(v);

	for (int x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	cout << qu1.size() << endl;

	//qu1.push(&v1);
}

int main()
{
	//test_stack();

	test_queue();

	return 0;
}