#include<bits/stdc++.h>
#define INF 1000000000
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
const int N=8e5+10,mod=998244353;
int i,j,k,n,s,t,m,top;
int a[N],dp[N],pos[N];
void Dec(int &x,int y){x-=y;if(x<0)x+=mod;}
void Inc(int &x,int y){if(y<0)Dec(x,abs(y));else {x+=y;if(x>=mod)x-=mod;}}
struct segment{
	int l,r;
	friend bool operator <(const segment &a,const segment &b){return a.r<b.r;} 
};
struct oper{
	int x,op,l,r;
	friend bool operator <(const oper &a,const oper &b){return a.x<b.x;}
}op[N];
struct node{
	int min,sum;
	node(int x=0,int y=0){min=x,sum=y;}
	friend node operator +(const node &a,const node &b)
	{
		if(a.min<b.min)return a;
		if(b.min<a.min)return b;
		return (node){a.min,(a.sum+b.sum)%mod};
	}
};
struct segmentTree{
	node a[N<<2];int lazy[N<<2];
	void push_up(int rt){a[rt]=a[rt<<1]+a[rt<<1|1];}
	void push_down(int rt)
	{
		if(lazy[rt]==0)return ;
		a[rt<<1].min+=lazy[rt],a[rt<<1|1].min+=lazy[rt];
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
	node quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2;node ret;
		push_down(rt);
		if(x<=mid)ret=ret+quert(l,mid,rt<<1,x,y);
		if(y>mid)ret=ret+quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
	void updata(int l,int r,int rt,int x,int y,int op,int c)
	{
		if(x<=l&&y>=r)
		{
			if(op==1)// ¸Ä min
			{
				a[rt].min+=c;
				lazy[rt]+=c;
			}
			else // ¸Ä sum 
			{
				Inc(a[rt].sum,c);
			}
			return ;
		}
		int mid=(l+r)/2;
		push_down(rt);
		if(x<=mid)updata(l,mid,rt<<1,x,y,op,c);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,op,c);
		push_up(rt);
	}
}T;
set<segment> st;
set<segment>::iterator merge(segment a,segment b)
{
	st.erase(a),st.erase(b);
	segment newsegment = (segment){a.l,b.r};
	st.insert(newsegment);
	return st.find(newsegment);
}
set<segment>::iterator split(segment a,int pos,int op)
{
	segment n1,n2;
	if(op==1)n1.l=a.l,n1.r=pos,n2.l=pos+1,n2.r=a.r;
	if(op==2)n1.l=pos,n1.r=a.r,n2.l=a.l,n2.r=pos-1;
	st.erase(a);
	st.insert(n1);
	if(n2.r>=n2.l)st.insert(n2);
	return st.find(n1);
}
signed main()
{
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),pos[a[i]]=i;
	
	st.insert((segment){1,n});
	for(i=1;i<=n;i++)
	{
		segment search;search.r=pos[i];
		auto it=st.lower_bound(search);
		if(pos[i]==it->r&&pos[i]!=n)it=merge(*it,*next(it));
		else it = split(*it,pos[i],1);

		if(pos[i]==it->l&&pos[i]!=1)it=merge(*prev(it),*it);
		else it = split(*it,pos[i],2);
		if(it->r!=n)
		{
			auto nxt=next(it);	
			op[++s]=(oper){nxt->l,1,it->l,it->r};
			op[++s]=(oper){nxt->r+1,-1,it->l,it->r};
		}
	}
	sort(op+1,op+s+1);int now=1;
	T.updata(1,n+1,1,1,1,2,1);dp[0]=1;
	for(i=1;i<=n;i++)
	{
		while(op[now].x==i)
		{
			T.updata(1,n+1,1,op[now].l,op[now].r,1,op[now].op);
			now++;
		}
		Inc(dp[i],T.quert(1,n+1,1,1,n+1).sum);
		T.updata(1,n+1,1,i+1,i+1,2,dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}
