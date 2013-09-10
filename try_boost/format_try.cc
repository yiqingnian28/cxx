#include <boost/format.hpp>
#include <string>
using namespace boost;
using namespace std;

int main(){
	
	string s("sum");
	
	cout << format("%s: %d+%d=%d") % s % 1 % 2 % (1+2) << endl ;
	
	format fmt(" %1% %2% %1% %2%");
	
	//arg 1 is occupied
	fmt.bind_arg(1, "fixed");
//	fmt % string("first");

	//this is arg 2
	fmt % string("sencond");
	cout << fmt.str() << endl;	

}