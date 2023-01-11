#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m;
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss)
		ret=ret*aa;
		aa=aa*aa;
		ss>>=1;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int a,b,c;
	cin>>a>>b>>c;
	if(abs(a)==abs(b))
	{
		if(c%2==0||a==b)
		printf("=");
		else
		if(a>b)
		printf(">");
		else
		printf("<");
	}
	else
	{
		if(c%2==0)
		{
			if(abs(a)>abs(b))
			printf(">");
			else
			printf("<");
		}
		else
		{
			if(a>b)
			printf(">");
			else
			printf("<");
		}
	}
	return 0;
}


