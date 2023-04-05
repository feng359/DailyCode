#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void print(pair<int, string> m) //?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?0?2?1?7?1?7?1?7map?1?7?1?7?1?7?1?7?1?7?1?7?0?6?1?7?1?7?1?7?1?7?1?7?0?5?1?7map?1?7?1?7?1?7?1?7?1?7?1?7?0?6?1?7?1?7?1?7?1?7?1?7?1?7?1?7?0?3?1?7?0?5?1?7?1?7pair
{
    cout << "?1?7?1?7?1?7 " << m.first << "?1?7?1?7?1?7?1?7?1?7?1?7 " << m.second << endl;
}  

int main()
{

    // map?1?7?1?7?1?7?0?8?1?7?0?5?1?7?1?7?0?4?1?7?1?7?1?7?1?7?1?7?0?8?1?7insert?1?7?1?7?1?7��?1?7

    //?0?0?1?7?0?0?1?7?1?7?1?7?1?7?0?5?1?7?0?3?1?7?1?7
    map<int, string> m = {pair<int, string>(2014, "?1?7?1?7?1?7?1?7"),
                          pair<int, string>(2010, "wangdachui")};

    //?1?7?1?7?1?7?1?7?1?7?0?5?1?7?0?0?1?7?0?5
    /*  m.insert(pair<int,string>(2012,"?1?7?1?7?1?7?1?7"));
     m.insert(pair<int,string>(2014,"?1?7?1?7?1?7?1?7"));
     m.insert(pair<int,string>(2010,"wangdachui")); */

    //?1?7��?8?8?0?5
    m[2013] = "jingjing";

    // find?0?0?1?7?1?7 --?1?7?1?7map?1?7?1?7?1?7?1?4?1?7?1?7?0?9?1?7?0?6?1?7?1?5?1?7?1?7?1?7find?1?7?1?7?1?7?1?3?0?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?0?8?1?7?1?7map?1?7?0?5?1?7��end
    auto it1 = m.find(2013);
    if (it1 != m.end())
        cout << "?1?7?1?7?1?7 " << it1->first << "?1?7?1?7?1?7?1?7?1?7?1?7 " << it1->second << endl
             << endl;

    cout << "?1?7��?1?7?1?7?1?7?0?8?1?7m[2014] = " << m[2014] << endl
         << endl;

    cout << "before erase m.size() = " << m.size() << endl;
    cout << "m.erase(2010)" << endl;
    m.erase(2010);
    cout << "after erase m.size() = " << m.size() << endl;

    cout << endl;
    cout << "?0?0?1?7?1?7for?1?7?1?7?1?7?1?7map" << endl;
    //?1?7?1?7?1?7?1?7elem?1?7?1?7?1?7?1?7?1?7?1?7m?1?7?1?7?0?6?1?7?1?7,?1?7?1?7?1?7?1?7?1?7?1?7?0?2?1?7?1?7?1?7?1?7m?1?7?1?7?0?6?1?7?1?7?1?7?1?7?1?7?0?0?1?7?0?5?1?7?1?7pair,?1?7?1?7?1?7?1?7?1?7?1?7?0?2for(pair<int,string> elem: m);
    for (auto elem : m)
    { //?0?8?1?7?1?7?0?8?1?7?1?7?1?7?1?7?1?7?1?7��?1?7?0?6?1?7?1?5?1?7?1?7?1?7?1?7?1?7?1?7?1?7?0?0?1?7for(auto &elem: m);?1?7?1?7?1?7?1?7?1?7?1?7?0?6?1?7?1?0?1?7const;for(const auto elem: m)
        cout << "?1?7?1?7?1?7 " << elem.first << "?1?7?1?7?1?7?1?7?1?7?1?7 " << elem.second << endl;
    }

    cout << endl;
    cout << "?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7map?1?7?1?7" << endl;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << "?1?7?1?7?1?7 " << iter->first << "?1?7?1?7?1?7?1?7?1?7?1?7 " << iter->second << endl;
    }

    cout << endl;
    cout << "?0?0?1?7?1?7for_each?1?7?1?7?1?7?1?7map" << endl;
    for_each(m.begin(), m.end(), print);  
    
    cout << endl;
    cout << "for_each?1?7?1?7?0?0?1?7?1?7lambda?1?7?1?7?1?7?1?7map" << endl;
    for_each(m.begin(), m.end(), [](pair<int,string> x){cout<<"?1?7?1?7?1?7 "<<x.first<<"?1?7?1?7?1?7?1?7?1?7?1?7"<<x.second<<endl;});
    cout<<endl;  
    
    system("pause");
    return 0;
}
//?0?4?1?7��?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?0?5?1?7?1?7

/* ?1?7?1?7?1?7 2013?1?7?1?7?1?7?1?7?1?7?1?7 jingjing

?1?7��?1?7?1?7?1?7?0?8?1?7m[2014] = ?1?7?1?7?1?7?1?7

before erase m.size() = 3
m.erase(2010)
after erase m.size() = 2

?0?0?1?7?1?7for?1?7?1?7?1?7?1?7map
?1?7?1?7?1?7 2013?1?7?1?7?1?7?1?7?1?7?1?7 jingjing
?1?7?1?7?1?7 2014?1?7?1?7?1?7?1?7?1?7?1?7 ?1?7?1?7?1?7?1?7

?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7map?1?7?1?7
?1?7?1?7?1?7 2013?1?7?1?7?1?7?1?7?1?7?1?7 jingjing
?1?7?1?7?1?7 2014?1?7?1?7?1?7?1?7?1?7?1?7 ?1?7?1?7?1?7?1?7

?0?0?1?7?1?7for_each?1?7?1?7?1?7?1?7map
?1?7?1?7?1?7 2013?1?7?1?7?1?7?1?7?1?7?1?7 jingjing
?1?7?1?7?1?7 2014?1?7?1?7?1?7?1?7?1?7?1?7 ?1?7?1?7?1?7?1?7
?1?7?0?3?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7?1?7. . . */