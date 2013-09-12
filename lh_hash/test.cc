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
	hashTable.insert(14);
	hashTable.insert(15);
	hashTable.insert(11);
	hashTable.insert(16);
	hashTable.insert(4);

	//test find()
	cout << "test find:" << endl;
	HashTableType::iterator iter16 = hashTable.find(16);
	HashTableType::iterator iter17 = hashTable.find(17);
	cout << *iter16 << endl;
	cout << *iter17 << endl;
	
	//test search
	cout << "test search:" << endl;
	for(HashTableType::iterator iter = hashTable.begin(); iter != hashTable.end(); ++iter){
		cout << *iter <<' ';
	}
	cout << endl;
	
	return 0;
}