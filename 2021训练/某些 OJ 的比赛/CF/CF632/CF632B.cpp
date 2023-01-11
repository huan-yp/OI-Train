#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=5e5+10;
int i,j,k,n,s,t,m,ans;
int a[N],pref[N],suff[N],prez[N],sufz[N];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]);
	scanf("%s",ch+1);
	for(i=1;i<=n;i++)
	{
		prez[i]=prez[i-1],pref[i]=pref[i-1];
		if(ch[i]=='B')
		prez[i]+=a[i];
		else
		pref[i]+=a[i];
	}
	for(i=n;i>=1;i--)
	{
		sufz[i]=sufz[i+1],suff[i]=suff[i+1];
		if(ch[i]=='B')
		sufz[i]+=a[i];
		else
		suff[i]+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		ans=max(ans,pref[i]+sufz[i+1]);
		ans=max(ans,prez[i]+suff[i+1]);
	}
	cout<<ans;
	return 0;
}


