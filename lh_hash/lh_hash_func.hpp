#ifndef LH_HASH_FUNC_HPP
#define LH_HASH_FUNC_HPP

template<typename Key>
struct HashMod{
};

template<>
struct HashMod<int>{
	int operator()(int x){return x%256;}
};

#endif