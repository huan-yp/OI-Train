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
/*
x1x2
x3x4
x5x6
x1^1=x6
1=x2^x5
1=x3
1=x4
1=x2^x5
1=x6^x1
*/
const int mod=123456789,N=505,M=155;
const int dx[]={0,1,-1,1,-1,-2,2,-2,2},dy[]={0,2,-2,-2,2,-1,-1,1,1};
int i,j,k,n,s,t,m,cnt;
int mp[N][N],pd[N];
bitset<N>val[M][M],eq[N]; 
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)
		ret=1ll*a*ret%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
bool ok(int x,int y)
{
	return x>0&&x<=n&&y>0&&y<=m;
}
void init()
{
	for(i=1;i<=n&&i<=2;i++)
	for(j=1;j<=m;j++)
	val[i][j][++t]=1;
	for(i=3;i<=n;i++)
	for(j=1;j<=1;j++)
	val[i][j][++t]=1;
	
	for(i=1;i<=n-2;i++)
	for(j=1;j<=m-1;j++)
	{
		for(k=0;k<8;k++)
		if(ok(i+dx[k],j+dy[k]))
		val[i+2][j+1]^=val[i+dx[k]][j+dy[k]];
		val[i+2][j+1][0]=val[i+2][j+1][0]^1;
	}
	t=0;
	for(i=max(n-1,1);i<=n;i++)
	for(j=1;j<=m;j++)
	{
		++t;
		for(k=0;k<=8;k++)
		if(ok(i+dx[k],j+dy[k]))
		eq[t]^=val[i+dx[k]][j+dy[k]];
		eq[t][0]=eq[t][0]^1;
	}
	for(i=1;i<=n-2;i++)
	for(j=m;j<=m;j++)
	{
		++t;
		for(k=0;k<=8;k++)
		if(ok(i+dx[k],j+dy[k]))
		eq[t]^=val[i+dx[k]][j+dy[k]];
		eq[t][0]=eq[t][0]^1;
	}
}
void gauss()
{
	for(i=1;i<=t;i++)
	{
		int p=0;
		for(j=1;j<=t;j++)
		if(eq[j][i]&&pd[j]==0)//Attention!!!
		{
			p=j;
			break;
		}
		if(p==0)
		{
			cnt++;
			continue;
		}
		swap(eq[p],eq[i]);
		swap(pd[p],pd[i]);
		pd[i]=1;
		for(j=1;j<=t;j++)
		if(eq[j][i]&&pd[j]==0)//Attention!!
		eq[j]^=eq[i];
	}
}
class KnightsOut{
	public:
	int count(int N, int M)
	{
		n=N,m=M;
		init();
		gauss();
		return quick(2,cnt);
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	KnightsOut solve;
//	cout<<solve.count(3,2);
//	return 0;
//}
