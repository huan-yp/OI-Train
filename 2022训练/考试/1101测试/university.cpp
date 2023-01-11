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
const int N=3e5+10,mod=998244353;
int i,j,k,m,n,s,t;
int fa[N]; 
vector<int> e[N];
set<int> st[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return ;fa[v]=u;
	if(st[u].size()<st[v].size())swap(st[u],st[v]);
	for(auto w:st[v])st[u].insert(w);
}
int main(){
//	freopen("university.in","r",stdin);
//	freopen("university.out","w",stdout);
	read(n),read(m);
	for(i=1;i<=m;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	int ans=1;
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=n;i++){
		int rk=find(i);
		for(auto v:e[i]){
			if(v>i)st[rk].insert(v);
			else merge(rk,v);
		}
		while(st[rk].begin()!=st[rk].end()&&*st[rk].begin()<=i)
		st[rk].erase(st[rk].begin());
		ans=1ll*(n-st[rk].size())*ans%mod;
	}
	cout<<ans<<endl; 
	return 0;
}

