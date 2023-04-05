#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//for_each不仅能对容器进行遍历，也能够对C语言中的数组进行遍历

//仿函数 也称 函数对象 ;实质就是重载了括号()的类或结构体，调用时 类名() 方式嗲调用。
class Print0
{
public:
    void operator()(int val)
    {

        cout << val << " ";
    }
};

void print1(int val)
{
    cout << val << " ";
}

void test1()
{
    vector<int> vec1;
    for (int idx = 0; idx < 6; idx++)
    {
        vec1.push_back(rand() % 100);
    }
    for_each(vec1.begin(), vec1.end(), Print0()); //仿函数就是类或者结构体重载了（）符号，调用时仿函数需要写（），普通函数直接写函数名即可
    cout << endl;
    for_each(vec1.begin(), vec1.end(), print1);
    cout << endl;
    cout<<"使用lambda表达式来作为for_each的第三个参数："<<endl;
    for_each(vec1.begin(),vec1.end(),[=](int x){cout<<x<<" ";});
    cout<<endl;

}

// transfor将一个容器转移到另一个容器中，也可以在转移的过程中对原来容器元素进行一些算数操作
// eg:下面第一个仿函数Transform()原封不动转移到另一个容器中，第二个trans普通函数，则对原来容器的数据进行了加5操作，再转移到另一个容器中

class Transform
{
public:
    int operator()(int val)
    {

        return val;
    }
};

int trans(int val)
{
    return val += 5;
}

int op_twosum(int i, int j)
{

    return i + j;
}

void test2()
{
    vector<int> vec2;
    for (int idx = 0; idx < 6; idx++)
    {
        vec2.push_back(rand() % 100); //将容器中的元素值大小限定在0-99
    }


    //下面两个版本的transform的，版本一第三个参数，版本二第四个参数是可变的，代表最终将要把元素转移到哪个容器
    //用法1：操作一个容器元素，传递的函数参数只需要一个元素参数，trans参数只需要一个参数；将一个容器的元素转移到另一个容器中，或者在转移的过程中做一些算数运算
    vector<int> vec3; //转移后的容器大小应和第一个容器大小一致，一定要在第一个容器有元素后再进行这步操作
    vec3.resize(vec2.size());

    //此处甚至不需要开辟两个容器，只需要一个容器也可，将第三个参数改为vec2.begin即可，这样vec2中的元素经过操作后最终结果会覆盖原来的元素
    transform(vec2.begin(), vec2.end(), vec3.begin(), Transform()); //仿函数就是类或者结构体重载了（）符号，调用时仿函数需要写（），普通函数直接写函数名即可
    cout << "for_each()-Transform() = ";
    for_each(vec3.begin(), vec3.end(), print1);
    cout << endl;

    transform(vec2.begin(), vec2.end(), vec3.begin(), trans);   //函数参数可换为匿名函数：[](int x){return x+5;} 
    cout << "for_each()-trans +5 = ";
    for_each(vec3.begin(), vec3.end(), print1);
    
    //用法2：操作两个容器元素，传递的函数参数需要两个元素参数，op_twosum两个参数；将vec2容器的元素和vec3容器的元素相加，并将结果重新赋给vec2容器,若第4个元素是vec3.begin(),则是将结果赋给vec3容器--5个参数
    transform(vec2.begin(), vec2.end(), vec3.begin(), vec2.begin(), op_twosum);  //函数参数可换为lambda表达式：[](int,x,int,y){return x+y;}
    cout << "op_twosum :";
    for_each(vec2.begin(), vec2.end(), print1);
    cout << endl;
}

int main()
{

    test1();
    test2();

    system("pause");
    return 0;
}

/* 测试结果如下所示：
41 67 34 0 69 24
41 67 34 0 69 24
for_each()-Transform() = 78 58 62 64 5 45
for_each()-trans +5 = 83 63 67 69 10 50
op_twosum :161 121 129 133 15 95
请按任意键继续. . . */