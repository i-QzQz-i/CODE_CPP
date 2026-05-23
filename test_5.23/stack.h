#define _CRT_SECURE_NO_WARNINGS 

namespace QzQz
{
	template< class T, class Container = std::deque<T> >
	class stack
	{
	public:
		stack()
		{}

		void push(const T& x)
		{
			con.push_back(x);
		}
		
		void pop()
		{
			con.pop_back();
		}

		size_t size()
		{
			return con.size();
		}

		bool empty() const
		{
			return con.empty();
		}

		T& top()
		{
			return con.back();
		}

		void swap(stack& tmp)
		{
			std::swap(tmp.con, con);
		}

	private:
		Container con;
	};

	void test_stack1()
	{
		stack<int, std::vector<int>> st;
		st.push(0);
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		std::cout << st.size() << std::endl;
		std::cout << st.top() << std::endl;

		st.pop();
		std::cout << st.top() << std::endl;

		while (!st.empty())
		{
			std::cout << st.top() << "  ";
			st.pop();
		}
		std::cout << std::endl;

		std::cout << st.size() << std::endl;
	}

	void test_stack2()
	{
		stack<int> st1;
		st1.push(0);
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);
		st1.push(5);
		std::cout << st1.size() << std::endl;

		stack<int> st2;
		
		st1.swap(st2);
		std::cout << st1.size() << std::endl;
	}
}