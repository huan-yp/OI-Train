#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(b>a)a=b;}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(b<a)a=b;}
const int N=1e5+10;
int i,j,k,m,n,s,t,top;
int dp[N],a[N],L[N],R[N],st[2][N];
struct oper{
	int x,c,l,r;
	friend bool operator <(const oper &b,const oper &a){
		return b.x>a.x;
	}
};
priority_queue<oper> q;
struct SGT{
	int a[N<<2],lazy[N<<2];
	void push_up(int rt){
		a[rt]=max(a[rt<<1],a[rt<<1|1]);
	}
	void push_down(int l,int r,int rt){
		int mid=l+r>>1;
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		a[rt<<1]+=lazy[rt],a[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c){
		if(x>y)return ;
		if(x<=l&&y>=r){
			a[rt]+=c;lazy[rt]+=c;
			return ;
		}
		push_down(l,r,rt);
		int mid=l+r>>1;
		if(x<=mid)updata(l,mid,rt<<1,x,y,c);
		if(y>mid) updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x<=l&&y>=r)return a[rt];
		push_down(l,r,rt);
		int mid=l+r>>1,ret=0;
		if(x<=mid)cmax(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)cmax(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
int main(){
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++)read(L[i]),read(R[i]);
	for(i=1;i<=n;i++){
		while(top&&a[i]>=st[0][top])top--;
		int l1=upper_bound(st[0]+1,st[0]+top+1,L[i],greater<int>())-st[0]-1;
		int l2=upper_bound(st[0]+1,st[0]+top+1,R[i]+1,greater<int>())-st[0]-1;
		l1*=(l1!=top+1);l2*=(l2!=top+1);l1=st[1][l1],l2=st[1][l2];
		T.updata(1,n,1,1,l1,1);
		T.updata(1,n,1,1,l2,-1);
		q.push(oper{L[i],1,l1+1,i});
		q.push(oper{R[i]+1,-1,l2+1,i});
		st[0][++top]=a[i],st[1][top]=i;
		while(!q.empty()&&st[0][top]>=q.top().x){
			auto w=q.top();q.pop();
			T.updata(1,n,1,w.l,w.r,w.c);
		}
		dp[i]=T.quert(1,n,1,1,i);
		if(i!=n)T.updata(1,n,1,i+1,i+1,dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}

