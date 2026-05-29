#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <queue>
#include "priority_queue.h"
using namespace std;

int main()
{
	QzQz::priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);

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