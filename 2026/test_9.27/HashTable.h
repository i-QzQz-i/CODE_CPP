#pragma once

#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace QzQz
{
	enum State
	{
		EXIST,   // 存在
		EMPTY,   // 空
		DELETE   // 删除
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
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

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable_open // 开放定址法
	{
	public:

		HashTable_open()
		{ 
			_tables.resize(11);
		}

		HashTable_open(size_t size)
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

			// 检查是否扩容 负载因子 >= 0.7 
			if (_size  * 10 / _tables.size() >= 7)
			{
				HashTable_open<K, V> tmp(_tables.size() * 2);
				for (int i = 0; i < _tables.size(); i++)
				{
					tmp.Insert(_tables[i]._kv);
				}

				//swap(this, &tmp);

				//_tables.swap(tmp._tables);
				_tables.swap(tmp.Get_Table());
			}

			// 哈希函数运算
			Hash hf;
			size_t hash0 = hf(kv.first) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;

			// 判断是否哈希冲突（碰撞）
			while (_tables[hashi]._state == EXIST && _tables[hashi]._kv != kv)
			{
				hashi = (hash0 + i) % _tables.size();
				++i;
			}

			// 开始插入
			//_tables[hashi] = HashData<K, V>(kv);
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hash0 = hf(key) % _tables.size();
			size_t hashi = hash0;
			size_t i = 1;

			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST
				 && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				// 线性探测
				hashi = (hash0 + i) % _tables.size();
				++i;
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
				tmp->_state = DELETE;
				--_size;
				return true;
			}

			return false;
		}

		vector<HashData<K, V>>& Get_Table()
		{
			return _tables;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _size = 0; // 表中数据个数
	};


}

namespace hash_bucket
{
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		HashData<K, V>* _next;

		HashData(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{ }
	};

	template<class K, class V>
	struct HashBucket
	{
		size_t _size = 0;
		HashData<K, V>* _next = nullptr;
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

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable_link // 链地址法
	{
	public:
		typedef HashBucket<K, V> Node;

		HashTable_link()
		{
			_tables.resize(11);
		}

		HashTable_link(size_t size)
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

			// 检查是否扩容 负载因子 >= 0.7 
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable_link<K, V> tmp(_tables.size() * 2);
				for (int i = 0; i < _tables.size(); i++)
				{
					tmp.Insert(_tables[i]._kv);
				}

				//_tables.swap(tmp._tables);
				_tables.swap(tmp.Get_Table());
			}

			// 哈希函数运算
			Hash hf;
			size_t hash = hf(kv.first) % _tables.size();

			// 判断桶长度是否大于8，若大于，则把链表更新为红黑树

			// 开始插入
			HashData<K, V>* cur = _tables[hash]->_next;
			while (1)
			{

			}
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hash = hf(key) % _tables.size();
			HashData<K, V>* cur = _tables[hash]->_next;

			while (cur->_next != nullptr)
			{
				if (cur->_kv == key)
				{
					return cur;
				}

				cur = cur->_next;
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

		vector<HashData<K, V>>& Get_Table()
		{
			return _tables;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0; // 表中数据总个数
	};
}




