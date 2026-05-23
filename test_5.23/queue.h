#define _CRT_SECURE_NO_WARNINGS 

namespace QzQz
{
	template< class T, class Container = std::deque<T> >
	class queue
	{
	public:
		queue()
		{}

		void push(const T& x)
		{
			con.push_back(x);
		}

		void pop()
		{
			con.pop_front();
		}

		size_t size()
		{
			return con.size();
		}

		bool empty()
		{
			return con.empty();
		}

		T& top()
		{
			return con.front();
		}

		void swap(queue& tmp)
		{
			std::swap(tmp.con, con);
		}

	private:
		Container con;
	};

	void test_queue1()
	{
		queue<int, std::list<int>> qu;
		qu.push(0);
		qu.push(1);
		qu.push(2);
		qu.push(3);
		qu.push(4);
		qu.push(5);
		std::cout << qu.size() << std::endl;
		std::cout << qu.top() << std::endl;

		qu.pop();
		std::cout << qu.top() << std::endl;

		while (!qu.empty())
		{
			std::cout << qu.top() << "  ";
			qu.pop();
		}
		std::cout << std::endl;

		std::cout << qu.size() << std::endl;
	}

	void test_queue2()
	{
		queue<int> qu1;
		qu1.push(0);
		qu1.push(1);
		qu1.push(2);
		qu1.push(3);
		qu1.push(4);
		qu1.push(5);
		std::cout << qu1.top() << std::endl;
		std::cout << qu1.size() << std::endl;

		queue<int> qu2;

		qu1.swap(qu2);
		std::cout << qu1.size() << std::endl;
		//std::cout << qu1.top() << std::endl;
	}
}
