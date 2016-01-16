/*
ID: luckyi31
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 15;
int ctoi(char a)
{
    if(a - 'A' == 18 || a - 'A' == 21 || a - 'A' == 24)
        return (a-'A')/3+1;
    return (a-'A')/3+2;
}
char in[N], tmp[N];
vector<string> out;
int main()
{
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream namefile("dict.txt");
    fin>>in;
    int len = strlen(in);
    while(namefile>>tmp)
    {
        if(strlen(tmp) == len)
        {
            int i = 0, flag = 1;
            while(i < len && (ctoi(tmp[i]) == (in[i] - '0')))
               i++;
            if(i == len)
                out.push_back(tmp);
            /*for(i = 0; i < len; i++)
                if(ctoi(tmp[i]) != (in[i] - '0'))
                    flag = 0;
            if(flag == 1)
                out.push_back(tmp);*/
        }
    }
    if(out.size() == 0)
        fout<<"NONE"<<endl;
    sort(out.begin(), out.end());
    for(int j = 0; j < out.size(); j++)
    fout<<out.at(j)<<endl;
    return 0;
}
