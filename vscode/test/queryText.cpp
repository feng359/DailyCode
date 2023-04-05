#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

class WordCount
{

public:
    void readFile(const char *filename);
    void writeFile(const char *filename);

private:
    map<string, int> m;
};

void WordCount::readFile(const char *filename)
{
    ifstream ifs(filename);
    if (!ifs.good())
    {
        cout << "ifstream open file error! " << endl;
    }

    string word;
    while (ifs >> word)
    {
        for(size_t i = 0;i<word.length();i++){  //将单词中的大写字符转换为小写字符
            if(isalpha(word[i])){
                if(isupper(word[i])){
                    word[i] = tolower(word[i]);
                }
            }
        }

        size_t id = word.length();
        if (isalpha(word[id--])) //单词的最后一个字符是字符，则是尾部不带标点符号单词，不必去除存入即可
        {
            m[word]++;
        }
        else
        {
            word.erase(id--);//单词的最后一个字符若不是字符，则是标点符号，需要除去
            m[word]++;
        }
    }
}

void WordCount::writeFile(const char *filename)
{
    ofstream ofs(filename);
    if (!ofs.good())
    {
        cout << "ofstream open file error!" << endl;
    }

    int count = 0;
    for_each(m.begin(), m.end(), [&ofs, &count](pair<string, int> mp) mutable
             { ofs<<mp.first<<" "<<mp.second<<endl;count+=mp.second; });
    cout << "文章单词总共有: " << count << "个" << endl;
}

int main(int argc, char *argv[]) //或char **argv
{

    if (3 != argc)
    {
        cout << "参数不足！" << endl;
    }
    
    WordCount w;
    time_t begin, end;

    time(&begin);
    w.readFile(argv[1]);  //argv[1]是程序运行的第二个参数，文章路径eg：C:\\..\\..\\tmp.txt,也可直接写成w.readFile("C:\\..\\..\\tmp.txt")，则程序运行时不用再输入参数
    w.writeFile(argv[2]); //argv[2]是程序运行的第三个参数，表示统计词频后存入的文章位置
    time(&end);
    cout << "处理时间总计为: " << begin - end << endl;
    
    system("pause");
    return 0;
}
