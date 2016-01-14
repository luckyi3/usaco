/*
 ID: luckyi31
 PROG: friday
 LANG: C++
 */

#include <iostream>
#include <string>
#include <fstream>
//#define fin cin
//#define fout cout

using namespace std;

int times[10];

int isleapyear(int year)
{
    return year % 100 ? year % 4:year % 400;
}

int main(int argc, const char * argv[])
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    
    int n, day = 2 + 13 - 1;
    fin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            day %= 7;
            cout<<day<<endl;
            times[day]++;
            if (j == 2)
            {
                if (isleapyear(1900 + i) == 0)
                    day += 29;
                else
                    day += 28;
            }
            if (j == 4 || j == 6 || j == 9 || j == 11)
                day += 30;
            if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
                day += 31;
        }
        cout<<endl;
    }
    for (int i = 0; i < 7; i++)
    {
        if(i == 0)
            fout<<times[i];
        else
            fout<<" "<<times[i];
    }
    fout<<endl;
    
    return 0;
}
