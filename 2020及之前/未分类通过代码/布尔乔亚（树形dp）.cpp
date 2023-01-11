#include<bits/stdc++.h>
#define long long long
#define ld lld
#define y1 y749872
#define next nxt
using namespace std;
int j,k,n,s,t=1,m;
const int N=5e4+10;
int sum[N],head[N],len[N],b[N],vis[N],size[N],fa[N],b2[N],pd;//len内部上传,1向上传最长的,2内销最长，sum儿子是个数，size是边数 
struct fu{
	int v,next;
};
fu a[N*2];
void work(int aa,int bb)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;
}
void dfs(int u)
{
	vis[u]=1;
	int i;
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(vis[v])
		continue;
		sum[u]++;
		dfs(v);
		size[u]+=size[v];
	}
	size[u]-=sum[u]/2;
	if(u!=t)
	{
		size[u]-=sum[u]%2;
		size[u]++;
	}
} 
int check2(int x,int num,int y)
{
	int jt=0;
	int i;
	for(i=1;i<=y;i++)
	if(i!=x)
	b2[++jt]=b[i];
	for(i=1;i<=jt/2;i++)
	if(b2[i]+b2[jt-i+1]>num)
	return 0;
	return 1;
}
int solve(int u,int num)
{
	int js=0;
	int i;
	for(i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(fa[u]==v)
		continue;
		b[++js]=len[v];
	}
	int l=1,r=js;
	int pt=0;
	if(js%2==0)
	pt=1;
	sort(b+1,b+js+1);
	if(pt)
	{
		if(check2(0,num,js))
		return 0;
		js--;
	}
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check2(mid,num,js))
		r=mid-1;
		else
		l=mid+1;
	}
	if(l==js+1)
	pd=0;
	return b[l];
}
void check(int u,int num)
{
	if(pd==0)
	return;
	vis[u]=1;
	int i;
	for(i=head[u];i;i=a[i].next)
	{
		if(pd==0)
		return;
		int v=a[i].v;
		if(vis[v])
		continue;
		fa[v]=u;
		check(v,num);
	}	 
	if(pd==0||u==t)
	return;
	len[u]=solve(u,num)+1;
	if(len[u]>num)
	pd=0;
}
void rsolve(int u,int num)
{
	if(pd==0)
	return;
	int js=0;
	int i;
	for(i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(fa[u]==v)
		continue;
		b[++js]=len[v];
	}
	int l=1,r=js;
	int pt=0;
	if(js%2==0)
	pt=1;
	sort(b+1,b+js+1);
	if(!pt)
	js--;
	pd=check2(0,num,js);
}
int main()
{

	//freopen(".ans","w",sdtout);
	scanf("%d",&n); 
	int i,x,y;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		work(x,y);
		work(y,x);
	}
	dfs(t);
	cout<<size[t]<<endl;
	int l=1,r=n-1;//l以下不行，r以上可以 
	while(r>=l)
	{
		memset(vis,0,sizeof(vis));
		memset(len,0,sizeof(len));
		int mid=(l+r)/2; 
		pd=1;
		check(t,mid);
		rsolve(t,mid);
		if(pd)
		r=mid-1;
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}

