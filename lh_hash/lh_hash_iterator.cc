#include"lh_hash_iterator.hpp"
#include"lh_hash_table.hpp"

template<typename Val, 
		 typename Key,
		 typename HashFunc,
		 typename EqualKey,
		 typename ExtractKey,
		 typename Alloc>	 
typename LHHashTableIterator<Val, Key, HashFunc, EqualKey, ExtractKey, Alloc>::iterator& 
	LHHashTableIterator<Val, Key, HashFunc, EqualKey, ExtractKey, Alloc>::operator++(){
	
	if(_pHashTable->empty()){
		_pCurrentNode = NULL;
	} else if(_pCurrentNode->next != NULL){
		_pCurrentNode = _pCurrentNode->next;
	} else {
		//find the bucket of this node
		Key key = _pHashTable->_getKey(_pCurrentNode->value);
		typename HashTable::size_type i = _pHashTable->_hasher(key);
		
		for(i+=1; _pHashTable->_buckets[i].next==NULL&&i<_pHashTable->_maxCount ; i++);
		_pCurrentNode = _pHashTable->_buckets[i].next;
	}
	
	return *this;
}
	