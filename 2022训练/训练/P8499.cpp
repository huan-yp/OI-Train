#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y>x)x=y;}
const int mods[]={998244353,1000000009,1000000007,1000010029};
const int base=19260817,N=1e5+10;
struct hn{
	int h[4],sz;
	friend bool operator <(const hn &a,const hn &b){
		if(a.sz!=b.sz)return a.sz<b.sz;
		for(int i=0;i<=3;i++)if(a.h[i]!=b.h[i])
		return a.h[i]<b.h[i];
		return 0;
	}
	friend bool operator ==(const hn &a,const hn &b){
		return a.sz==b.sz&&a.h[0]==b.h[0]&&a.h[1]==b.h[1]&&a.h[2]==b.h[2]&&a.h[3]==b.h[3];
	}
	void operator +=(const hn &a){
		sz+=a.sz;
		h[0]=(1ll*h[0]*base+1ll*a.h[0]*a.sz)%mods[0];
		h[1]=(1ll*h[1]*base+1ll*a.h[1]*a.sz)%mods[1];
		h[2]=(1ll*h[2]*base+1ll*a.h[2]*a.sz)%mods[2];
		h[3]=(1ll*h[3]*base+1ll*a.h[3]*a.sz)%mods[3];
	}
	void reset(){
		sz=h[0]=h[1]=h[2]=h[3]=1;
	}
};
int i,j,k,m,n,s,t,d,flag,l1,l2;
int a[2][N],ok[N],vis[N],lim[10];
vector<int> e[2][N];
hn hv[2][N];
void dfs(int u,int op){
	hv[op][u].reset();
	vector<hn> ve(0);
	for(auto v:e[op][u]){
		if(ok[v])continue;
		dfs(v,op);
		ve.push_back(hv[op][v]);
	}
	sort(ve.begin(),ve.end());
	for(auto v:ve)
	hv[op][u]+=v;
}
int solve(int u1,int u2);
int match(int dep,int lm,int vis[],
const vector<pair<hn,int>> &a1,const vector<pair<hn,int>> &a2){
	lim[0]=lm;
	if(dep==a1.size()){
		return true;
	}
	for(int i=0;i<a2.size();i++){
		if(vis[i]>lim[i]||a2[i].first.sz>=a1[dep].first.sz)continue;
		vis[i]++;
		int ans=match(dep+1,lm,vis,a1,a2)&&solve(a1[dep].second,a2[i].second);
		vis[i]--;
		if(ans)return true;
	}
	return false;
}
int solve(int u1,int u2){
	if(u2==0)return true;
	int d=hv[0][u1].sz-hv[1][u2].sz;
	set<pair<hn,int>> st1,st2,er;
	vector<pair<hn,int>> a1,a2;
	a1.emplace_back(hv[0][0],0),a2.emplace_back(hv[0][0],0);
	for(int v:e[0][u1])st1.insert({hv[0][v],v});
	for(int v:e[1][u2])st2.insert({hv[1][v],v});
	for(auto x:st2){
		auto tmp=st1.lower_bound({x.first,0});
		if(tmp!=st1.end()&&(*tmp).first==x.first)
		er.insert(x),st1.erase(tmp);
	}
	for(auto x:er)st2.erase(x);
	if(st2.size()>st1.size()||st1.size()>d)return 0;
	for(auto x:st1)a1.push_back(x);for(auto x:st2)a2.push_back(x);
	int vis[10];memset(vis,0,sizeof(vis));
	return match(1,st1.size()-st2.size()-1,vis,a1,a2);
}
int main(){
	int tot,test;
	read(test),read(tot),read(k);
	while(tot--){
		for(read(n),i=1;i<=n;i++)e[0][i].clear();flag=0;
		for(i=1;i<=n;i++){
			read(a[0][i]);
			if(a[0][i]==-1)a[0][0]=i;
			else e[0][a[0][i]].push_back(i);
		}
		for(read(m),i=1;i<=m;i++)e[1][i].clear();
		d=n-m;
		for(i=1;i<=m;i++){
			read(a[1][i]);
			if(a[1][i]==-1)a[1][0]=i;
			else e[1][a[1][i]].push_back(i);
		}
		dfs(a[1][0],1);
		dfs(a[0][0],0);
		if(solve(a[0][0],a[1][0]))
		puts("Yes");
		else
		puts("No");
	}
	return 0;
}

