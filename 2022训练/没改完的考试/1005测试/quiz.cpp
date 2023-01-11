#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int M=105,N=200005;
int i,j,k,m,n,s,t,tot,pot=1;
int answer[N],cnt[N];
double dp[2][N],ans[N],a[N];
char ch[N];
vector<int> quiz[N],as[N],e[N];
__gnu_pbds::gp_hash_table<string,int> mp;
__gnu_pbds::gp_hash_table<int,int> son[N];
void scans(string &x){
	x="";scanf("%s",ch+1);int len=strlen(ch+1);
	for(int i=1;i<=len;i++)x+=ch[i];
}
void add(int u,vector<int>::iterator it){
	if(it==quiz[i].end()){
		as[u].push_back(answer[i]);
		return ;
	}
	if(son[u].find(*it)==son[u].end())son[u][*it]=++pot,e[u].push_back(pot);
	add(son[u][*it],next(it));
}
void dfs(int u,int maxn=0){
	for(auto v:e[u]){
		dfs(v);
		for(auto w:as[v])as[u].push_back(w);	
	}
	for(auto w:as[u])cnt[w]++,cmax(maxn,cnt[w]);
	for(auto w:as[u])cnt[w]--;
	a[u]=((double)(1.0))*maxn/as[u].size();
}
int main(){
	read(t),read(n);
	for(i=1;i<=n;i++){
		string w;
		while(1){
			scans(w);if(mp.find(w)==mp.end())mp[w]=++tot;
			if(getchar()!=' ')break;
			quiz[i].push_back(mp[w]);
		}
		answer[i]=mp[w];
		add(1,quiz[i].begin());
	}
	dfs(1);
	for(i=1;i<=t;i++)for(j=1;j<=pot;j++){
		dp[i&1][j]=dp[i-1&1][1]+a[j];
		double sum=0,all=as[j].size();
		for(auto v:e[j]){
			sum+=dp[i-1&1][v]*as[v].size()/all;
		}
		cmax(dp[i&1][j],sum);
	}
	printf("%0.8lf\n",dp[t&1][1]);
	return 0;
}

