#include<bits/stdc++.h>
#define y1 y3647
#define int long long
#define earse erase
#define low(x) (x)&(-x)
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int N=1e6+10;
int i,j,k,m,n,s,t;
int a[N],b[N],sa[N],sum[N],h[N],ans[N];
int st[N],top;
char ch[N];
void suffix_sort()
{
	for(i=1;i<=n;i++)a[i]=ch[i];
	for(i=1;i<=n;i++)sum[a[i]]++;
	for(i=1;i<=128;i++)sum[i]+=sum[i-1];
	for(i=n;i>=1;i--)sa[sum[a[i]]--]=i;
	for(i=1;i<=n;i++)b[i]=a[i];
	for(i=1;i<=n;i++)a[sa[i]]=b[sa[i]]==b[sa[i-1]]?t:++t;
	for(k=1;;k<<=1)
	{
		s=t=0;
		for(i=n-k+1;i<=n;i++)b[++s]=i;
		for(i=1;i<=n;i++)if(sa[i]>k)b[++s]=sa[i]-k;
		for(i=1;i<=n;i++)sum[i]=0;
		for(i=1;i<=n;i++)sum[a[i]]++;
		for(i=1;i<=n;i++)sum[i]+=sum[i-1];
		for(i=n;i>=1;i--)sa[sum[a[b[i]]]--]=b[i];
		for(i=1;i<=n;i++)b[i]=a[i];
		for(i=1;i<=n;i++)a[sa[i]]=(b[sa[i]]==b[sa[i-1]]&&b[sa[i]+k]==b[sa[i-1]+k])?t:++t;
		if(t==n)break;
	}
	for(i=1;i<=n;i++)
	{
		h[a[i]]=max(h[a[i-1]]-1,0ll);
		while(ch[h[a[i]]+i]==ch[h[a[i]]+sa[a[i]-1]]&&sa[a[i]-1]+h[a[i]]<=n&&h[a[i]]+i<=n)
		h[a[i]]++;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",stdout);
	read(n);
	scanf("%s",ch+1);
	suffix_sort();h[0]=h[n+1]=-1;
	int now=0;
	st[top=1]=0;
	for(i=1;i<=n;i++)
	{
		ans[i]+=n-i+1;
		while(h[st[top]]>=h[i])top--,now-=(st[top+1]-st[top])*h[st[top+1]];
		now+=h[i]*(i-st[top]);
		st[++top]=i;
		
		ans[sa[i]]+=now;
	}
	st[top=1]=n;now=0;
	for(i=n-1;i>=1;i--)
	{
		while(h[st[top]+1]>=h[i+1])top--,now-=(st[top]-st[top+1])*h[st[top+1]+1];
		now+=h[i+1]*(st[top]-i);
		st[++top]=i;
		ans[sa[i]]+=now;
	}
	
	
	for(i=1;i<=n;i++)
	printf("%lld\n",ans[i]);
	
	return 0;
}

