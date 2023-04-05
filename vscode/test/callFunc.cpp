#include <iostream>

using namespace std;

//回调函数-callback function
//回调函数也是一个函数，与一般普通函数直接调用区别在于，回调函数调用时是作为另一个函数的参数被这个函数调用，
//这个参数就是回调函数的入口地址，用函数指针占位参数(函数指针保存的就是函数的入口地址，函数名就是函数的入口地址），
//传参时，只能传回调函数入口地址本名，不可带参；进入调用函数内部时，调用回调函数就是调用这个函数指针，和一般普通函数调用方式相同，带参数调用。
int callBack(int val)
{

    return ++val;
}


//参照创建线程函数pthread_create()的第三和第四个参数类似于下面第一第二个参数。
void print(int (*callFunc)(int), void *val) //此处采用void *val ，void *通用指针，可转变为任何一类指针，方便不同类型的参数传入。
{ //用一个函数指针占位参数，表示回调函数的入口地址。
    int *valu = (int *)val;  //将通用指针转变为int *型指针
    cout << "test print val = " << *valu << endl;
    cout << "callFunc val = " << callFunc(*valu) << endl; //进入print函数体调用时和一般调用用法相同。调用回调函数就是调用函数指针。
}

int main(int argc, char *argv[])
{
    int val = 3;
    print(callBack, &val); //注意：此处调用不可写括号和参数，直接写函数名入口地址，进入print函数体调用时才能和一般括号调用使用。

    system("pause");
    return 0;
}


/* test print val = 3
callFunc val = 4 */