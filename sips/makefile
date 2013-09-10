INCLUDE = -I ~/libosip2-4.0.0/include
LIB_PATH = /usr/local/lib

LIBS = -lboost_timer -lboost_chrono -lboost_system
				
STATIC_LIBS = /usr/local/lib/libosipparser2.a 

ALL_TARGET = \
	test_osip_uri_parser


all : $(ALL_TARGET)
clean : 
	rm $(ALL_TARGET)
	rm *.o

#rules for each target
test_osip_uri_parser : test_osip_uri_parser.cc
	g++ $(INCLUDE)   test_osip_uri_parser.cc $(STATIC_LIBS)  -o test_osip_uri_parser 
