#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
    Person(string name,int age) : m_name(name),m_age(age) {}
    ~Person(void) {}
    bool operator==(const Person &rhs) const;
public:   //属性要设置成公有的，否则后面通过迭代器找到后无法访问
    string m_name; // 姓名
    int m_age;//年龄
};

bool Person::operator==(const Person &rhs) const
{
    return (m_name == rhs.m_name && m_age == rhs.m_age);
}
void func0(){


    //测试普通类型时find的使用
    vector<int> vec = {3, 5, 6, 9, 7, 1};
      auto it = find(vec.begin(),vec.end(),9);
      if(it != vec.end()){
          cout<<"找到元素："<<*it<<endl;
      }
      else{
          cout<<"元素不存在"<<endl;
      } 

    vector<Person> vect = {Person("zhangsan",34), Person("lisi",24), Person("xiaocui",16)};
    Person one("lisi",24);
    auto it1 = find(vect.begin(), vect.end(), one);
    if (it1 != vect.end())
    {
        cout << "找到这个人:name: " << it1->m_name<<",age: "<<it1->m_age<<endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

}



//find_if--此处给予find_if函数第三个参数普通函数（全局）、仿函数（函数对象）、lambda(匿名函数)三种调用法

//普通函数
bool lessThanFive(int val) {
	return val < 5;
}

//谓词（返回类型为bool的仿函数/函数对象）
class LessThanFive {
public:
	bool operator()(int val) {
		return val < 5;
	}
};

//查找内置数据类型元素
void func1() {
	vector<int> v;

	v.push_back(9);
	v.push_back(4);
	v.push_back(7);
	v.push_back(6);
	v.push_back(3);

	//回调函数
	vector<int>::iterator pos = find_if(v.begin(), v.end(), lessThanFive);
	
	//谓词
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), LessThanFive());
	
	//匿名函数（lambda表达式）
    //vector<int>::iterator pos = find_if(v.begin(), v.end(), [](int val) {return val < 5;});
    if(pos == v.end()){cout<<"目标元素不存在";};
	while(pos != v.end()) {
		cout << "目标元素存在：" << *pos << endl;	//1
        pos = find_if(++pos,v.end(),[](int val){return val<5;}); //循环确保将所有满足条件的元素打印出来，此处需要将查找范围改变，初始位置应该是已经查找到元素的下一个位置
    }   //--一定要注意，++pos是之前找到元素的下一位置，重置查找范围，find_if返回的pos是新查找到的元素位置
}		//还要注意！++pos必须使用前置++，如果使用后置pos++此是将当前已查找到的位置作为下一次新的开始位置，这样始终打印这一个未知的元素陷入死循环。	



class People {
public:
	string name;
	int age;

	People(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

//回调函数
bool greaterThan20(const People &p) {
	return p.age > 20;
}

//谓词（返回类型为bool的仿函数/函数对象）
class GreaterThan20 {
public:
	bool operator()(const People& p) {
		return p.age > 20;
	}
};

//查找自定义数据类型元素，需重载operator==运算符
void func2() {
	vector<People> v;
	People p1("Tom", 16);
	People p2("Jerry", 18);
	People p3("Jack", 20);
	People p4("Lucy", 22);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//回调函数
	//vector<People>::iterator pos = find_if(v.begin(), v.end(), greaterThan20);

	//谓词
	//vector<People>::iterator pos = find_if(v.begin(), v.end(), GreaterThan20());

	//匿名函数（lambda表达式）
	vector<People>::iterator pos = find_if(v.begin(), v.end(), [](const People &p) {return p.age > 20; });

	if (pos != v.end()) {
		cout << "目标元素存在： 姓名：" << (*pos).name << "，年龄：" << pos->age << endl;	//姓名：Lucy，年龄：22
	}
	else {
		cout << "目标元素不存在.." << endl;
	}
}

int main()
{

/*     find：查找指定元素是否存在。find_if：按条件查找元素是否存在。
    注1：使用find算法时，需包含头文件include <algorithm>。
    注2：查找自定义数据类型的元素时，需在自定义数据类型的类中，重载运算符operator==，
    告知find算法应如何比较两个自定义数据类型的对象。eg:查找元素为结果体或类实例的对象 */

    //find
    func0();

    //find_if
    func1();
    func2();

    system("pause");
    return 0;
}