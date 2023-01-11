#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".ans").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,C[1001][1001],fac[100001],inv[100001];
std::vector<int> v;
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=m;
		(x*=x)%=m;
		y>>=1;
	}
	return res;
}
int c(int x,int y)
{
	if(x<y)
		return 0;
	return fac[x]*inv[y]%m*inv[x-y]%m;
}
int lucas(int x,int y)
{
	if(!y)
		return 1%m;
	return c(x%m,y%m)*lucas(x/m,y/m)%m;
}
signed main()
{
	fileio("random");
	n=read();
	m=read();
	if(n<=1000)
	{
		C[0][0]=1;
		for(int i=1;i<n;i++)
		{
			C[i][0]=1;
			for(int l=1;l<=i;l++)
				C[i][l]=(C[i-1][l]+C[i-1][l-1])%m;
		}
		for(int i=0;i<n;i++)
			if(!C[n-1][i])
				v.push_back(i);
	}
	else
	{	
		fac[0]=inv[0]=inv[1]=1;
		for(int i=1;i<=100000;i++)
			fac[i]=fac[i-1]*i%m;
		for(int i=2;i<=100000;i++)
			inv[i]=m-m/i*inv[m%i]%m;
		for(int i=2;i<=100000;i++)
			(inv[i]*=inv[i-1])%=m;
		if(m>n)
		{
			puts("0");
			return 0;
		}
		for(int i=0;i<n;i++)
			if(!lucas(n-1,i))
				v.push_back(i);
	}
	cout<<v.size()<<'\n';
	for(int i:v)
		cout<<i+1<<" ";
	return 0;
}