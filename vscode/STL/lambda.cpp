#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(int x){

    cout<<x<<" ";
}

int main(){

    vector<int> vec;
    for(size_t idx = 0; idx<9; idx++){
        vec.push_back(rand()%100);
    }
    cout<<"vector初始元素为: ";
    for_each(vec.begin(),vec.end(),[](int x){cout<<x<<" ";}); 
    cout<<endl;

    transform(vec.begin(),vec.end(),vec.begin(),[](int x){return x+5;});
    cout<<"vector进行transform后元素为: ";
    for_each(vec.begin(),vec.end(),[](int x){cout<<x<<" ";});
    cout<<endl;

    vector<int> vec1(vec);
    cout<<"vec1元素为：";
    for_each(vec1.begin(),vec1.end(),[](int x){cout<<x<<" ";});
    cout<<endl;
    
    transform(vec.begin(),vec.end(),vec1.begin(),vec.begin(),[](int x,int y){return x+y;});
    cout<<"vec和vec1进行+操作后vec元素为：";
    for_each(vec.begin(),vec.end(),[](int x){cout<<x<<" ";});
    cout<<endl;

    system("pause");
    return 0;
}



/* vector初始元素为: 41 67 34 0 69 24 78 58 62
vector进行transform后元素为: 46 72 39 5 74 29 83 63 67
vec1元素为：46 72 39 5 74 29 83 63 67
vec和vec1进行+操作后vec元素为：92 144 78 10 148 58 166 126 134
请按任意键继续. . .
 */