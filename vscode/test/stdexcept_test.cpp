#include <iostream>
#include <stdexcept>
using namespace std;

//using std::runtime_error;
using std::cout;
using std::endl;

int main()
{
    int a(4);
    int b=3;
    try{
 
      //通过以下测试，throw可以抛出const char* 、对象、int型等，但要注意，throw抛出的类型一定要和catch捕捉的参数类型一致；
      //try抛出异常后，catch捕捉异常，从第一个catch一直找到对应的抛出的异常类型，执行里面的代码。
      //if (a>b) throw "比较错误";

     if(a>b){
        throw runtime_error("比较错误"); // runtime_error构造函数的参数类型只能是const char *
      }
     
     
     //if(a>b) throw 9;
    }
    catch(const char*  e){    //catch中参数类型应和throw抛出类型一致
        //perror(e)；
        cout<<e<<endl;
    }
    catch(runtime_error &err){  //exception是原始基类， 此处可替代exception &err效果是一样的
        cout<<err.what()<<endl;   //err是一个对象，.what()是对象提供的成员函数
    }
    catch(int a){

      cout<<a<<endl;
    }
    system("pause");
}

