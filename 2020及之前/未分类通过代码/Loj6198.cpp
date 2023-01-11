#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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
int i,j,k,n,s,t,m,ans;
const int N=1e5+10;
int a[N],b[N<<1],sum[N],sa[N],h[N],val[N],rk[N];
char ch[N];
struct Tree{
	int val,rk;
	friend Tree operator +(Tree aa,Tree bb)
	{
		if(aa.val<bb.val)
		return aa;
		return bb;
	}
}T[N<<2];
struct Trie{
	int son[2],val[2]; 
}Tr[N<<5];
void suffix_sort()
{
	t=0;
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
		if(n==t)break; 
	}
	for(i=1;i<=n;i++)
	{
		h[a[i]]=max(h[a[i-1]]-1,0);
		while(ch[h[a[i]]+i]==ch[h[a[i]]+sa[a[i]-1]]&&i+h[a[i]]<=n&&h[a[i]]+sa[a[i]-1]<=n)
		h[a[i]]++;
	}
} 
void add(int u,int u2,int rk,int x,int dep)
{
	if(dep==-1)return;
	if(x&(1<<dep))
	{
		Tr[u].son[1]=++t,Tr[u].val[1]=rk+1;
		Tr[u].son[0]=Tr[u2].son[0],Tr[u].val[0]=Tr[u2].val[0];
		add(Tr[u].son[1],Tr[u2].son[1],rk,x,dep-1);
	}
	else
	{
		Tr[u].son[0]=++t,Tr[u].val[0]=rk+1;
		Tr[u].son[1]=Tr[u2].son[1],Tr[u].val[1]=Tr[u2].val[1];
		add(Tr[u].son[0],Tr[u2].son[0],rk,x,dep-1);
	}
}
int query(int u,int x,int l,int dep)
{
	if(dep==-1)return 0;
	int pd=(x>>dep)&1;
	if(Tr[u].son[pd^1]&&Tr[u].val[pd^1]>=l)
	return (1<<dep)|query(Tr[u].son[pd^1],x,l,dep-1); 
	else
	return query(Tr[u].son[pd],x,l,dep-1);
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		T[rt].rk=l;
		T[rt].val=h[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}
Tree quert(int l,int r,int rt,int x,int y)
{
	if(x<=l&&y>=r)
	return T[rt];
	int mid=(l+r)/2;
	Tree ret;ret.val=1e9;
	if(x<=mid)
	ret=ret+quert(l,mid,rt<<1,x,y);
	if(y>mid)
	ret=ret+quert(mid+1,r,rt<<1|1,x,y); 
	return ret;
}
void solve(int l,int r)
{
	if(l==r)return;
	int mid=quert(1,n,1,l+1,r).rk;
	solve(l,mid-1),solve(mid,r);
	if(mid-l>r-mid+1)
	{
		for(int i=mid;i<=r;i++)
		ans=max(ans,h[mid]+query(rk[mid-1],val[sa[i]],l,20));
	} 
	else
	{
		for(int i=l;i<mid;i++)
		ans=max(ans,h[mid]+query(rk[r],val[sa[i]],mid,20));
	} 
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	scanf("%s",ch+1);
	suffix_sort();
//	for(i=1;i<=n;i++)
//	printf("%s\n",ch+sa[i]);
	t=0;
	for(i=1;i<=n;i++)
	rk[i]=++t;
	for(i=1;i<=n;i++)
	read(val[i]);
	for(i=1;i<=n;i++)
	add(rk[i],rk[i-1],i-1,val[sa[i]],20);
	build(1,n,1);
	solve(1,n);
	printf("%d",ans);
	return 0;
}

