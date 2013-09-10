BOOST_HOME = ~/boost_1_54_0/libs
INCLUDE = -I ~/boost_1_54_0
LIB_PATH = -L ~/boost_1_54_0/stage/lib
LIBS_PATH = ~/boost_1_54_0/stage/lib
LIBS = -lboost_timer -lboost_chrono -lboost_system
				
STATIC_LIBS = 	$(LIBS_PATH)/libboost_timer.a \
				$(LIBS_PATH)/libboost_chrono.a \
				$(LIBS_PATH)/libboost_system.a

ALL_TARGET = \
	timer_try \
	timer_try_shared \
	progress_display_try \
	format_try \
	string_algo_try \
	utf_try


all : $(ALL_TARGET)
clean : 
	rm $(ALL_TARGET)
	rm *.o

#rules for each target
timer_try : timer_try.cc
	g++ $(INCLUDE) $(LIB_PATH)  timer_try.cc $(STATIC_LIBS)  -o timer_try -lrt

timer_try_shared : timer_try.cc
	g++ $(INCLUDE) $(LIB_PATH)  timer_try.cc $(LIBS)  -o timer_try.shared
	
progress_display_try: progress_display_try.cc
	g++ $(INCLUDE) progress_display_try.cc -o progress_display_try

smart_ptr_try: smart_ptr_try.cc boost_test_obj.hpp
	g++ $(INCLUDE) smart_ptr_try.cc -o smart_ptr_try

format_try: format_try.cc
	g++ $(INCLUDE) format_try.cc -o format_try

string_algo_try : string_algo_try.cc
	g++ $(INCLUDE) string_algo_try.cc -o string_algo_try
	
utf_try : utf_try.cc utf_try_ex.cc 
	g++ $(INCLUDE) -c utf_try.cc -o utf_try.o
	g++ $(INCLUDE) -c utf_try_ex.cc  -o utf_try_ex.o
	g++ utf_try.o utf_try_ex.o -o utf_try
 