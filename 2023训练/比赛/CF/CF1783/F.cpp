#include<bits/stdc++.h>
#define LL long long 
using namespace std;
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=6005;
int i,j,k,m,n,s,t;
struct permutation{
	vector<int> c[N];
	int p[N],rk[N],count;
	void init(){
		for(i=1;i<=n;i++)read(p[i]);
		for(i=1;i<=n;i++)if(!rk[p[i]]){
			count++,s++;
			int now=p[i];
			do{
				rk[now]=s;
				c[count].emplace_back(now);
				now=p[now];
			}while(!rk[now]);
		}
	}
}a,b;
struct graph{
	vector<pair<int,int>> e[N];
	int match[N][2],vis[N],count,n;
	void add_edge(int u,int v,int p){
		e[u].emplace_back(v,p);
	}
	int find_match(int u){
		if(vis[u])return 0;
		vis[u]=1;
		for(auto [v,p]:e[u])if(!match[v][0]||find_match(match[v][0])){
			match[v][0]=u;match[v][1]=p;
			return 1;
		}
		return 0;
	}
	int max_match(){
		for(i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			count+=find_match(i);
		}
		return count;
	}
}G;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);
	a.init(),b.init();
	G.n=a.count;
	for(i=1;i<=a.count;i++)
	for(auto v:a.c[i])
	G.add_edge(i,b.rk[v],v);
	cout<<n-G.max_match()<<endl; 
	set<int> v;
	for(i=G.n+1;i<=s;i++)
	if(G.match[i][0])v.insert(G.match[i][1]);
	for(int i=1;i<=n;i++)if(v.find(i)==v.end())printf("%d ",i);
	return 0;
} 
