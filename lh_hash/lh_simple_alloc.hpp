#ifndef LH_SIMLPLE_ALLOC_HPP
#define LH_SIMLPLE_ALLOC_HPP

#include<stdlib.h>
template<typename Val>
struct LHSimpleAllocator{

	typedef LHSimpleAllocator<Val> allocator_type;
		
	template<typename Other>
	struct rebind{
		typedef LHSimpleAllocator<Other> other;
	};
	
	Val* allocate(size_t n){
		return (Val*)malloc(n * sizeof(Val));
	}
};



#endif