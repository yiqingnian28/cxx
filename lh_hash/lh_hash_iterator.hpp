#ifndef LH_HASH_ITERATROR_HPP
#define LH_HASH_ITERATROR_HPP

#include<stddef.h>


//Node 
template<typename Val>
struct LHHashTableNode {
	LHHashTableNode():next(NULL){}
	LHHashTableNode* next;
	Val value;
};

//Iterator
template<typename Val, 
		 typename Key,
		 typename HashFunc,
		 typename EqualKey,
		 typename Alloc>
struct LHHashTableIterator {
	
//	typedef LHHashTable<Val, Key, HashFunc, EqualKey, Alloc> HashTable;
	typedef LHHashTableIterator<Val, Key, HashFunc, EqualKey, Alloc> iterator;
	typedef LHHashTableIterator<const Val, const Key, HashFunc, EqualKey, Alloc> const_iterator;

	typedef LHHashTableNode<Val> Node;
	
	typedef Val value_type;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef Val* pointer;
	typedef Val& reference;
	
	Node *_pCurrentNode;
//	HashTable* _pHashTable;
	
	//constructors
	LHHashTableIterator(Node* node/*, HashTable* ht*/):_pCurrentNode(node)/*, _pHashTable(ht)*/{}
	LHHashTableIterator(){}

	//operators
	reference operator* (){return _pCurrentNode->value;}
	iterator& operator++(){}

};




#endif