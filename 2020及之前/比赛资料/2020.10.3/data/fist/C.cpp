#include<cstdio>
#include<algorithm>
#include<cstring>
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
struct Tree
{
	ll a,b;
}tree[4000005];
ll a[1000005];
int n,l[1000005],r[1000005],st[1000005],top;
void pushdown(int x,int l,int r,ll a,ll b)
{
	if(l*a+b<=l*tree[x].a+tree[x].b&&r*a+b<=r*tree[x].a+tree[x].b)return;
	if(l*a+b>=l*tree[x].a+tree[x].b&&r*a+b>=r*tree[x].a+tree[x].b)
	{
		tree[x].a=a;
		tree[x].b=b;
		return;
	}
	if(mid*a+b>mid*tree[x].a+tree[x].b)
	{
		swap(a,tree[x].a);
		swap(b,tree[x].b);
	}
	if(l*a+b>=l*tree[x].a+tree[x].b)pushdown(lc,l,mid,a,b);
	else pushdown(rc,mid+1,r,a,b);
}
void update(int x,int l,int r,int from,int to,ll a,ll b)
{
	if(l>=from&&r<=to)
	{
		pushdown(x,l,r,a,b);
		return;
	}
	if(from<=mid)update(lc,l,mid,from,to,a,b);
	if(to>mid)update(rc,mid+1,r,from,to,a,b);
}
ll query(int x,int l,int r,int p)
{
	if(l==r)return l*tree[x].a+tree[x].b;
	ll ans=p*tree[x].a+tree[x].b;
	if(p<=mid)ans=max(ans,query(lc,l,mid,p));
	else ans=max(ans,query(rc,mid+1,r,p));
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		while(top&&a[st[top]]>=a[i])top--;
		l[i]=st[top]+1;
		st[++top]=i;
	}
	top=0;
	st[0]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[st[top]]>=a[i])top--;
		r[i]=st[top]-1;
		st[++top]=i;
	}
	for(int i=1;i<=n;i++)
	{
		update(1,1,n,l[i],r[i],a[i],-l[i]*a[i]+a[i]);
		update(1,1,n,r[i],n,0,(r[i]-l[i]+1)*a[i]);
	}
	for(int i=1;i<=n;i++)printf("%lld ",query(1,1,n,i));
	printf("\n");
	return 0;
}
