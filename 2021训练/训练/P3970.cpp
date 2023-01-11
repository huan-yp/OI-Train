#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) (x)&(-x)
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
const int N=1e5+10,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int c[N],a[N],dp[N],b[N],pos[N];
void Dec(int &x,int y){x-=y;if(x<0)x+=mod;}
void Inc(int &x,int y){if(y<0){Dec(x,y);return;}x+=y;if(x>=mod)x-=mod;}
void updata(int x,int cc){for(;x<=m;x+=low(x))Inc(c[x],cc);}
int quert(int x,int ret=0){for(;x;x-=low(x))Inc(ret,c[x]);return ret;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),b[i]=a[i];
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for(i=1;i<=n;i++)
	{
		dp[i]=quert(a[i]-1);
		updata(a[i],(dp[i]-dp[pos[a[i]]]+(pos[a[i]]==0?1:0)+mod)%mod);
		pos[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	if(pos[a[i]]==i)Inc(ans,dp[i]);
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}

