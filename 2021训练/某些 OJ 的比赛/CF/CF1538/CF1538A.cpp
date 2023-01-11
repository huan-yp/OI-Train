#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
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
int i,j,k,n,s,t,m;
const int N=1e2+10;
int a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		int maxn=-2e9,minu=2e9;
		for(i=1;i<=n;i++)	
		{
			read(a[i]);
			maxn=max(maxn,a[i]);
			minu=min(minu,a[i]);
		}
		int pa,pi;
		for(i=1;i<=n;i++)
		{
			if(a[i]==maxn)
			pa=i;
			if(a[i]==minu)
			pi=i;
		}
		int ans=min(max(pa,pi),min(n-min(pa,pi)+1,min(n-pa+1+pi,n-pi+1+pa)));
		printf("%d\n",ans);
	}
	return 0;
}


