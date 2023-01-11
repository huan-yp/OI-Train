#include<bits/stdc++.h>
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
const int N=5e5+10;
int i,j,k,m,n,s,t,L,R;
int a[N],sum[N],st[N][20],lo[N];
int ask(int l,int r){
	int len=log2(r-l+1);
	return sum[st[l][len]]<sum[st[r-(1<<len)+1][len]]?st[l][len]:st[r-(1<<len)+1][len];	
}
struct node{
	int l,r,from,val;
	friend bool operator <(const node &a,const node &b){
		return a.val<b.val;
	}
};
priority_queue<node> q;
signed main(){
	read(n),read(k),read(L),read(R);
	for(i=1;i<=n;i++)read(a[i]),sum[i]=sum[i-1]+a[i],st[i][0]=i;
	for(i=1;i<=19;i++)
	for(j=0;j+(1<<i)-1<=n;j++)
	st[j][i]=sum[st[j][i-1]]<sum[st[j+(1<<i-1)][i-1]]?st[j][i-1]:st[j+(1<<i-1)][i-1];
	for(i=L;i<=n;i++){
		int l=max(i-R,0),r=i-L;
		q.push(node{l,r,i,sum[i]-sum[ask(l,r)]});
	}
	long long ans=0;
	for(i=1;i<=k;i++){
		auto u=q.top();q.pop();ans+=u.val;
		int mid=ask(u.l,u.r);
		if(u.l<mid)q.push(node{u.l,mid-1,u.from,sum[u.from]-sum[ask(u.l,mid-1)]});
		if(u.r>mid)q.push(node{mid+1,u.r,u.from,sum[u.from]-sum[ask(mid+1,u.r)]});
	}
	cout<<ans<<endl;
	return 0;
}

