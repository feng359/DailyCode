#include <iostream>

using namespace std;
class Person
{

public:
    Person(int age = 18, string name = " ") : _age(age), _name(name) {}
    void print(); 
    friend istream& operator>>(istream &ist, Person &obj);
    friend ostream& operator<<(ostream &ost, Person &obj);

private:
    int _age;
    string _name;
};

istream& operator>>(istream &ist, Person &obj)
{
    ist >> obj._age >> obj._name;
    return ist;
}
ostream& operator<<(ostream &ost, Person &obj){
    ost<<obj._age<<"\t"<<obj._name<<endl;
    return ost;

}

void Person::print() //成员函数可直接访问类的私有数据成员
{
    cout << _age <<"\t"<<_name << endl;
}
int main()
{
    Person  MM;
    Person  nn;
    cin>>MM>>nn;   //一次输入：32 honghong 19 lili ；  两次输入：32 honghong 回车 19 lili 回车 ； 四次输入，32回车，honghong 回车、、、、
    cout<<MM<<nn<<endl;
    cout<<"print:"<<endl;
    MM.print();
    nn.print();
    system("pause");
    return 0;
}