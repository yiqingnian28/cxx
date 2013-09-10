#ifndef BOOST_TEST_OBJ_HPP_INCLUDED_
#define BOOST_TEST_OBJ_HPP_INCLUDED_

#include<iostream>

class BoostTestObj {
public:
	BoostTestObj(){		
		std::cout << "new BoostTestObj created at " << this << " ..." << std::endl;		
	}
	
	BoostTestObj(const BoostTestObj& obj){
		std::cout << "" << std::endl;
	}
		
	~BoostTestObj(){
		std::cout << "BoostTestObj at " << this << " released..." << std::endl;
	}
	
	
	
protected:
	int _value;
	
};
#endif