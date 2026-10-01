#pragma once

#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace QzQz
{
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		HashData<K, V>* _next;

		HashData(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{
		}
	};

	template<class K, class V>
	struct HashBucket
	{
		size_t _size = 0;
		HashData<K, V>* _data = nullptr;
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

	template<class K, class V, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		typedef HashBucket<K, V> Node;

		HashTable()
		{
			_tables.resize(11);
		}

		HashTable(size_t size)
		{
			_tables.resize(size);
		}

		bool Insert(const pair<K, V>& kv)
		{
			// 查找
			if (Find(kv.first))
			{
				return false;
			}

			Hash hf;

			if (_n * 10 / _tables.size() >= 7)
			{
				vector<Node> tmp(_tables.size() * 2);
				for (int i = 0; i < _tables.size(); i++)
				{
					HashData<K, V>* cur = _tables[i]._data;
					if (cur)
					{
						size_t hash = hf(cur->_kv.first) % _tables.size();
						// 扩容后，不同的桶的值可能映射到同一个桶中
						HashData<K, V>* next = _tables[i]._data;
						if (next)
						{
							while (next->_next)
							{
								next = next->_next;
							}
							next->_next = _tables[i]._data;
						}
						else
						{
							tmp[hash]._data = _tables[i]._data;
						}
					}
				}

				//_tables.swap(tmp._tables);     后面用友元实现tmp._tables
				_tables.swap(tmp);
			}

			// 哈希函数运算
			size_t hash = hf(kv.first) % _tables.size();

			// 开始插入
			HashData<K, V>* cur = _tables[hash]._data;
			if (cur)
			{
				while (cur->_next)
				{
					cur = cur->_next;
				}
				cur->_next = new HashData<K, V>(kv);
			}
			else
			{
				_tables[hash]._data = new HashData<K, V>(kv);
			}

			++_tables[hash]._size;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hash = hf(key) % _tables.size();
			HashData<K, V>* cur = _tables[hash]._data;

			if (cur)
			{
				while (cur)
				{
					if (cur->_kv.first == key)
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
			HashData<K, V>* tmp = Find(key);

			if (key == nullptr)
			{
				return false;
			}
			else
			{
				--_n;
				return true;
			}

			return false;
		}

		vector<Node>& Get_Table()
		{
			return _tables;
		}

	private:
		vector<Node> _tables;
		size_t _n = 0; // 表中数据总个数
	};



}
