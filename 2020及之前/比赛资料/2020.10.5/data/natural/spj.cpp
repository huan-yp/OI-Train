#include "testlib.h"
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<bitset>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int T=inf.readInt();
    int cnt=0;
    while (T--){
    	string s1=ouf.readToken();
    	string s2=ans.readToken();
    	if (s1==s2) cnt++;
    }
    quitp(1.0*(cnt/100)/100,"QAQ");
}