#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <assert.h>

using namespace std;

namespace QzQz
{
	template<class V>
	struct HashData
	{
		V _kv;
		HashData<V>* _next;

		HashData(const V& kv)
			:_kv(kv)
			, _next(nullptr)
		{
		}
	};

	template<class V>
	struct HashBucket
	{
		size_t _size = 0;
		HashData<V>* _data = nullptr;
	};

	template<class V, class Ref, class Ptr, class KeyOfT, class Hash>
	struct HashIterator
	{
		typedef HashData<V> Data;
		typedef HashBucket<V> Node;
		typedef vector<Node> Table;
		typedef HashIterator<V, Ref, Ptr, KeyOfT, Hash> Self;

		Data* _data;
		Table* _t;

		HashIterator(Data* data, Table* tables)
			:_data(data)
			, _t(tables)
		{
		}

		// ++
		Self& operator++()
		{
			if (_data->_next)
			{
				_data = _data->_next;
			}
			else
			{
				Hash hf;
				KeyOfT KofT;
				size_t size = (*_t).size();
				size_t hash = hf(KofT(_data->_kv)) % size;
				size_t i = 1;
				Node* cur = nullptr;
		
				while (size > hash + i)
				{
					cur = &((*_t)[hash + i]);
					if (cur->_data == nullptr)
					{
						++i;
					}
					else
					{
						break;
					}
				}

				if (size > hash + i)
				{
					_data = cur->_data;
				}
				else
				{
					_data = nullptr;
				}
			}
			
			return *this;
		}

		// forword itertor 无--

		bool operator==(const Self& tmp) const
		{
			return _data == tmp._data;
		}

		bool operator!=(const Self& tmp) const
		{
			return _data != tmp._data;
		}

		Ref operator*()
		{
			return _data->_kv;
		}

		Ptr operator->()
		{
			return &_data->_kv;
		}
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& key)
		{
			size_t ret = 0;
			auto it = key.begin();
			while (it != key.end())
			{
				ret *= 131;
				ret += *it;
				it++;
			}

			return ret;
		}
	};

	template<class K, class V, class KeyOfT, class Compare = less<K>, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		typedef HashBucket<V> Node;
		//因为不知道 HashTable<>::Iterator 是变量还是类型，需加typename表明他是类型
		typedef typename HashIterator<V, V&, V*, KeyOfT, Hash> Iterator;
		typedef const HashIterator<V, const V&, const V*, KeyOfT, Hash> Const_Iterator;

		HashTable()
		{
			_tables.resize(11);
		}

		HashTable(size_t size)
		{
			_tables.resize(size);
		}

		Iterator Begin()
		{
			if (_n == 0)
			{
				return { nullptr, &_tables };
			}

			for (size_t i = 0; i < _tables.size(); i++)
			{
				HashData<V>* cur = _tables[i]._data;
				if (cur)
				{
					return Iterator(cur, &_tables);
				}
			}
				
			assert("Begin error !");
		}

		Iterator End()
		{
			return Iterator(nullptr, &_tables);
		}

		Const_Iterator Begin() const
		{
			if (_n == 0)
			{
				return { nullptr, &_tables };
			}

			for (size_t i = 0; i < _tables.size(); i++)
			{
				HashData<V>* cur = _tables[i]._data;
				if (cur)
				{
					return Const_Iterator(cur, &_tables);
				}
			}

			assert("Begin error !");
		}

		Const_Iterator End() const
		{
			return { nullptr, &_tables };
		}

		pair<Iterator, bool> Insert(const V& kv)
		{
			KeyOfT KofT;

			// 查找
			Iterator f = Find(KofT(kv));

			if (f._data != nullptr)
			{
				return { f, false };
			}

			Hash hf;
			

			if (_n * 10 / _tables.size() >= 7)
			{
				vector<Node> tmp(_tables.size() * 2);

				// 错误的只算每个桶的第一个值的哈希值，就直接把整个桶直接给到新桶中
				//for (int i = 0; i < _tables.size(); i++)
				//{
				//	HashData<V>* cur = _tables[i]._data;
				//	if (cur)
				//	{
				//		size_t hash = hf(KofT(cur->_kv)) % (_tables.size() * 2);
				//		// 扩容后，不同的桶的值可能映射到同一个桶中
				//		
				//		HashData<V>* next = tmp[hash]._data;
				//		if (next)
				//		{
				//			while (next->_next)
				//			{
				//				next = next->_next;
				//			}
				//			next->_next = _tables[i]._data;
				//			tmp[hash]._size += _tables[i]._size;
				//		}
				//		else
				//		{
				//			tmp[hash]._data = _tables[i]._data;
				//			tmp[hash]._size = _tables[i]._size;
				//		}
				//	}
				//}


				// 所以不能偷懒，每个值都要重新映射 （图书馆关门了，明天改）

				_tables.swap(tmp);
			}

			// 哈希函数运算
			size_t hash = hf(KofT(kv)) % _tables.size();

			// 开始插入
			HashData<V>* cur = _tables[hash]._data;
			HashData<V>* ret = new HashData<V>(kv);
			if (cur)
			{
				while (cur->_next)
				{
					cur = cur->_next;
				}
				cur->_next = ret;
			}
			else
			{
				_tables[hash]._data = ret;
			}

			++_tables[hash]._size;
			++_n;

			return { { ret, &_tables } , true };
		}

		Iterator Find(const K& key)
		{
			Hash hf;
			KeyOfT KofT;
			size_t hash = hf(KofT(key)) % _tables.size();
			HashData<V>* cur = _tables[hash]._data;

			if (cur)
			{
				while (cur)
				{
					if (KofT(cur->_kv) == key)
					{
						return { cur,  &_tables };
					}

					cur = cur->_next;
				}
			}

			return { nullptr, &_tables };
		}

		bool Erase(const K& key)
		{
			HashData<V>* cur = Find(key);
			if (cur == nullptr)
			{
				return false;
			}

			Hash hf;
			KeyOfT KofT;
			size_t hash = hf(KofT(key)) % _tables.size();
			HashData<V>* prev = _tables[hash]._data;

			while (prev->_next != cur)
			{
				prev = prev->_next;
			}
		
			prev->_next = cur->_next;
			--_n;
			delete cur;

			return true;
		}

	private:
		vector<Node>& Get_Table()
		{
			return _tables;
		}

		/*Node* Find_Head(const V& kv)
		{
			Hash hf;
			KeyOfT KofT;
			size_t hash = hf(KofT(key)) % _tables.size();
			HashData<V>* cur = _tables[hash]._data;

			return cur;
		}*/

	private:
		vector<Node> _tables;
		size_t _n = 0; // 表中数据总个数
	};
}
