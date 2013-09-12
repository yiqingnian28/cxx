#ifndef LH_HASH_ITERATROR_HPP
#define LH_HASH_ITERATROR_HPP

#include<stddef.h> //for ptrdiff_t

template<typename Val, 
		 typename Key,
		 typename HashFunc,
		 typename EqualKey,
		 typename ExtractKey, //Extract key from given value
		 typename Alloc>
class LHHashTable;

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
		 typename ExtractKey,
		 typename Alloc>
struct LHHashTableIterator {
	
	typedef LHHashTable<Val, Key, HashFunc, EqualKey, ExtractKey, Alloc> HashTable;
	typedef LHHashTableIterator<Val, Key, HashFunc, EqualKey, ExtractKey, Alloc> iterator;
	typedef LHHashTableIterator<const Val, const Key, HashFunc, EqualKey, ExtractKey, Alloc> const_iterator;

	typedef LHHashTableNode<Val> Node;
	
	typedef Val value_type;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef Val* pointer;
	typedef Val& reference;
		
	//constructors
	LHHashTableIterator(Node* node, HashTable* ht):_pCurrentNode(node), _pHashTable(ht){}
	LHHashTableIterator(){}

	//operators
	reference operator* (){return _pCurrentNode->value;}
	iterator& operator++();
	
	bool operator==(iterator rhs) const {
		return (this->_pCurrentNode == rhs._pCurrentNode &&
				this-> _pHashTable == rhs._pHashTable);
	}
	
	bool operator != (iterator rhs) const{
		return (this->_pCurrentNode != rhs._pCurrentNode ||
				this-> _pHashTable != rhs._pHashTable);
	}
	
private:
	Node *_pCurrentNode;
	HashTable* _pHashTable;
};




#endif