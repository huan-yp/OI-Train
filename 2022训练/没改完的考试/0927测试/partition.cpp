#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename _type>
int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=50005;
int i,j,k,m,n,s,t,LIM,top;
int dp[N],a[N],b[N],suf_x[N],pre_i[N],sb[N],st[N];
int legal(int x){
	if(x==0)return 1;
	return pre_i[x]>suf_x[x+1];
}
struct segment_tree{
	int a[N<<2],lazy[N<<2];
	void clear(){
		memset(a,31,sizeof(a));
		memset(lazy,0,sizeof(lazy));
	}
	void push_up(int rt){
		a[rt]=min(a[rt<<1],a[rt<<1|1]);
	}
	void push_down(int rt){
		if(lazy[rt]==0)return ;
		a[rt<<1]+=lazy[rt],a[rt<<1|1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt],lazy[rt<<1]+=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c,int op=1){
		if(x>y)return ;
		if(x<=l&&y>=r){
			a[rt]*=op;a[rt]+=c,lazy[rt]+=c;
			return ;
		}
		push_down(rt);
		int mid=l+r>>1;
		if(x<=mid)updata(l,mid,rt<<1,x,y,c,op);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c,op);
		push_up(rt);
	}	
	int quert(int l,int r,int rt,int x,int y){
		if(x>y)return 1e18;
		if(x<=l&&y>=r)return a[rt];
		push_down(rt);int ret=1e18,mid=l+r>>1;
		if(x<=mid)cmin(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)cmin(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
int check(int x){
	T.clear();
	int l=0;top=0;
	memset(dp,31,sizeof(dp));dp[0]=0;
	T.updata(0,n,1,0,0,0,0);
	for(i=1;i<=n;i++){
		while(sb[i]-sb[l]>x&&l<i)l++;
		int lst=i-1;T.updata(0,n,1,i-1,i-1,a[i]);
		while(top&&a[i]>a[st[top]]){
			T.updata(0,n,1,st[top]-1,lst-1,a[i]-a[st[top]]);
			lst=st[top--]-1;
		}
		if(top==0)T.updata(0,n,1,0,0,a[i],0);
		st[++top]=i;
		if(legal(i)){
			dp[i]=T.quert(0,n,1,l,i-1);
			T.updata(0,n,1,i,i,dp[i],0);
		}
	}
	return dp[n]<=LIM;
}
signed main(){
	read(n),read(LIM);
	for(i=1;i<=n;i++)read(a[i]),read(b[i]),sb[i]=sb[i-1]+b[i];
	for(pre_i[0]=1ll<<40,i=1;i<=n;i++)pre_i[i]=min(pre_i[i-1],b[i]);
	for(i=n;i>=1;i--)suf_x[i]=max(suf_x[i+1],a[i]);

	int l=1,r=sb[n],ans=-1;
	while(r>=l){
		int mid=l+r>>1;
		if(check(mid))
		ans=mid,r=mid-1;
		else
		l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

