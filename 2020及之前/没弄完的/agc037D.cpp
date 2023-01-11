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
//2 3
//1 3
//2 1


*/
const int N=105;
int n,s,t,m;
int a[N][N],b[N][N],c[N][N],pd[N][N],from[N];
//from[i] 记录颜色 i 在哪一行出现  
int getColor(int x)
{
	return (x-1)/m+1;
}
void solve(int x)
{
	memset(from,0,sizeof(from));
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(pd[i][j]||from[getColor(a[i][j])])continue;
			b[i][x]=a[i][j],pd[i][j]=1;
			from[g.etColor(b[i][x])]=i;
			break;
		}
		if(b[i][x]==0)
		{
			int now=i,first=0,p=1;
			do
			{
				for(j=1;j<=m;j++)
				{
					if(pd[now][j])continue;
					if(first==0)first=a[now][j];
					if(from[getColor(a[now][j])]==0)
					first=a[now][j],p=0;
				}
				b[now][x]=first;int tmp=now;
				now=from[getColor(first)];
				from[getColor(first)]=tmp;
			}while(p);
		}
	}
	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int i,j;
	read(n),read(m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(a[i][j]); 
	
	for(i=1;i<=m;i++)
	solve(i);
	
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		int col=getColor(b[i][j]);
		c[col][j]=b[i][j];
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		printf("%d ",b[i][j]);
		
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		printf("%d ",c[i][j]);
	
		printf("\n");
	}
	return 0;
}

