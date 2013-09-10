#include <iostream>

using namespace std;

class Base {
public :
	void funcPublic(){cout << "Base::funcPublic()" << endl;};
protected :
	void funcProtected(){cout << "Base::funcProtected()" << endl;};;
private :
};

class Inherited : private Base {
public :
	void funcPublic(){ 
		Base::funcPublic();
		Base::funcProtected();
	}
protected :
private :
};

int main(){
	Inherited child;
	child.funcPublic();
	return 0;
}

