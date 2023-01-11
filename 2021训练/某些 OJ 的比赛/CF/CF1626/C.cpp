#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e4+10;
int i,j,n,s,t,m;
int h[N],k[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);int ans,now,maxn;
		for(i=1;i<=n;i++)read(k[i]);
		for(i=1;i<=n;i++)read(h[i]);
		ans=h[n],now=maxn=h[n];
		for(i=n-1;i>=0;i--)
		{
			int now2=now-k[i+1]+k[i];
			if(now2<=0)ans+=now*(now-1)/2,now=maxn=0;	
			else ans+=(k[i+1]-k[i])*(now2+now-1)/2,now=now2;
			if(now>=h[i])continue;
			ans+=(h[i]-now)*(maxn-now+1),maxn+=h[i]-now,now=h[i];
		}
		printf("%lld\n",ans);
	}

	return 0;
}

