#include<iostream>
#include <boost/progress.hpp>


int main(int argc, char* args[]){
	
	boost::progress_display proDisp(0xffffffff);
	for(unsigned int i=0x00000000; i<0xffffffff; i++ ){
		++proDisp;
	}
	return 0;
}