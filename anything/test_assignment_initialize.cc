#include <iostream>

using namespace std;

class TestObj {
public:
	TestObj(){cout<<"TestObj()"<<endl;};
	TestObj(const TestObj& obj){cout<<"TestObj(const TestObj& obj)"<<endl;};
	TestObj& operator = (const TestObj& obj){cout<<"operator = ()"<<endl;}

};


int main () {
	
	TestObj obj1 = TestObj();
	TestObj obj2(obj1);
	TestObj obj3 = obj1;
	obj3 = obj1;
	return 0;
}