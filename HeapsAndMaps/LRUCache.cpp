#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
	private:

		int cap;
		list < int > keyList;
		map < int , list < int > :: iterator > pos;
		map < int , int > keyToValue;

		void moveToFront(int key)
		{
			keyList.erase(pos[key]);
			keyList.push_front(key);
			pos[key] = keyList.begin();
		}

		void evict()
		{
			int popKey = keyList.back();
			keyList.pop_back();
			pos.erase(popKey);
			keyToValue.erase(popKey);
		}

		void insert(int key , int value)
		{
			keyList.push_front(key);
			pos[key] = keyList.begin();
			keyToValue[key] = value;
		}

	public:
		LRUCache(int capacity)
		{
			cap = capacity;
			keyList.clear();
			pos.clear();
			keyToValue.clear();
		}
		
		int get(int key)
		{
			if(keyToValue.find(key) != keyToValue.end())
			{
				moveToFront(key);

				return keyToValue[key];
			}

			return -1;
		}

		void set(int key , int value)
		{
			if(pos.find(key) != pos.end())
			{
				moveToFront(key);
				keyToValue[key] = value;
			} 
			else
			{
				if(keyList.size() == cap) evict();
				insert(key , value);
			}
		}
	
};





int main()
{
	LRUCache lru(2);

	lru.set(1 , 10);
	lru.set(5 , 12);

	cout << lru.get(5) << endl;

	cout << lru.get(1) << endl;

	cout << lru.get(10) << endl;

	lru.set(5 , 14);

	cout << lru.get(5) << endl;

}