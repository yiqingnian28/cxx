#MakeFile for LHHashTable

CXX_FLAGS = -g -O0

ALL_TARGET = \
	test
all : $(ALL_TARGET)
	
	
test: \
	test.cc \
	lh_hash_table.hpp \
	lh_hash_iterator.hpp \
	lh_hash_iterator.cc \
	lh_alloc_traits.hpp \
	lh_simple_alloc.hpp \
	lh_hash_func.hpp 
	g++ -I . $(CXX_FLAGS) test.cc -o test
	

clean : 
	rm $(ALL_TARGET)

#rules for each target
#lh_hash_table_obj : lh_hash_table.hpp lh_hash_iterator.hpp lh_alloc_traits.hpp
#	g++ $(INCLUDE)   test_osip_uri_parser.cc $(STATIC_LIBS)  -o test_osip_uri_parser 

#lh_hash_func : lh_hash_func.hpp
	
	
#lh_hash_alloc : lh_simple_alloc.hpp