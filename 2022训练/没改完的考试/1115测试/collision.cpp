#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=1e6+10;
int i,j,k,m,n,s,t,n1,n2;
int a[N],b[N],p[N],rk[N],_v[N];
long long L,R;
long long count(long long x){
	long long ans=0;
	for(i=1;i<=n2;i++){
		int lim=max(b[i]-x,-2147483647ll);
		int _l=p[i]=lower_bound(a+1,a+n1+1,lim)-a;
		int _r=lower_bound(a+1,a+n1+1,b[i])-a-1;
		ans+=_r-_l+1;
	}
	return ans;
}
struct node{
	int val,rk;
	bool operator <(const node &a)const{
		return val>a.val;
	}
};
struct statu{
	int t,x,y;
	bool operator <(const statu &a)const{
		if(t!=a.t)return t<a.t;
		if(x!=a.x)return x<a.x;
		return y<a.y;
	}
}w[N];
priority_queue<node> q;
signed main(){
	read(n);
	for(i=1;i<=n;i++){
		int x,v;read(x),read(v);
		_v[i]=x;rk[i]=i;
		if(v==1)a[++n1]=x;
		else b[++n2]=x;		
	}
	sort(rk+1,rk+n+1,[](int a,int b){return _v[a]<_v[b];});
	sort(a+1,a+n1+1);sort(b+1,b+n2+1);
	read(L),read(R);
	int l=0,r=2e9,res;
	while(r>=l){
		int mid=l+(r-l)/2;
		if(count(mid)<L)
		res=mid,l=mid+1;
		else
		r=mid-1;
	}
	long long val=count(res);
	L-=val,R-=val;
	for(i=1;i<=n2;i++)
	if(p[i]!=1)
	q.push(node{b[i]-a[p[i]-1],i});
	
	for(i=1;i<=R+n;i++){
		if(q.empty())break ;
		auto w=q.top();q.pop();
		int rk=w.rk;p[rk]--;
		::w[++s]={b[rk]-a[p[rk]],p[rk],rk};
		if(p[rk]!=1)q.push(node{b[rk]-a[p[rk]-1],rk});
	}
	for(i=1;i<=s;i++){
		w[i].x=w[i].x+w[i].y-1;
		w[i].y=w[i].x+1;
		w[i].x=rk[w[i].x];
		w[i].y=rk[w[i].y];
	}
	sort(w+1,w+s+1);
	for(i=L;i<=R;i++)
	printf("%d %d\n",w[i].x,w[i].y);
	return 0;
}

