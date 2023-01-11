#include "testlib.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int main(int argc,char* argv[])
{
//	registerTestlibCmd(argc,argv);
	registerLemonChecker(argc,argv);
	string s=inf.readToken();
	string t=inf.readToken();
	int u=ouf.readInt(),ss=ans.readInt();
	if(u!=ss) quitf(_wa,"diff answer");
	string g=ouf.readToken();
	while(!ouf.seekEof()) ouf.readToken();
	if(g.size()!=s.size()) quitf(_wa,"invalid string");
	for(int i=0;i<s.size();++i)
	{
		if(s[i]!='?')
		{
			if(g[i]!=s[i]) quitf(_wa,"invalid string");
		}
		else
		{
			if(!islower(g[i])) quitf(_wa,"invalid string");
		}
	}
	ll tg=0,pw=1,cv=0; //xi wang ren mei shi
	for(int j=0;j<t.size();++j)
		pw*=37,tg=tg*37+t[j];
	int cc=0;
	for(int i=0;i<g.size();++i)
	{
		cv=cv*37+g[i];
		if(i>=t.size())
			cv-=g[i-t.size()]*pw;
		if(i+1>=t.size())
		{
			if(tg==cv) ++cc;
		}
	}
	if(cc<u) quitf(_wa,"count doesnt fit");
	if(cc>u) quitf(_ok,"good job (overflow? found %d matches while expecting %d)",cc,u);
	quitf(_ok,"good job");
}
