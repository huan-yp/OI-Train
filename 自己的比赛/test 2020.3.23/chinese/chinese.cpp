#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
string sm[100],ym[100],a;
string hf[6000];
int main()
{
	freopen("chinese.in","r",stdin);
	freopen("chinese.out","w",stdout);
	sm[1]="b";
	sm[2]="p";
	sm[3]="m";
	sm[4]="f";
	sm[5]="d";
	sm[6]="t";
	sm[7]="n";
	sm[8]="l";
	sm[9]="g";
	sm[10]="k";
	sm[11]="h";
	sm[12]="j";
	sm[13]="q";
	sm[14]="x";
	sm[15]="zh";
	sm[16]="ch";
	sm[17]="sh";
	sm[18]="r";
	sm[19]="z";
	sm[20]="c";
	sm[21]="s";
	sm[22]="y";
	sm[23]="w";
	ym[1]="a";
	ym[2]="o";
	ym[3]="i";
	ym[4]="u";
	ym[5]="v";
	ym[6]="ai";
	ym[7]="ei";
	ym[8]="ui";
	ym[9]="ao";
	ym[10]="ou";
	ym[11]="iu";
	ym[12]="ie";
	ym[13]="ve";
	ym[14]="er";
	ym[15]="an";
	ym[16]="en";
	ym[17]="in";
	ym[18]="un";
	ym[19]="ang";
	ym[20]="eng";
	ym[21]="ing";
	ym[22]="ong";
	ym[23]= "vn";
	for(i=1;i<=23;i++)
	for(j=1;j<=23;j++)
	hf[++s]=sm[j]+ym[i];
	while(cin>>a)
	{
		if(a.length()>5)
		i=s+1;
		else
		for(i=1;i<=s;i++)
		if(a==hf[i])
		{
		cout<<"yes"<<endl;
		break;
		}
		if(i==s+1)
		cout<<"no"<<endl;
	}
	return 0;
}
