#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) ((x)&(-x))
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int mod = 1e9+7;
int i,j,k,n,s,t,m;
map<int,int> dp,f,g;
int solve(int x)
{
	if(x==1)return 1;
	if(dp.find(x)!=dp.end())return dp[x];
	int r=x>>1,l=x-r;
	int ret=(solve(l)+solve(r))%mod;
	f[x]=f[l]+f[r]+l,g[x]=g[l]+g[r]+r;
	f[x]%=mod,g[x]%=mod;
	ret+=f[l]*(r%mod)%mod;ret%=mod;
	ret+=g[r]*(l%mod)%mod;ret%=mod;
	ret+=x-1;ret%=mod;
//	if(low(l)!=l)ret+=r,ret%=mod;
//	if(low(r)!=r)ret+=l,ret%=mod;
	return dp[x]=ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int l,r,ans=0;
		read(n);
		cout<<solve(n)<<endl;
	}
	return 0;
}

