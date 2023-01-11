#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
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
const int N=3e5+10;
int i,j,k,m,n,s,t,T;
int a[N][3],ans[N],vis[N],dis[N];
vector<pii> e[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<int> p;
int check(int l,int r){
	s+=r-l+1;
	p.clear();p.push_back(1);
	for(i=l;i<=r;i++){
		p.push_back(a[i][0]),p.push_back(a[i][1]);
		e[a[i][0]].emplace_back(a[i][1],a[i][2]);
		e[a[i][1]].emplace_back(a[i][0],a[i][2]);
	}
	q.push(make_pair(0,1));dis[1]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:e[u]){
			if(dis[v]<=dis[u]+w)continue;
			dis[v]=dis[u]+w;
			q.push(make_pair(dis[v],v));
		}
	}
	int flag=dis[n]<=T;
	for(auto u:p)vis[u]=0,dis[u]=0x3f3f3f3f,e[u].clear();
	return flag;
}
int get_ans(int f,int x,int y){
	int l=x,r=y-1,ret=y;
	while(r>=l){
		int mid=(l+r)/2;
		if(check(f,mid))
		ret=mid,r=mid-1;
		else
		l=mid+1;
	}
	return ret;
}
int main(){
//	freopen("path.in","r",stdin);
//	freopen("path.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	read(n),read(m),read(T);
	for(i=1;i<=m;i++)
	read(a[i][0]),read(a[i][1]),read(a[i][2]);
	int l=1;
	while(l<=m){
		int len=1;
		while(l+len-1<=m){
			if(check(l,l+len-1))break;
			len<<=1;
		}
		int res=get_ans(l,l+(len>>1),min(l+len-1,m+1));l=res+1;
		if(res<=m)ans[++ans[0]]=res;
	}
	cout<<ans[0]<<'\n';
	for(i=1;i<=ans[0];i++)
	cout<<ans[i]<<' ';
	return 0;
}

