#ifndef LH_ALLOC_TRAITS_HPP
#define LH_ALLOC_TRAITS_HPP
template<typename Val, class Alloc>
struct LHAllocTraits{
	
	// From GCC:
	// use ‘Alloc::template rebind’ to indicate that it is a template
	typedef typename Alloc::template rebind<Val>::other allocator_type;

};

#endif 