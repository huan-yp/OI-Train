#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,used[N],fa,sz[N];
double f[N][2],p[N];
vector<int> ve[N];
string s;

void pre(int x){
	if(!ve[x].size()){
		sz[x]=1;
		return ;
	}
	for(auto i:ve[x]){
		pre(i);
		sz[x]+=sz[i];
	}
	for(auto i:ve[x]) p[i]=(double)sz[i]/sz[x];
}

bool cmp(int aa,int bb){
	return p[bb]*(f[aa][0]+2)<p[aa]*(f[bb][0]+2);
}

void dfs(int x){
	if(!ve[x].size()) return ;
	for(auto i:ve[x]) dfs(i);
	sort(ve[x].begin(),ve[x].end(),cmp);
	double qzh=1;
	for(auto i:ve[x]){
		f[x][0]+=f[i][0]+2;
		f[x][1]+=p[i]*(f[i][1]+qzh);
		qzh+=f[i][0]+2;
	}
	if(used[x]) f[x][0]=0;
}

int main(){
	
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++){
		cin>>fa>>s;
		if(s=="Y") used[i]=1;
		ve[fa].push_back(i);
	}
	pre(1);
	dfs(1);
	printf("%.10f",f[1][1]);
	return 0;
}