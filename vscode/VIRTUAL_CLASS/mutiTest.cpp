#include <iostream>

using namespace std;

class Person
{

public:
    virtual void func()
    {
        cout << "I am a person" << endl;
    }
};

class Student : public Person
{

public:
    void func()
    {
        cout << "I am a student" << endl;
    }
};

void mutiTest1(Person *obj)
{
    obj->func();
}

void mutiTest2(Person &obj)
{
    obj.func();
}

int main()
{

    Person p1;
    Person p2;

    Student stu1;
    Student stu2;

    cout << "指针方式：" << endl;
    mutiTest1(&p1);
    mutiTest1(&stu1);

    cout << "引用方式：" << endl;
    mutiTest2(p2);
    mutiTest2(stu2);

    system("pause");
    return 0;
}