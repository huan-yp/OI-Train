#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=4e5+50,T=404;
int i,j,k,n,s,t,m,top;
int pos[N],rk[N],sa[N],tp[N],sum[N],height[N];
int sta[N],lo[N],st[N][20];
char ch[N];
LL all;
LL ans[N];
struct query{
	int l,r,rk;
	friend bool operator <(const query &a,const query &b)
	{
		if(pos[a.l]!=pos[b.l])return a.l<b.l;
		return a.r>b.r;
	}
}q[N];
struct node{
	int l,r,lcp;
}a[N];
void suffixsort()
{
	for(i=1;i<=n;i++)sum[rk[i]=ch[i]]++;
	for(i=1;i<=128;i++)sum[i]+=sum[i-1];
	for(i=n;i>=1;i--)sa[sum[rk[i]]--]=i;
	for(i=1;i<=n;i++)tp[i]=rk[i];
	for(i=1;i<=n;i++)rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]])?m:++m;
	for(k=1;;k<<=1)
	{
		m=s=0;
		for(i=n-k+1;i<=n;i++)tp[++s]=i;
		for(i=1;i<=n;sum[i++]=0)if(sa[i]>k)tp[++s]=sa[i]-k;
		for(i=1;i<=n;i++)sum[rk[i]]++;
		for(i=1;i<=n;i++)sum[i]+=sum[i-1];
		for(i=n;i>=1;i--)sa[sum[rk[tp[i]]]--]=tp[i];
		for(i=1;i<=n;i++)tp[i]=rk[i];
		for(i=1;i<=n;i++)rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+k]==tp[sa[i-1]+k])?m:++m;
		if(m==n)break;
	}
	for(i=1;i<=n;i++)
	{
		height[rk[i]]=max(0,height[rk[i-1]]-1);
		if(rk[i]==1)continue;
		while(ch[i+height[rk[i]]]==ch[sa[rk[i]-1]+height[rk[i]]])height[rk[i]]++;
	}
}
void erase(int x)
{
	int l=a[x].l,r=a[x].r;all-=a[x].lcp+a[r].lcp;
	a[l].r=r,a[r].l=l,cmin(a[r].lcp,a[x].lcp);
	all+=a[r].lcp;
}
int ask(int l,int r)
{
	int len=lo[r-l+1];
	return min(st[l][len],st[r-(1<<len)+1][len]);
}
void rollback(int x)
{
	int l=a[x].l,r=a[x].r;all-=a[r].lcp;
	a[l].r=x,a[r].l=x,a[r].lcp=ask(rk[x]+1,rk[r]);
	all+=a[r].lcp+a[x].lcp;
}
LL calc(LL l,LL r)
{
	LL len1=n-l+1,len2=n-r;
	return len1*(len1+1)/2-len2*(len2+1)/2;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",ch+1);n=strlen(ch+1);
	suffixsort();read(m);
	for(i=1;i<=n;i++)pos[i]=(i-1)/T+1,st[i][0]=height[i],lo[i]=log2(i);
	for(i=1;i<=17;i++)
	for(j=1;j+(1<<i)-1<=n;j++)
	st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	
	for(i=1;i<=m;i++)
	{
		read(q[i].l),read(q[i].r);
		q[i].rk=i;
	}
	sort(q+1,q+m+1);int now=1,pl,pr;
	for(i=1;i<=m;i++)
	{
		if(pos[q[i].l]!=pos[q[i-1].l])
		{
			now=pos[q[i].l];int lst=0;all=0;
			for(j=1;j<=n;j++)
			{
				if(sa[j]<(now-1)*T+1)continue;
				a[lst].r=sa[j],a[sa[j]].l=lst;
				all+=a[sa[j]].lcp=ask(rk[lst]+1,j),lst=sa[j];
			}
			top=a[lst].r=0;pr=n;
		}
		while(top)rollback(sta[top--]);
		pl=(now-1)*T+1;
		while(pr>q[i].r)erase(pr--);
		while(pl<q[i].l)erase(sta[++top]=pl++);
		ans[q[i].rk]=calc(q[i].l,q[i].r)-all;
	}
	for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}

