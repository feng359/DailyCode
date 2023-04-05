#include <iostream>

using namespace std;

//+号由于需要两个操作数，拿来验证成员函数在类里面定义和类外面定义的区别结果是，除了在类外面定义时使用类和作用域外和类里面定义没有任何区别，效果一样的；
//再次验证成员函数和普通函数的区别：结果成员函数少一个左操作数，隐含了左操作数this,
//非成员函数,不再隐含左操作数，操作数需要写全；如果涉及到访问类里面的私有数据成员，则必须在类里面声明时为friend友元，而且普通函数也要通过对象调用类的私有数据，而不能直接访问类的私有数据
class Complex
{
public:
	Complex(int a = 0, int b = 0) :a(a), b(b) {}
	void print()
	{
		cout << a <<"\t" << b << endl;
	}

	void print(Complex & obj);
//  friend Complex operator+(Complex& a, Complex& b);  //注意：友元不属于类的成员函数，类内声明类外实现,只要不是在类里面实现的函数
    //则没有隐含左操作数,c操作数个数必须写全

  /*   Complex operator+(Complex& rhs){    //类里面实现的，由于隐含左操作数，则操作数少一个，只需要写右操作数

        return Complex(this->a+rhs.a,this->b+rhs.b);
        
    } */


	Complex operator+(Complex &obj);

protected:
	int a;
	int b;
};


/* Complex operator+(Complex& a, Complex& b) {  注意：operator+此时不属于类的成员函数，由于要访问类的私有数据成员a和b因此必须在类里声明为友元，
												//而且访问类的私有数据成员不可以直接访问eg:a,而是要通过对象来调用eg:a.a 前一个a是对象，后一个a是数据成员			
	//return Complex(a.a + b.a, a.b + b.b);   //可以直接用无名对象来返回
	Complex c(a.a + b.a, a.b + b.b);         //也可以定义一个临时的类c，然后运算结束后再返回
	return c;                               
} */


	Complex Complex::operator+(Complex &obj){
		return Complex(this->a+obj.a,this->b+obj.b);
	}

	void Complex::print(Complex & obj){
			cout<<obj.a<<"\t"<<obj.b<<endl;
	}

int main()
{
	Complex one(1, 1);
	Complex two(2, 0);
	Complex three;
	three = one + two;   //这里的three是一个类，所以我们可以推断重载函数的返回是一个类
	three.print();
	//one.print(three);//没意义，测试类里声明类外定义
	/*打印结果
	3	1
	*/
    system("pause");
	return 0;
}