#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0,r=1;
	while(ch<'0'||ch>'9'){if(ch=='-')r=0;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return r?x:-x;
}
int n,m,x,s,ans[100100],cnt;
bool b[100100];
void check(int x,int p)
{
	int now=0;
	for(int i=1;i<=n;++i)
	{
		s=i;
		while(s%x==0)s/=x,now--;
		s=n-i+1;
		while(s%x==0)s/=x,now++;
		if(now<p)b[i]=0;
	}
}
signed main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read()-1;m=read();
	for(int i=1;i<=n;++i)b[i]=1;
	if(m==1){printf("%lld\n",n+1);for(int i=1;i<=n+1;++i)printf("%lld ",i);return 0;}
	for(int i=2;i*i<=m;++i)
	{
		x=0;
		while(m%i==0)m/=i,x++;
		if(x)check(i,x);
	}
	if(m>1)check(m,1);
	for(int i=1;i<=n;++i)if(b[i])ans[++cnt]=i;
	printf("%lld\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%lld ",ans[i]+1);
	return 0;
}
