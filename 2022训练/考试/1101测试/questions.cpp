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
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=3e5+10,M=512;
int i,j,k,m,n,s,t,l,r;
int a[N],cnt[N],pos[N],ans[N];
struct query{
	int l,r,k,rk;
	bool operator <(const query &a){
		if(pos[l]!=pos[a.l])return l<a.l;
		return (pos[l]&1)?r>a.r:r<a.r;
	}
}q[N];
struct Solver{
	int a[N];
	int query(int x){
		return a[x];
	}
}S;
void add(int x){
	S.a[++cnt[x]]++;
};
void del(int x){
	S.a[cnt[x]--]--;
}
int main(){
//	freopen("questions.in","r",stdin);
//	freopen("questions.out","w",stdout);
	for(read(n),i=1;i<=n;i++)read(a[i]),pos[i]=i/M;
	for(read(m),i=1;i<=m;i++)
	read(q[i].l),read(q[i].r),read(q[i].k),q[i].rk=i;
	sort(q+1,q+m+1);
	for(i=1;i<=m;i++){
		while(l>q[i].l)add(a[--l]);
		while(r<q[i].r)add(a[++r]);
		while(l<q[i].l)del(a[l++]);
		while(r>q[i].r)del(a[r--]);	
		ans[q[i].rk]=S.query(q[i].k);
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}

