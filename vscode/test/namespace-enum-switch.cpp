#include <iostream>

using std::cout;
using std::endl;
using std::string;

// namespace只能在全局定义、支持嵌套定义（不能在函数体内定义，只能空间嵌套空间）、随时添加成员

namespace myspace
{
    int val = 4;
    void func()
    {
        cout << "This is myspace!" << endl;
    }
}

//注意：上面第一次添加了val和func两个成员，这一次是同一个命名空间，并不是新建的命名空间，是在已创建的myspace命名空间的基础上新添加了show成员
//这下，myspace命名空间共有val,func,show三个成员，满足随时添加成员特性。
namespace myspace
{
    void show()
    {
        cout << "Hello World!" << endl;
    }
}

// namespace匿名名字空间；无名命名空间意味着命名空间中的符号只能在本文件中访问，相当于给符号增加了 static 修饰，只能在当前文件内访问。
//匿名命名空间中的变量特点跟全局变量一样(意味着可以直接类似全局变量一样调用)。
namespace
{
    int value = 9;
    void print()
    {
        myspace::func();
        cout << " Hi , boy!" << endl;
    }
}

//命名空间的嵌套使用
namespace spaceA
{
    int number = 10;

    namespace spaceB
    {
        void func()
        {
            cout << "Hello,girl!" << endl;
        }
    }
}




// 1-枚举适用于一个一个变量有几个固定的取值；例如一天可能属于一周的星期几;day就是枚举类型可取周一到周日的任何一天；
//类似的季节season可以取春夏秋冬四个值。2-枚举是有值，枚举的几个值是连续的，一般第一个值默认为0，下一个值依次加一，
//如果要改变其值，则只需在在第一个值显示赋给其值，后面的所有的值会默认依次加一。
void enum_test()
{

    // 1-先定义枚举类型day，再定义枚举变量d
    /* enum day1
    {
        mon,
        tue,
        wed,
        thu,
        fri,
        sat,
        sun
    };     //不给mon赋值，默认mon=0,tue=1,wed=2,thu=3...后面依次加一;
    enum day1 d1 = thu;
    cout << "enum day d = thu: " << d1 << endl; */
    //结果为3

    enum day2
    {
        mon = 1,
        tue,
        wed,
        thu,
        fri,
        sat,
        sun
    }; //给mon赋值,则后面的值在mon的基础上依次加一，mon=1,tue=2,wed=3,thu=4...后面依次加一;
    enum day2 d2 = thu;
    cout << "enum day d2 = thu : " << d2 << endl; //结果为4

    //定义枚举类型和变量，再赋值
    enum season
    {
        spring,
        summer,
        autumn,
        winter
    } s;
    s = winter;
    cout << s << endl;


    //2-枚举变量充当switch()中的参数
    enum color
    {
        blue = 1,
        red,
        green,
        yellow
    };
    enum color favourate;

    //下面流程多用于管理系统首页选项功能。
    while (true)
    {
        printf("请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  ");
        scanf("%d", &favourate); //此句必须写在while循环里面，否则一直打印第一次输入的结果。
        if (99 == favourate)
        {
            break;
        }

        //switch参数可以是int型变量
        /*  int a;
         scanf("%d", &a);
         if (99 == a)
         {
             break; //方便退出循环
         } */
         //switch(a) 
         
        //case下面如果不是一条语句,需要写很多语句，则可在case下使用加{}，在{}里面写代码
        switch (favourate)
        {
        case blue:    //多条语句使用{}。
           {
             printf("你喜欢的颜色是蓝色!\n");
            int b =4;
            cout<<b;
            break;
           }
        case red:
            printf("你喜欢的颜色是红色!\n");
            break;
        case green:
            printf("你喜欢的颜色是绿色!\n");
            break;
        case yellow:
            printf("你喜欢的颜色是黄色!\n");
            break;
        default:
            printf("你的输入存在错误！请重新输入，如果要退出本次输入，请输入 99\n");
            break;
        }
    }
}

int main()
{
    //命名空间中的成员调用方式

    //法1：直接调用
    cout << myspace::val << endl;
    myspace::func();

    //法2：using 声明 指定符号 在某个作用域可见
    using myspace::func;
    using myspace::val;
    cout << val << endl;
    func();

    //法3：using 编译指令指定命名空间的 所有符号 在某个作用域下可见
    using namespace myspace;
    cout << val << endl;
    func();
    myspace::show();

    //匿名命名空间中的成员在本文件中全局有效，直接调用。
    cout << value << endl;
    print();

    //命名空间的嵌套使用
    cout << spaceA::number << endl;
    spaceA::spaceB::func();

    // enum枚举类型和switch的使用

    enum_test();

    system("pause");
    return 0;
}

/* 4
This is myspace!
4
This is myspace!
4
This is myspace!
Hello World!
9
This is myspace!
 Hi , boy!
10
Hello,girl! 4
This is myspace!
4
This is myspace!
4
This is myspace!
Hello World!
9
This is myspace!
 Hi , boy!
10
Hello,girl!
enum day d2 = thu : 4
3
请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  3
你喜欢的颜色是绿色!
请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  1
你喜欢的颜色是蓝色!
4请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  2
你喜欢的颜色是红色!
请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  4
你喜欢的颜色是黄色!
请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  5
你的输入存在错误！请重新输入，如果要退出本次输入，请输入 99
请输入你最喜欢的颜色:1-blue,2-red,3-green,4-yellow-(99退出系统):  99*/