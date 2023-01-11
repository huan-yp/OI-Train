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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
定义 pd[i] 为通过拆解 i 可以获取到的 sg 值的集合 
转移 pd[i] 即可 

*/
const int N=1<<9;
int i,j,k,n,s,t,m;
int sg[N],pd[N][N],ass[N][N];
signed main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<=300;i++)
	{
		for(j=1;j<i;j++)
		{
			for(k=0;k<1<<9;k++)
			pd[i][k^sg[j]]|=pd[i-j][k];
			pd[i][sg[j]^sg[i-j]]=1;
		}
		for(j=0;j<1<<9;j++)
		ass[i][j]|=pd[i][j];
		for(j=0;j<i;j++)
		ass[i][sg[j]]=1;
		for(j=0;j<1<<9;j++)
		if(ass[i][j]==0)break;
		sg[i]=j;
	}
	read(t);
	while(t--)
	{
		int now=0,x;
		read(n);
		for(i=1;i<=n;i++)	
		read(x),now^=sg[x];
		
		if(now)
		printf("Alice\n");
		else
		printf("Bob\n");
	}

	return 0;
}

