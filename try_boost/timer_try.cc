#include<iostream>
#include <boost/timer/timer.hpp>


int main(int argc, char* args[]){
	using namespace std;
	
	boost::timer::cpu_timer cpuTimer;
	
	for(unsigned int i=0x00000000; i<0xffffffff; i++ );
	
	cpuTimer.stop();
	
	cout << cpuTimer.format() << endl;
	
	return 0;
}