#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
bool ask[100005];
int sze[100005],lef[100005];
int sum[100005];
vector<int>v[100005];
char ch[11];
bool cmp1(int x,int y){
	return 1ll*sze[x]*lef[y]<1ll*sze[y]*lef[x];
}
bool cmp2(int x,int y){
	return lef[x]<lef[y];
}
void dfs(int x){
	sze[x]=1;
	if(v[x].size()==0)lef[x]=1;
	sum[x]=0;
	vector<int>v0,v1;
	for(int i=0;i<v[x].size();++i){
		dfs(v[x][i]);
		sze[x]+=sze[v[x][i]]; 
		sum[x]+=sum[v[x][i]];
		lef[x]+=lef[v[x][i]];
		if(ask[v[x][i]]){
			v1.push_back(v[x][i]);
		}else{
			v0.push_back(v[x][i]);
		}
	}
	sort(v1.begin(),v1.end(),cmp2);
	sort(v0.begin(),v0.end(),cmp1);
	sum[x]+=lef[x];
	if(v[x].size()==0)--sum[x];
	int k=lef[x],j=0;
	for(int i=0;i<v1.size();++i){
		if(j==v0.size()||lef[v0[i]]<=sze[v0[i]]*lef[v1[i]]){
			k-=lef[v1[i]];
			sum[x]+=2ll*k;
		}else{
			k-=lef[v0[j]];
			sum[x]+=2ll*k*sze[v0[j]];
			++j;
		}
	}
	for(;j<v0.size();++j){
		k-=lef[v0[j]];
		sum[x]+=2ll*k*sze[v0[j]];
		++j;
	}
}
int main(){
	//*
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);//*/
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int p;
		scanf("%d%s",&p,ch);
		if(ch[0]=='Y')ask[i]=true;
		else ask[i]=false;
		v[p].push_back(i);
	}
	dfs(1);
	printf("%.10lf\n",1.0*sum[1]/lef[1]);
	return 0;
}
