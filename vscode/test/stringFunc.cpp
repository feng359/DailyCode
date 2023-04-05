#include<iostream>

using namespace std;

int main(){
    string str1 = "hello,world!";
    cout<<"str1 = "<<str1<<endl;

    string str2 = str1.substr(0,6);
    cout<<"str2 = str1.substr(0,6) = "<<str2<<endl;

    string str3 = "world!";
    cout<<"str3 = "<<str3<<endl;
    str2+=str3;
    cout<<"str2+=str3 = "<<str2<<endl;

    cout<<"str2.length = "<<str2.length()<<endl;
    cout<<"str2.size() = "<<str2.size()<<endl;

    cout<<"str1.erase(5) = "<<str1.erase(5)<<endl;
    cout<<"str1.erase(2,2) = "<<str1.erase(2,2)<<endl;
    cout<<"str1.intsert(2,2,'1') = "<<str1.insert(2,2,'l')<<endl;
    cout<<"str1.insert(5,,wld) = "<<str1.insert(5,",wld")<<endl;  //?0?0?1?7?7?4?0?5?1?7?1?7insert?0?6?1?7?1?7pos?0?2?0?5λ?1?7ò?1?7?1?7?0?3?1?7?1?7?1?7?1?7?1?7?0?2?1?7?1?7β?1?7?1?7?1?7?1?7?1?7?0?3?1?7?1?7λ?1?7?0?6?1?7д?1?7?1?7β?0?6?1?7?1?3?1?7?1?7?1?7?0?5λ?1?7?1?7
    cout<<"str1.insert(7,or) = "<<str1.insert(7,"or")<<endl;

    str1+=" girl";
    cout<<"str1 += girl = "<<str1<<endl;
    
    cout<<"str1.find(i,5) = "<<str1.find('i',5)<<endl;
    cout<<"str1.find(llo) = "<<str1.find("llo")<<endl;

    cout<<"str1.replace(12,4,boy) = "<<str1.replace(12,4,"boy")<<endl;
    cout<<"str1.insert(15, girl) = "<<str1.insert(15 ," girl")<<endl;


    system("pause");
    return 0;
}


 //结果如下所示：
/*  str1 = hello,world!
str2 = str1.substr(0,6) = hello,
str3 = world!
str2+=str3 = hello,world!
str2.length = 12
str2.size() = 12
str1.erase(5) = hello
str1.erase(2,2) = heo
str1.intsert(2,2,'1') = hello
str1.insert(5,,wld) = hello,wld
str1.insert(7,or) = hello,world
str1 += girl = hello,world girl
str1.find(i,5) = 13
str1.find(llo) = 2
str1.replace(12,4,boy) = hello,world boy
str1.insert(15, girl) = hello,world boy girl */