#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <vector>


#include "boost_test_obj.hpp"

struct TestStruct {
	TestStruct() : objPtr(new BoostTestObj()) {
		
	}
	
	boost::scoped_ptr<BoostTestObj> objPtr;
};

void testScopedPtr(){
	using namespace std;
	cout << "entering testScopedPtr :" << endl;
	TestStruct s;
	s.objPtr.reset( new BoostTestObj);
	cout << "leaving testScopedPtr ..." << endl;

}

void testSharedPtr(){
	cout << "entering testSharedPtr:" << endl;
	 
	
	
	cout << "leaving testSharedPtr..." << endl;
}

int main(int argc, char* argv[]){
	using namespace std;
	cout << "entering main function..." << endl ;
	
	testScopedPtr();
	
	cout << "leaving main():" << endl;
	return 0;
}
