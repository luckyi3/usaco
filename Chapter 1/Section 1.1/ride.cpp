/*
 ID: luckyi31
 PROG: ride
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char comet[10], group[10];
    fin>>comet>>group;
    int a = 1, b = 1;
    char tmp = 0;
    int i = 0;
    while((tmp = comet[i++]) != 0) {
        a *= (tmp - 'A' + 1);
        a %= 47;
    }
    tmp = 0;
    i = 0;
    while((tmp = group[i++]) != 0) {
        b *= (tmp - 'A' + 1);
        b %= 47;
    }
    if(a == b)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;

    return 0;
}
