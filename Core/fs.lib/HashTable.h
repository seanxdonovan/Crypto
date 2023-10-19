namespace fs
{
	template <class K, class V>
	class HashTable
	{
		typedef std::pair<K, V> Pair;
		typedef std::list<Pair> ListType;
		std::vector<ListType> m_buckets;
	public:
		HashTable(size_t p_width)
		{
			m_buckets.resize(p_width);
		}

		~HashTable()
		{
		}

		void Insert(const K& p_k, const V& p_v)
		{
			dword offset = (dword)(Hash(p_k) % m_buckets.size());

			ListType::iterator it = m_buckets[offset].begin();
			while (it != m_buckets[offset].end())
			{
				Pair& pr = *it;
				if (pr.first == p_k)
				{
					pr.second = p_v;
					return;
				}
				++it;
			}
			m_buckets[offset].push_back(Pair(p_k, p_v));
		}

		bool Find(const K& p_k, V *p_pV) const
		{
			dword offset = (dword)(Hash(p_k) % m_buckets.size());

			ListType::const_iterator it = m_buckets[offset].begin();
			while (it != m_buckets[offset].end())
			{
				const Pair& pr = *it;
				if (pr.first == p_k)
				{
					*p_pV = pr.second;
					return true;
				}
				++it;
			}

			return false;
		}

		void Remove(const K& p_k)
		{
			dword offset = (dword)(Hash(p_k) % m_buckets.size());

			ListType::iterator it = m_buckets[offset].begin();
			while (it != m_buckets[offset].end())
			{
				Pair& pr = *it;
				if (pr.first == p_k)
				{
					m_buckets[offset].erase(it);
					return;
				}
				++it;
			}
		}

		void Clear()
		{
			for (size_t ix = 0; ix < m_buckets.size(); ++ix)
			{
				m_buckets[ix].clear();
			}
		}
	};
}
