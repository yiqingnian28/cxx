// TestCast.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;
class Base
{
public:
virtual void f() { cout << "Base::f" << endl; }
void f1(){cout << "Base::f1" << endl;}
private:
double x;
double y;
};
class Derived : public Base
{
public:
virtual void f(){cout << "Derived::f" << endl; }
virtual void k(){cout << "Derived::k" << endl; }
private:
double z;
};
class Base1
{
public:
virtual void g(){ cout << "Base1::g" << endl;}
void g1(){cout << "Base1::g1" << endl;}
};
class Derived1 : public Base,public Base1
{
public:
virtual void f(){ cout << "Derived1::f" << endl;}
virtual void h(){ cout << "Derived1::h" << endl;}
};
void Test1()
{
// 对于单继承，
// 如果pD真的指向Derived，用dynamic_cast和static_cast效果相同
Base *pD = new Derived;
Derived *pD1 = dynamic_cast<Derived*>(pD);
pD1->f();
pD1->k();
pD1->f1();
Derived *pD2 = static_cast<Derived*>(pD);
pD2->f();
pD2->k();
pD2->f1();
// 但是如果pB不是真的指向Derived，则用dynamic_cast则返回NULL，能够更早的禁止error的发生，
// 如果用static_cast虽然返回的不为NULL，但是运行时可能抛出exception。
/**///// Error code 
//Base *pB = new Base();
//Derived *pD3 = static_cast<Derived*>(pB);
//pD3->f();
//pD3->k();
//pD3->f1();
//Derived *pD4 = dynamic_cast<Derived*>(pB);
//pD4->f();
//pD4->k();
//pD4->f1();
}
void Test2()
{
// 对于多重继承，
// 如果pD真的指向的是Derived1，使用dynamic_cast和static_cast都可以转化为Derived1，
// 但是如果要转化为Base的兄弟类Base1，必须使用dynamic_cast，使用static_cast不能编译。
Base *pD = new Derived1;
Derived1 *pD1 = dynamic_cast<Derived1*>(pD);
pD1->f();
pD1->h();
pD1->f1();
Base1 *pB1 = dynamic_cast<Base1*>(pD);
pB1->g();
Derived1 *pD2 = static_cast<Derived1*>(pD);
pD2->f();
pD1->h();
pD2->f1();
/**///// error can not compiler
//Base1 *pB2 = static_cast<Base1*>(pD);
//pB2->g();
// 当然对于pB不是真的指向Derived1，想要转化为Derived1或Base的兄弟类Base1，情况与Test1中的error情况相同。
}
int main(int argc, char* argv[])
{
Test1();
Test2();
return 0;
}
