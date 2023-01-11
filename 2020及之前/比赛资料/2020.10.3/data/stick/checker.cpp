#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include"testlib.h"
using namespace std;
struct Num
{
	int _a[1005],*a;
	Num(int x=0)
	{
		a=_a+500;
		memset(_a,0,sizeof(_a));
		a[0]=x;
		int now=0;
		while(a[now]>=10)
		{
			a[now+1]=a[now]/10;
			a[now]%=10;
			now++;
		}
	}
	bool operator<(Num x)
	{
		for(int i=1000;i>=0;i--)
		{
			if(_a[i]<x._a[i])return 1;
			if(_a[i]>x._a[i])return 0;
		}
		return 0;
	}
	Num&operator=(Num x)
	{
		a=_a+500;
		x.a=x._a+500;
		for(int i=0;i<1005;i++)_a[i]=x._a[i];
		return*this;
	}
	Num&operator=(int x)
	{
		a=_a+500;
		memset(_a,0,sizeof(_a));
		a[0]=x;
		return*this;
	}
	Num operator+(Num x)
	{
		a=_a+500;
		x.a=x._a+500;
		Num ans;
		for(int i=-450;i<=450;i++)
		{
			ans.a[i]+=a[i]+x.a[i];
			if(ans.a[i]>=10)ans.a[i]-=10,ans.a[i+1]++;
		}
		return ans;
	}
	Num operator-(Num x)
	{
		a=_a+500;
		x.a=x._a+500;
		Num ans;
		for(int i=-450;i<=450;i++)
		{
			ans.a[i]+=a[i]-x.a[i];
			if(ans.a[i]<0)ans.a[i]+=10,ans.a[i+1]--;
		}
		return ans;
	}
	Num operator+(int x)
	{
		return *this+Num(x);
	}
	Num operator/(int x)
	{
		a=_a+500;
		Num ans;
		for(int i=450;i>=-450;i--)
		{
			ans.a[i]+=a[i];
			ans.a[i-1]+=ans.a[i]%x*10;
			ans.a[i]/=x;
		}
		return ans;
	}
}a,b,v;
void print(Num x)
{
	x.a=x._a+500;
	bool flag=0;
	for(int i=450;i>=0;i--)
	{
		if(x.a[i])flag=1;
		if(flag)printf("%d",x.a[i]);
	}
	if(!flag)printf("0");
	printf(".");
	for(int i=-1;i>=-100;i--)printf("%d",x.a[i]);
}
string s,t;
void in()
{
	memset(a._a,0,sizeof(a._a));
	memset(b._a,0,sizeof(b._a));
	int m=s.length();
	int p=0;
	while(p<m&&s[p]!='.')p++;
	if(p>=m)
	{
		for(int i=0;i<m;i++)
		  a.a[i]=s[m-i-1]-'0';
	}
	else
	{
		for(int i=0;i<p;i++)
		  a.a[i]=s[p-i-1]-'0';
		for(int i=p+1;i<m;i++)
		  a.a[-(i-p)]=s[i]-'0';
	}
	m=t.length();
	p=0;
	while(p<m&&t[p]!='.')p++;
	if(p>m)
	{
		for(int i=0;i<m;i++)
		  b.a[i]=t[m-i-1]-'0';
	}
	else
	{
		for(int i=0;i<p;i++)
		  b.a[i]=t[p-i-1]-'0';
		for(int i=p+1;i<m;i++)
		  b.a[-(i-p)]=t[i]-'0';
	}
}
int main(int argc,char*argv[])
{
	registerLemonChecker(argc,argv);
	int c=inf.readInt();
	int tt=inf.readInt();
	while(tt--)
	{
		s=ouf.readToken();
		t=ans.readToken();
		in();
		if(a<b)v=b-a;
		else v=a-b;
		for(int i=1000;i>=c;i--)v._a[i]=v._a[i-c];
		if(!(v<b||v<Num(1)))quitf(_wa,"Wrong Answer");
		s=ouf.readToken();
		t=ans.readToken();
		in();
		if(a<b)v=b-a;
		else v=a-b;
		for(int i=1000;i>=c;i--)v._a[i]=v._a[i-c];
		if(!(v<b||v<Num(1)))quitf(_wa,"Wrong Answer");
	}
	quitf(_ok,"Accept");
	return 0;
}
