#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define INF 1000000000
#define LL long long
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
const int N=7e5+10;
const int d[6][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1}};
int i,j,k,m,n,s,t;
int p[N][2],a[N][2],fa[N],sz[N];
pair<int,int> b[N];
struct hash_fun{
	long long operator ()(pair<int,int> a)const{
		return (1ll*a.first*(int(2e9))+a.second);
	}
};
__gnu_pbds::cc_hash_table<pair<int,int>,int,hash_fun> mp,ps;
//unordered_map<pair<int,int>,int,hash_fun> mp,ps;
//map<pair<int,int>,int> mp,ps;
void insert(int x,int y){
	a[++s][0]=x,a[s][1]=y;
	mp.insert(make_pair(make_pair(x,y),s));
}
int have(int x,int y){
	return ps.find(make_pair(x,y))!=ps.end();
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
pair<int,int> merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return make_pair(0,0);
	if(sz[v]>sz[u])swap(u,v);
	sz[u]+=sz[v];fa[v]=u;
	return make_pair(u,v);	
}
void split(pair<int,int> x){
	auto [u,v]=x;
	if(u==0)return ;
	sz[u]-=sz[v];
	fa[v]=v;
}
int main(){
	freopen("checkers.in","r",stdin);
	freopen("checkers.out","w",stdout);
	read(n);
	for(i=1;i<=n;i++){
		read(p[i][0]),read(p[i][1]);
		b[++t]=make_pair(p[i][0],p[i][1]);
		insert(p[i][0],p[i][1]);
		ps[make_pair(p[i][0],p[i][1])]=1;
		for(k=0;k<6;k++)
		b[++t]=make_pair(p[i][0]+d[k][0],p[i][1]+d[k][1]);
	}
	sort(b+1,b+t+1);t=unique(b+1,b+t+1)-b-1;
	for(i=1;i<=t;i++)insert(b[i].first,b[i].second);
	for(i=1;i<=s;i++)fa[i]=i,sz[i]=1;
	for(i=1;i<=s;i++){
		if(have(a[i][0],a[i][1]))continue;
		for(k=0;k<6;k++){
			if(have(a[i][0]+d[k][0],a[i][1]+d[k][1])&&!have(a[i][0]+2*d[k][0],a[i][1]+2*d[k][1]))
			merge(i,mp[make_pair(a[i][0]+2*d[k][0],a[i][1]+2*d[k][1])]);
		}
	}
	for(i=1;i<=n;i++){
		vector<pair<int,int>> v;
		for(k=0;k<6;k++){
			if(have(p[i][0]+d[k][0],p[i][1]+d[k][1])&&!have(p[i][0]+2*d[k][0],p[i][1]+2*d[k][1]))
			v.push_back(merge(mp[make_pair(p[i][0],p[i][1])],mp[make_pair(p[i][0]+2*d[k][0],p[i][1]+2*d[k][1])]));
		}
		int rt=find(mp[make_pair(p[i][0],p[i][1])]),ans=sz[rt];
		for(k=0;k<6;k++){
			if(have(p[i][0]+d[k][0],p[i][1]+d[k][1]))continue;
			int v=find(mp[make_pair(p[i][0]+d[k][0],p[i][1]+d[k][1])]);
			ans+=v!=rt;
		}
		while(!v.empty()){
			split(v.back());
			v.pop_back();
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
