#ifndef LH_HASH_TABLE_HPP
#define LH_HASH_TABLE_HPP

#define MAX_COUNT 256

#include<lh_hash_iterator.hpp>
#include<lh_alloc_traits.hpp>

#include<stddef.h> //for ptrdiff_t
#include<utility> //for pair

using std::pair;

template<typename Val, 
		 typename Key,
		 typename HashFunc,
		 typename EqualKey,
		 typename ExtractKey, //Extract key from given value
		 typename Alloc>
class LHHashTable {
public:
	
	typedef Key key_type;
	typedef Val value_type;
	typedef HashFunc hasher;
	typedef EqualKey key_equal;
		
	typedef size_t size_type;
	typedef Val* pointer;
	typedef Val& reference;
	typedef ptrdiff_t difference_type;
	
private:
	typedef LHHashTableNode<Val> Node;

public:
	typedef typename LHAllocTraits<Val, Alloc>::allocator_type allocator_type;
	allocator_type get_allocator() const {return NULL;}
	
private:
	typedef typename LHAllocTraits<Node, Alloc>::allocator_type node_alloc_type;
	node_alloc_type* _pNodeAllocator;
	
	
	hasher 		_hasher;
	key_equal 	_keyEqual;
	ExtractKey	_getKey;
	Node*		_buckets;
	size_type	_elementCount;
	size_type	_maxCount;

public:
	typedef LHHashTableIterator<Val, Key, HashFunc, EqualKey, Alloc> iterator;
	typedef LHHashTableIterator<const Val, const Key, HashFunc, EqualKey, Alloc> const_iterator;

	friend struct LHHashTableIterator<Val, Key, HashFunc, EqualKey, Alloc>;

	//constructor
	LHHashTable(const HashFunc &hf,
				const EqualKey &eq,
				const ExtractKey &gk)
				: _hasher(hf),
				  _keyEqual(eq),
				  _getKey(gk),
				  _elementCount(0),
				  _maxCount(MAX_COUNT){
		
		initHashTable();
	}
	
	~LHHashTable(){
		delete _pNodeAllocator;
		free(_buckets);
	}
	
	size_type size(){return _elementCount;}
	bool emepty(){return size()==0;}
	
	iterator begin(){
		for(size_type i=0; i<_maxCount; i++){
			if(_buckets[i] != NULL){
				return iterator(&_buckets[i]);
			}
		}
		return end();
	}
	
	iterator end(){
		return iterator(NULL);
	}
	
	//insert 
	pair<iterator, bool>insert(const value_type& obj){
		key_type keyTemp = _getKey(obj);
		size_type pos = _hasher(keyTemp);
		
		//create a copy of obj, and put it into the buckets.
		Node* node = _pNodeAllocator->allocate(1);
		node->value = obj;
		Node *n;
		for(n = &_buckets[pos]; n->next!=NULL; n=n->next);
		n->next = node;

		//TODO(Liu): where should this iterator point to ?
		return pair<iterator,bool>(node, true);
	}
	
	// find 
	iterator find(key_type k){
		
		//why use size_type
		size_type i = _hasher(k);
		
		Node* n;
		for(n=_buckets[i].next; n!=NULL; n=n->next){
			if(_getKey(n->value) == k){
				break;
			}
		}
		
		return 	iterator(n);
	}
private:
	
	//initialize the buckets for hash table
	void initHashTable(){
		_pNodeAllocator = new node_alloc_type();
		_buckets = _pNodeAllocator->allocate(_maxCount);
	};
	

	
	
};





#endif