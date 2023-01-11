#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
struct mergeOperation{
	int u,v,rk;
	friend bool operator <(const mergeOperation &a,const mergeOperation &b)
	{
		return a.rk>b.rk;
	}
};
struct checkPoint{
	int x,val,rk;
	friend bool operator <(const checkPoint &a,const checkPoint &b)
	{
		return a.val>b.val;
	}
};
const int N=3e5+10; 
int i,j,k,n,s,t,m;
int fa[N],size[N],val[N],ans[N],os[N];
priority_queue<mergeOperation> q;
priority_queue<checkPoint> op[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	//merge v to u
	u=find(u),v=find(v);
	if(size[v]>size[u])swap(v,u);
	fa[v]=u,size[u]+=size[v]; 
	val[u]+=val[v];
	while(!op[v].empty())
	{
		auto tmp=op[v].top();op[v].pop();
		op[u].push(tmp);
	}
//	if(!op[u].empty())
//	printf("%lld\n",op[u].top().val);
	while(!op[u].empty()&&op[u].top().val<=val[u])
	{
		auto tmp=op[u].top();op[u].pop();
		int root=find(tmp.x);
		int x=val[u],y=val[root];
		if(x+y>=os[tmp.rk])
		{
			q.push((mergeOperation){u,root,tmp.rk});
			continue;
		}
		int nvalx=x+(os[tmp.rk]-x-y+1)/2;
		int nvaly=y+(os[tmp.rk]-x-y+1)/2;
		op[root].push((checkPoint){u,nvaly,tmp.rk});
		op[u].push((checkPoint){root,nvalx,tmp.rk});
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	size[i]=1,read(val[i]),fa[i]=i;

	for(i=1;i<=m;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);os[i]=z;
		if(val[x]+val[y]>=z)
		q.push((mergeOperation){x,y,i});
		else
		{
			op[x].push((checkPoint){y,val[x]+(os[i]-val[x]-val[y]+1)/2,i});
			op[y].push((checkPoint){x,val[y]+(os[i]-val[x]-val[y]+1)/2,i});
		}
		//维护的是每一块还需要的值
		//如果维护的是总值的一半,那么另一个没到一半的时候就已经有可能满足条件了 
	}
	//复杂度分析:每次拆出两个 checkpoint 当前 operation  
	//还需要的值 /2
	//总 checkPoint 数量级为 nlogs,考虑用 priority_queue 维护
	//总复杂度 O(nlogn^2logsloglogs) 
	while(!q.empty())
	{
		auto now=q.top();q.pop();
		int u=now.u,v=now.v;
		if(find(u)==find(v))continue;
		ans[++s]=now.rk;
		merge(u,v);
	}
	printf("%lld\n",s);
	for(i=1;i<=s;i++)
	printf("%lld ",ans[i]);
	return 0;
}

