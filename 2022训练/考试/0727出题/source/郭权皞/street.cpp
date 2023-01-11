#include<bits/stdc++.h>
using namespace std;
#define N 100001
#define pb push_back 
int n,h[N],leaf[N],mask[N];
vector<int>g1[N],g2[N];//g1为小弟儿子集合,g2为非小弟儿子集合 
double dp[N];
void dfs(int x){
	leaf[x]=mask[x];
	for(auto v:g1[x]){
		dfs(v);
		leaf[x]+=leaf[v];
	}
	for(auto v:g2[x]){
		dfs(v);
		leaf[x]+=leaf[v];
	}
}
int cmp2(int a,int b){
	return leaf[a]<leaf[b];
}
int cmp1(int a,int b){
	return leaf[a]>leaf[b];
}
void solve(int x){
	for(auto v:g1[x]) solve(v);
	for(auto v:g2[x]) solve(v);
	sort(g1[x].begin(),g1[x].end(),cmp1);
	sort(g2[x].begin(),g2[x].end(),cmp2);
	double fenzi=0,fenmu=leaf[x],zfenzi=leaf[x],zfenmu=leaf[x];
	for(auto v:g1[x]){
		if(fenmu==0) break;
		fenzi=leaf[v];
		dp[x]+=zfenzi/zfenmu*(1+dp[v]*fenzi/fenmu+(fenmu-fenzi)/fenmu);
		zfenzi-=leaf[v];fenmu-=leaf[v];
	}
	for(auto v:g2[x]){
		if(fenmu==0) break;
		fenzi=leaf[v];
		dp[x]+=zfenzi/zfenmu*(1+dp[v]*fenzi/fenmu+(fenmu-fenzi)/fenmu);
		zfenzi-=leaf[v];fenmu-=leaf[v];
	}
}
int main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;
		char opt;
		cin>>x>>opt;
		if(opt=='Y') g1[x].pb(i),h[i]=1;
		else g2[x].pb(i);
	}
	for(int i=1;i<=n;i++)
		if(g1[i].size()==g2[i].size()&&g1[i].size()==0)
			leaf[i]=1,mask[i]=1;
	dfs(1);
	solve(1);
	cout<<dp[1]<<endl;
	//for(int i=1;i<=n;i++)
	//	sort(g1[i].begin(),g1[i].end(),cmp1),sort(g2[i].begin(),g2[i].end(),cmp2);
	return 0;
}
//5 1 N 1 Y 3 N 3 N
