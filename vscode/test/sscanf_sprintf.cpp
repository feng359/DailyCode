#include<iostream>

using namespace std;

int main(){



    //sscanf和sprintf输入输出的对象是字符串
    int year,month,day,hour,minute,second;
    //要分离出部分指定的数据，则当中没指定的应当在format中原样写出；下面分离时不想要//和--以及 ： 符号，则应在相应位置原样写出
   
   /*  char *arr = "2022//7--14 11:42:33";
    sscanf(arr,"%d//%d--%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second); */
    
    sscanf("2022//7--14 11:42:33","%d//%d--%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second); 
    printf("time = %d-%d-%d %d:%d:%d\n",year,month,day,hour,minute,second);
    char buf[100];
    sprintf(buf,"姓名：%s,小时为[%d],分钟为[%d],秒数为[%d]","张三",hour,minute,second);//字符和数字等不同的格式组成字符串
    puts(buf);
    system("pause");
    return 0;
}




/* time = 2022-7-14 11:42:33
小时为[11],分钟为[42],秒数为[33] */