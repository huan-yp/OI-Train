#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int sum[N],cnt[N];
int ans;
void solve(int l,int r)
{
	for(i=2;i<=r;i++)
	cnt[i]=r/i-(l-1)/i;
	
	for(i=r;i>=2;i--)
	{
		cnt[i]=cnt[i]*cnt[i];
		for(j=2;j*i<=r;j++)
		cnt[i]-=cnt[j*i];
		
		ans+=cnt[i];
	}
	//从后向前容斥
	//1被考虑在外 
	for(i=max(2ll,l);i<=r;i++)
	{
		ans--;
		for(j=2;j*i<=r;j++)
		ans-=2;
	}
	cout<<ans;//1
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int l,r;
	read(l),read(r);
	solve(l,r);
	return 0;
}
