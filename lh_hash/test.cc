#include"lh_hash_table"

#include <iostream>

struct IntEqual{
	bool operator()(int lhs, int rhs){
		return lhs == rhs;
	}
};

struct IntExtractKey{
	int operator()(int value){
		return value;
	}
};


int main(){
	using namespace std;

	IntEqual intEqualObj;
	HashMod<int> hashModObj;
	IntExtractKey getKeyObj;

	typedef LHHashTable<int, int, HashMod<int>, IntEqual,IntExtractKey, LHSimpleAllocator<int> >
		HashTableType;
	HashTableType hashTable(hashModObj, intEqualObj, getKeyObj);

	hashTable.insert(16);
	hashTable.insert(17);
	
	HashTableType::iterator iter16 = hashTable.find(16);
	HashTableType::iterator iter17 = hashTable.find(17);

	cout << *iter16 << endl;
	cout << *iter17 << endl;
		
	return 0;
}