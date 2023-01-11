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
const int N=1e5+10,mod=1e9+7;
int i,j,k,m,n,s,t,top,ans,now;
int st[N],w[N],h[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)read(h[i]);
	for(i=1;i<=n;i++)read(w[i]);
	for(i=1;i<=n;i++)
	{
		int tmp=w[i];
		while(h[i]<h[st[top]]&&top)
		{
			int u=st[top--],len=h[u]-h[i];
			now-=len*(h[u]+h[i]+1)/2%mod*w[u]%mod%mod,now%=mod,w[i]+=w[u],w[i]%=mod;
		}
		ans+=h[i]*(h[i]+1)/2%mod*(tmp*(tmp+1)/2%mod)%mod;ans%=mod;
		ans+=now*tmp%mod,ans%=mod;
		now+=h[i]*(h[i]+1)/2%mod*tmp%mod,now%=mod;
		st[++top]=i;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

