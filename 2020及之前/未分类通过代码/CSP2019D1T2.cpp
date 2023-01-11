#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,k,m,n,s,t,top;
const int N=5e5+10;
int head[N],st[N],fa[N],ans[N],op[N],c[N];
struct fu{
	int v,next;
}a[N<<1];
char ch[N];
void work(int aa,int bb)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;	
} 
void dfs(int u)
{
	ans[u]+=ans[fa[u]];
	if(ch[u]=='(')
	{
		st[++top]=u;
		op[u]=1e9;
	}
	else
	{
		if(top)
		{
			op[u]=st[top--];
			c[u]=c[fa[op[u]]]+1;
			ans[u]+=c[u];
		}
	}
	for(int i=head[u];i;i=a[i].next)
	dfs(a[i].v);
	if(op[u]==1e9)
	top--;
	else
	if(op[u])
	st[++top]=op[u];
}
signed main()
{
	scanf("%lld",&n);	
	scanf("%s",ch+1);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&t);
		fa[i]=t;
		work(t,i);
	}
	dfs(1);
	int sum=0;
	for(i=1;i<=n;i++)
	sum^=ans[i]*i;
	printf("%lld",sum);
	return 0;
}
