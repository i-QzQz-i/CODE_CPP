#define _CRT_SECURE_NO_WARNINGS 

// 优先级队列（其实就是堆）
// 主要是建堆，并实现仿函数
// 堆节点的关系：
// 亲找子：p * 2 + 1 \ p * 2 + 2
// 子找亲：(c - 1) / 2

namespace QzQz
{
	template<class T, class Container = vector<T>, class Compare = Less<T>>
	//template<class T, class Container = vector<T>, class Compare = >
	class priority_queue
	{

	public:
		priority_queue()
		{ }
	
		~priority_queue()
		{ }

		void AdjustDown(size_t parent)
		{
			Compare f;
	
			size_t child = parent * 2 + 1;

			while (child < size())
			{
				if (child + 1 < _con.size() && f(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (f(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustUp(size_t child)
		{
			Compare f;

			int parent = (child - 1) / 2;

			while (parent >= 0)
			{
				if (f(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

		const T& top() const
		{
			return _con[0];
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		
	private:
		Container _con;
	};

	// 仿函数（像函数一样调用）
	template<class T>
	class Less
	{
	public:
		bool operator()(const T& A, const T& B)
		{
			return A < B;
		}
	};

	template<class T>
	class Greater
	{
	public:
		bool operator()(const T& A, const T& B)
		{
			return A > B;
		}
	};
}