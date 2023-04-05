#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // map和键值对的基本用法

    // 1-map会按照key进行排序；2-key不可重复，value可以重复。
    //大括号键值对初始化。 键值对的两种写法如下：pair的用法：pair<string,int> p = ("莉莉"，87)  p.first  p.second,下面使用了匿名pair
    map<string, int> m = {pair<string, int>("莉莉", 87),
                          make_pair("杰瑞", 76),
                          make_pair("林华", 76)};
    //下标赋值或者输出值。
    m["付珍"] = 83;

    //插入时也要插入键值对
    m.insert(pair<string, int>("昭阳", 94)); //或者m.insert(make_pair("昭阳"，94));

    for_each(m.begin(), m.end(), [](pair<string, int> m)
             { cout << m.first << " " << m.second << endl; }); // map的参数类型是键值对。
    cout << endl;

    cout << "find查找是否有 付珍 这个人" << endl;
    auto it = m.find("付珍"); // map有find(key)成员函数,vector没有。
    if (it != m.end())
    {
        cout << "经过查找存在付珍这个人,对应的分数为：" << it->second << endl
             << endl;
    }
    else
    {
        cout << "经过查找不存在付珍这个人" << endl
             << endl;
    }

 

    //boost-容器的嵌套复杂使用
    //重点：对于嵌套的容器，要从内往外初始化，遍历时从外往内进行遍历，遍历时对于嵌套的元素要按照开始定义时的元素类型来接收，再取这个接受的容器迭代器操作元素
    
    // vector嵌套map
    // vecto中元素使用同一个map,而map中元素也一次比一次多，因此每次遍历voctor元素时，还需要对map中元素进行遍历
    vector<map<string, int>> vec;
    map<string, int> mm;
    mm.insert(pair<string, int>("莉莉", 87));
    vec.push_back(mm); // vector的第一个map元素此时只有莉莉
    mm.insert(pair<string, int>("杰瑞", 76));
    vec.push_back(mm); // vector的第二个map元素此时有莉莉、杰瑞
    mm.insert(pair<string, int>("林华", 97));
    vec.push_back(mm); // vector的第三个map元素中有莉莉，杰瑞和林华   --、如果要使一个元素map中只有一个元素，则每次都创建一个map，而不用像本次中使用了同一个map，导致元素不断增多

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        //下面一行也可直接简写为auto tmpMap = *it
        map<string, int> tmpMap = *it; // it表示指向vector中某个元素这个位置，*it表示某个元素本身，此处是指map容器，而不是map容器的键值对元素，对键值对元素遍历时，键值对元素才有first和second成员。
        for (auto ite = tmpMap.begin(); ite != tmpMap.end(); ite++)
        {
            cout << "vector-map.first: " << ite->first << " second: " << ite->second << endl;
        }
        cout << endl;
    }
    cout << endl;

    // vector中元素是同类型的不同map，而每个map中元素都是一个，则遍历vector元素时不必对map进行遍历。
    vector<map<string, int>> vec1;
    map<string, int> m1;
    m1.insert(pair<string, int>("莉莉", 87));
    vec1.push_back(m1); // vec1tor的第一个map元素只有莉莉

    map<string, int> m2;
    m2.insert(pair<string, int>("杰瑞", 76));
    vec1.push_back(m2); // vec1tor的第二个map元素只有杰瑞

    map<string, int> m3;
    m3.insert(pair<string, int>("林华", 97));
    vec1.push_back(m3); // vec1tor的第三个map元素此时林华   --、如果要使一个元素map中只有一个元素

    for (auto it = vec1.begin(); it != vec1.end(); it++)
    {
        map<string, int> tmpMap = *it; // vector中元素是map容器，先用同类型的tmpMap接收vector中元素map容器，(tmpMap.first是错误的写法，tmpMap是容器，没有first成员，只有map容器中的元素键值对才有first和second成员)。
        auto ite = tmpMap.begin();     //由于vector中元素map中的元素个数都是一个，故没必要用for循环遍历。
        cout << "vector-map.first: " << ite->first << "\t second: " << ite->second << endl;
    }
    cout << endl;

    // map嵌套map

    map<int, map<string, int>> m4;
    map<string, int> mm1 = {make_pair("珍妮", 23)};
    m4.insert(make_pair(1, mm1));

    map<string, int> mm2 = {make_pair("泰勒", 32)};
    m4.insert(make_pair(3, mm2));

    map<string, int> mm3 = {make_pair("福瑞", 24)};
    m4.insert(make_pair(2, mm3));

    for (auto it = m4.begin(); it != m4.end(); it++)
    {
        map<string, int> tmpMap = it->second;
        auto ite = tmpMap.begin();
        cout << "map-map.first: " << it->first << "\tsecond.first: " << ite->first << "\tsecond.second: " << ite->second << endl;
    }
    cout << endl;


    // map嵌套vector--某人对应的各科成绩

    map<string, vector<int>> m5;

    vector<int> vv1 = {34, 22, 77, 44, 85};
    m5.insert(make_pair("静静", vv1));

    vector<int> vv2 = {56, 21, 47, 89, 78};
    m5.insert(make_pair("洋洋", vv2));

    vector<int> vv3 = {34, 22, 77, 44, 85};
    m5.insert(make_pair("蝴蝶", vv3));

    for (auto it = m5.begin(); it != m5.end(); it++)
    {
        cout << "map-vector.first: " << it->first << "\tmap-vector.second: ";
        auto tmpVec = it->second; //完整的写法：vector<int> tmpVec = it->second
        for (auto ite = tmpVec.begin(); ite != tmpVec.end(); ite++)
        {
            cout << *ite << " ";
        }
        cout << endl;
    }
    cout << endl;

    // map嵌套map再嵌套vevtor 国家-姓名-成绩
    map<string, map<string, vector<int>>> mmmm;
    vector<int> vvv1 = {67, 22, 88, 44, 98};
    map<string, vector<int>> mmm1;
    mmm1.insert(make_pair("长泽雅", vvv1));
    mmmm.insert(make_pair("日本", mmm1));

    vector<int> vvv2 = {78, 84, 34, 97, 45};
    map<string, vector<int>> mmm2;
    mmm2.insert(make_pair("金泫雅", vvv2));
    mmmm.insert(make_pair("韩国", mmm2));

    vector<int> vvv3 = {88, 90, 78, 99, 84};
    map<string, vector<int>> mmm3;
    mmm3.insert(make_pair("陈莉娟", vvv3));
    mmmm.insert(make_pair("中国", mmm3));

    for (auto it1 = mmmm.begin(); it1 != mmmm.end(); it1++) //容器map有多个元素，需要进行for遍历
    {

        map<string, vector<int>> tmpMap = it1->second;
        auto it2 = tmpMap.begin(); //嵌套的map只有一个元素,没必要进行for遍历，直接取结果即可。
        cout << "map.first: " << it1->first << "\t\tmap-map.first: " << it2->first << " "<< "\t\tmap-map-vector: ";
        vector<int> tmpVec = it2->second;
        for (auto it3 = tmpVec.begin(); it3 != tmpVec.end(); it3++) // vector含有多个元素，需要进行for遍历
        {     
            cout << *it3 << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}


//运行结果如下所示：
/* 付珍 83
杰瑞 76
莉莉 87
林华 76
昭阳 94

find查找是否有 付珍 这个人
经过查找存在付珍这个人,对应的分数为：83

vector-map.first: 莉莉 second: 87

vector-map.first: 杰瑞 second: 76
vector-map.first: 莉莉 second: 87

vector-map.first: 杰瑞 second: 76
vector-map.first: 莉莉 second: 87
vector-map.first: 林华 second: 97


vector-map.first: 莉莉   second: 87
vector-map.first: 杰瑞   second: 76
vector-map.first: 林华   second: 97

map-map.first: 1        second.first: 珍妮      second.second: 23
map-map.first: 2        second.first: 福瑞      second.second: 24
map-map.first: 3        second.first: 泰勒      second.second: 32

map-vector.first: 蝴蝶  map-vector.second: 34 22 77 44 85
map-vector.first: 静静  map-vector.second: 34 22 77 44 85
map-vector.first: 洋洋  map-vector.second: 56 21 47 89 78

map.first: 韩国         map-map.first: 金泫雅           map-map-vector: 78 84 34 97 45
map.first: 日本         map-map.first: 长泽雅           map-map-vector: 67 22 88 44 98
map.first: 中国         map-map.first: 陈莉娟           map-map-vector: 88 90 78 99 84
 */