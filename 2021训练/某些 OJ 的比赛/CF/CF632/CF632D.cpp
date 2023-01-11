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
const int N=1e6+10;
int i,j,k,n,s,t,m,ans=1;
int cnt[N],sum[N],a[N],opt[N];
void init()
{
	for(i=1;i<=m;i++)
	for(j=1;j*i<=m;j++)
	sum[i*j]+=cnt[i];
	for(i=1;i<=m;i++)
	if(sum[i]>sum[ans])
	ans=i;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>m)continue;
		cnt[a[i]]++;
	}
	init();
	for(i=1;i<=n;i++)
	if(ans%a[i]==0)
	opt[++s]=i;
	printf("%d %d\n",ans,s);
	for(i=1;i<=s;i++)
	printf("%d ",opt[i]);
	return 0;
}


