#include <iostream>
#include <cstring>
using namespace std;


class String{

public:
    String(const char *str);
    String(const String &obj);
    ~String();
    String& operator=(const String &other);
    void print();
private:
    char *info;
};



String::String(const char *str){

    cout<<"String(const char *str)"<<endl;
    if(NULL == str){
        info = new char[1];
        *info = '\0';
    }
    else
    {
        int len = strlen(str);
        info = new char[len+1]; //也可上面两步合为一步：info = new char[strlen(str)+1]
        strcpy(info,str);
    }
}

String:: String(const String &obj){
    cout<<"String(const String &obj)"<<endl;
    int len = strlen(obj.info);
    info = new char[len+1];  
    strcpy(info,obj.info);
}

String::  ~String(){
    cout<<"~String()"<<endl;
    if(info)
    delete [] info;
}

String& String::operator=(const String &other){
    cout<<"operator=(const String &other)"<<endl;
    if(&other == this){ //是否是自己给自己赋值  --注意：this值保存的是对象的地址，*this才是指向的对象本身。
        return *this;
    }   
    else{
        delete [] info; //清理自己的空间，防止在此之前有数据，导致赋值时出错
        int len = strlen(other.info);
        info = new char[len+1];
        strcpy(info,other.info);
        return *this;
    } 
}


void String::print(){

    cout<<info<<endl;
}

int main(){
   
    String str1("hello");
    cout<<"str1 = ";
    str1.print();
    cout<<"String str2 = str1"<<endl;
    String str2 = str1;
    cout<<"str2 = ";
    str2.print();
    String str3 = {"world"};
    cout<<"str3 = ";
    str3.print();
    str2 = str3;
    cout<<"str2 = str3"<<endl;
    cout<<"str2 = ";
    str2.print();
    cout<<"str3 = ";
    str3.print();
    system("pause");
    return 0;    
}