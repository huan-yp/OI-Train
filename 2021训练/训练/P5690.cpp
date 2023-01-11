#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int change(int x,int y)
{
	int g[3],f[3];
	g[1]=x%10,g[2]=x/10,f[1]=y%10,f[2]=y/10;
	return (g[1]!=f[1])+(g[2]!=f[2]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	s=10;
	for(i=1;i<=12;i++)
	{	
		for(j=1;j<=month[i];j++)
		cmin(s,change(n,i)+change(m,j));
	}
	cout<<s<<endl;
	return 0;
}

