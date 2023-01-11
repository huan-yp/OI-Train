#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N = 2e7+10 ,mod = 1e9+7;
int i,j,k,m,n,s,t;
int p[N],dp[N];
int quick(int a,int s)
{
	int now=a;
	if(p[a])return p[a];
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return p[now]=ret;
}
void Dec(int &x,int y)
{
	x-=y;if(x<0)x+=mod;
}
void Inc(int &x,int y)
{
	x+=y;if(x>=mod)x-=mod;
}
void solve()
{
	for(int i=k;i>=1;i--)
	{
		dp[i]=quick((2*(k/i)+1),n);
		Dec(dp[i],1);
		for(j=2;j*i<=k;j++)
		Dec(dp[i],dp[i*j]);
	}
	cout<<(dp[1]+1)%mod<<endl;
}
signed main()
{
	read(n),read(k);
	solve();
	return 0;
}

