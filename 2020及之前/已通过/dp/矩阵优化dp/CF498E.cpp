#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline int read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m;
const int mod=1e9+7;
const int N=7e3+10;
struct matri{
	int n,m,num[128][128];
	friend matri operator *(matri aa,matri bb)
	{
		matri ret;
		ret.n=bb.n,ret.m=aa.m;
		for(int i=0;i<=ret.n;i++)
		for(int j=0;j<=ret.m;j++)
		{
			ret.num[i][j]=0;
			for(int k=0;k<=aa.n;k++)
			ret.num[i][j]=(ret.num[i][j]+1ll*aa.num[k][j]*bb.num[i][k]%mod)%mod;
		}
		return ret;
	}
}E,Z,S,Ans;
int w[10];
inline void quick(matri &ret,matri aa,int ss)
{
	while(ss)
	{
		if(ss&1)
		ret=ret*aa;
		aa=aa*aa;
		ss>>=1;
	}
}
int dp[N][128],p[128][128];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	matri Ans;
	Ans.n=127,S.n=S.m;
	for(i=0;i<=127;i++)
	E.num[i][i]=1;
	int maxn=0;
	for(i=1;i<=7;i++)
	{
		read(w[i]);
		if(w[i])maxn=i;
	}
	int now=0,tmp=0;
	if(w[1]==0)
	dp[now][1]=1;
	else
	dp[now][0]=1;
	p[0][0]=p[1][0]=p[0][1]=1;
	for(i=1;i<=maxn;i++)
	{
		tmp|=1<<i;
		if(w[i])
		{
			Ans.n=S.n=S.m=(1<<i)-1;
			for(int j=0;j<1<<i;j++)
			Ans.num[j][0]=dp[now][j];
			for(int j=0;j<1<<i;j++)
			for(int k=0;k<1<<i;k++)
			S.num[j][k]=p[j][k];
			quick(Ans,S,w[i]-1);
			for(int j=0;j<1<<i;j++)
			dp[now][j]=Ans.num[j][0];
		}
		memset(p,0,sizeof(p));
		if(w[i+1])
		{	
			now++;
			for(k=0;k<1<<(i+1);k++)
			for(s=0;s<1<<i;s++)
			for(j=0;j<1<<(i+1);j++)
			{
				if(!(j&k&(s|(1<<i))&((s<<1)|1)))
				p[j][k]++;
				if(!((j|tmp)&k&(s|(1<<i))&((s<<1)|1)))
				dp[now][k]=(dp[now][k]+dp[now-1][j])%mod;
			}
			tmp=1<<i+1;
		}
	}
	printf("%d",dp[now][(1<<maxn)-1]);
	return 0;
}
