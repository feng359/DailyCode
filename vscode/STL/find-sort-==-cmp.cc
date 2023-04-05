#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using person = struct p{
    string name;
    int age;
};
//上面c++中此处using用法和c中type用法一样
/* typedef struct p{
    string name;
    int age;
}person;
 */

//查找元素find的第三个参数是自定义(结构体、类等非内置类型)需要重载==
bool operator==(person a,person b){     
    return (a.name== b.name && a.age == b.age);
}

//比较的元素是自定义，需要指明比较方式，此处按照年龄从下到大排序
bool cmp(person A,person B){
    return (A.age<B.age);
}


int main(){ 

    char arr[9] = {4,5,1,3,4,8,4,9,7};
    vector<int> vec(arr,arr+9);
    auto it  = find(vec.begin(),vec.end(),4);
    while(it != vec.end()){
        
        cout<<"存在此元素: "<<*it<<endl;
        it = find(++it,vec.end(),4);
    }


    auto ite= find_if(vec.begin(),vec.end(),[](int val){return val>5;});
    if(ite == vec.end()) cout<<"查无此值！"<<endl;
    while(ite != vec.end()){    
        cout<<"存在大于5的元素: "<<*ite<<endl;
        ite = find_if(++ite,vec.end(),[](int val){return val>5;});
    }
   
    person p[3] = {{"lihua",34},{"jingjing",24},{"taohong",27}};
    person one = {"jingjing",24};

   auto it1 =  find(p,p+3,one);
   if(it1 != p+3){
    cout<<"name: "<<it1->name<<" "<<"age: "<<it1->age<<endl;
   }

    cout<<"sort: ";
    sort(p,p+3,cmp);
    for(size_t idx = 0;idx<3;idx++){
        cout<<p[idx].name<<" "<<p[idx].age<<endl;

    }    


    system("pause");
    return 0;
}