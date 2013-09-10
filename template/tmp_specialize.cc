#include <iostream>
using namespace std;

template<typename T>
class Haha {
public:
	void doSomething(){
		cout << "Haha does something()" <<endl;
		return ;
	}
	
	template<typename U>
	struct Hehe {
		Hehe(){cout << "Hehe" << endl;}
	};

private:
};

template<>
void Haha<int>::doSomething(){
	cout << "Haha<int> does something" << endl;
}

template<>
	template<>
	Haha<char>::Hehe<char>::Hehe(){
		cout << "Haha<char>::Hehe<char>::Hehe()" << endl;
	}

template<>
	template<typename U>
	Haha<char>::Hehe<U>::Hehe(){
		cout << "Haha<char>::Hehe::Hehe()" << endl;
	}

int main() {

	Haha<int> hahaInt;
	hahaInt.doSomething();
	
	Haha<char>::Hehe<char>();
	Haha<char>::Hehe<int>();
	
	return 0;
}