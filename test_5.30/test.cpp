#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <queue>
#include "priority_queue.h"
using namespace std;

int main()
{
	QzQz::priority_queue<int, vector<int>, QzQz::Less<int>> pq;
	pq.push(3);
	pq.push(2);
	pq.push(5);
	pq.push(1);
	pq.push(6);
	pq.push(9);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	// cout << pq.top() << endl;

	//pq.pop();

	//cout << pq.top() << endl;


	return 0;
}