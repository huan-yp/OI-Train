#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
#define pii pair<int,int>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=5e5+10;
int i,j,k,n,s,t,m;
int pre[N],suf[N],val[4][N];
int ask(int op,int l,int r){
	return val[op][r]-val[op][l-1];
}
struct line{
	int l,r,val;
	friend bool operator <(const line &a,const line &b){
		return a.r<b.r;
	}
}p[N],st[N];
struct SGT{
	int a[N<<2],b[N<<2],c[N<<2],lazy[N<<2];
	void push_up(int rt){
		a[rt]=max(a[ls],a[rs]);
		b[rt]=max(b[ls],b[rs]);
		c[rt]=max(c[ls],c[rs]);
	}
	void push_down(int rt){
		if(lazy[rt]==0)return ;
		b[ls]+=lazy[rt],c[ls]+=lazy[rt],lazy[ls]+=lazy[rt];
		b[rs]+=lazy[rt],c[rs]+=lazy[rt],lazy[rs]+=lazy[rt];
		lazy[rt]=0;
	}
	void build(int l,int r,int rt){
		if(l==r){
			a[rt]=pre[l],b[rt]=suf[l];
			c[rt]=a[rt]+b[rt];
			return ;
		}
		int mid=l+r>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rs);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x<=l&&y>=r)return c[rt];
		int mid=l+r>>1,ret=-1ll*INF*INF;
		push_down(rt);
		if(x<=mid)cmax(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)cmax(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
	void updata(int l,int r,int rt,int x,int cc){
		if(l==r){
			cmax(a[rt],cc);c[rt]=a[rt]+b[rt];
			return ;
		}
		push_down(rt);
		int mid=l+r>>1;
		if(x<=mid)updata(l,mid,rt<<1,x,cc);
		else updata(mid+1,r,rt<<1|1,x,cc);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int y,int cc){
		if(x<=l&&y>=r){
			b[rt]+=cc,lazy[rt]+=cc,c[rt]+=cc;
			return ;
		}
		push_down(rt);int mid=l+r>>1;
		if(x<=mid)updata(l,mid,rt<<1,x,y,cc);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,cc);
		push_up(rt);
	}
	void build2(int l,int r,int rt){
		if(l==r){
			a[rt]=c[rt]=-1ll*INF*INF;
			b[rt]=0;
			return ;
		}
		int mid=l+r>>1;
		build2(l,mid,rt<<1);
		build2(mid+1,r,rs);
		push_up(rt);
	}
}T,B;
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m);
	for(j=1;j<=3;j++)
	for(i=1;i<=n;i++)
	read(val[j][i]),val[j][i]+=val[j][i-1];

	for(i=1;i<=m;i++)
	read(p[i].l),read(p[i].r),read(p[i].val);
	sort(p+1,p+m+1);
	
	for(i=1;i<=n;i++){
		pre[i]=ask(1,1,i)-ask(2,1,i-1);
		suf[i]=ask(3,i,n)+ask(2,1,i);
	}
	T.build(1,n,1);
	B.build2(1,n,1);
	int ans=-1ll*INF*INF,now=1,top=0,maxn=-1ll*INF*INF;
	for(i=1;i<=n;i++){
		int rnow=i-1,lnow=i;
		while(top&&suf[i]>=st[top].val){
			int dis=suf[i]-st[top].val;
			lnow=st[top].l;
			T.updata(1,n,1,lnow,st[top--].r,dis);
		}
		st[++top]=line{lnow,i,suf[i]};
		B.updata(1,n,1,i,pre[i]);
		while(p[now].r==i){
			int tmp=B.quert(1,n,1,p[now].l,i)-p[now].val;
			cmax(pre[i+1],tmp);
			cmax(ans,T.quert(1,n,1,p[now].l,p[now].r)-p[now].val);
			now++;	
		}
		if(i!=n)T.updata(1,n,1,i+1,pre[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

