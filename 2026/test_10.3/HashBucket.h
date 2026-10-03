#pragma once

#include <iostream>
#include <vector>
#include <list>

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

	template<class data, class Ref, class Ptr>
	struct HashIterator
	{
		typedef HashData<data> Node;
		typedef HashBucket<data> Bucket;
		typedef HashIterator<data, Ref, Ptr> Self;

		Node* _node;
		Bucket* _bk;

		HashIterator(Node* node, Bucket* bk)
			:_node(node)
			, _bk(bk)
		{
		}

		// ++
		Self& operator++()
		{
			
			return *this;
		}

		// --
		Self& operator--()
		{

			return *this;
		}

		bool operator==(const Self& tmp) const
		{
			return _node == tmp._node;
		}

		bool operator!=(const Self& tmp) const
		{
			return _node != tmp._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
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
		typedef typename HashIterator<V, V&, V*> Iterator;
		typedef const HashIterator<V, const V&, const V*> Const_Iterator;

		HashTable()
		{
			_tables.resize(11);
		}

		HashTable(size_t size)
		{
			_tables.resize(size);
		}

		pair<Iterator, bool> Insert(const V& kv)
		{
			KeyOfT KofT;

			// 查找
			Iterator f = Find(KofT(kv))
			if (f)
			{
				return { {f, } , false};
			}

			Hash hf;
			

			if (_n * 10 / _tables.size() >= 7)
			{
				vector<Node> tmp(_tables.size() * 2);
				for (int i = 0; i < _tables.size(); i++)
				{
					HashData<V>* cur = _tables[i]._data;
					if (cur)
					{
						size_t hash = hf(KofT(cur->_kv)) % (_tables.size() * 2);
						// 扩容后，不同的桶的值可能映射到同一个桶中
						HashData<V>* next = tmp[hash]._data;
						if (next)
						{
							while (next->_next)
							{
								next = next->_next;
							}
							next->_next = _tables[i]._data;
							tmp[hash]._size += _tables[i]._size;
						}
						else
						{
							tmp[hash]._data = _tables[i]._data;
							tmp[hash]._size = _tables[i]._size;
						}
					}
				}

				//_tables.swap(tmp._tables);     // 后面用友元实现tmp._tables
				_tables.swap(tmp);
			}

			// 哈希函数运算
			size_t hash = hf(KofT(kv)) % _tables.size();

			// 开始插入
			HashData<V>* cur = _tables[hash]._data;
			if (cur)
			{
				while (cur->_next)
				{
					cur = cur->_next;
				}
				cur->_next = new HashData<V>(kv);
			}
			else
			{
				_tables[hash]._data = new HashData<V>(kv);
			}

			++_tables[hash]._size;
			++_n;

			return true;
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
						return cur;
					}

					cur = cur->_next;
				}
			}

			return nullptr;
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
