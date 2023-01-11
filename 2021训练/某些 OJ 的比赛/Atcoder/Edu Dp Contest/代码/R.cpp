#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=55,mod=1e9+7;
int i,j,n,s,t,m;
LL k;
struct matri{
	int a[N][N],n,m;
	friend matri operator *(const matri &aa,const matri &bb)
	{
		matri ret;
		ret.n=bb.n,ret.m=aa.m;
		for(int i=1;i<=ret.n;i++)
		for(int j=1;j<=ret.m;j++)
		{
			ret.a[i][j]=0;
			for(int k=1;k<=aa.n;k++)
			ret.a[i][j]+=1ll*aa.a[k][j]*bb.a[i][k]%mod,ret.a[i][j]%=mod;
		}
		return ret;
	}
}E,S;
void solve(LL ss)
{
	while(ss)
	{
		if(ss&1ll)
		E=E*S;
		ss>>=1ll;
		S=S*S;
	}
	int ans=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	ans+=E.a[i][j],ans%=mod;
	cout<<ans;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>n>>k;
	E.n=E.m=S.n=S.m=n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	read(S.a[j][i]),E.a[i][j]=i==j;
	solve(k);
	return 0;
}


