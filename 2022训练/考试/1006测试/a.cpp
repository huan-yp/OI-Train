#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
const int N=3e5+10,M=1024;
int i,m,n,t,A,B;
struct point{
	int x,y,rk;
}p[N];
int dis[N],l[N],r[N],sum[N],b[N];
vector<int> _e[N],e[N];
priority_queue<pair<int,int>> q;
void dfs(int u,int a[]){
	for(auto v:_e[u]){
		if(a[v])continue;
		a[v]=a[u];
		dfs(v,a);
	}
}
void solve(){
	memset(dis,1,sizeof(dis));queue<int> q;
	for(i=1;i<=n;i++)if(p[i].x==0)dis[i]=1,q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			if(dis[v]<=dis[u]+1)continue;
			dis[v]=dis[u]+1,q.push(v);
		}
	}
	for(i=1;i<=n;i++)if(p[i].x==A&&dis[i]<=n)sum[lower_bound(b+1,b+t+1,p[i].y)-b]++;
	for(i=1;i<=t;i++)sum[i]+=sum[i-1];
	sort(p+1,p+n+1,[](point a,point b)->bool{return a.y<b.y;});
	for(i=1;i<=n;i++)if(p[i].x==A&&!l[p[i].rk]){
		l[p[i].rk]=lower_bound(b+1,b+t+1,p[i].y)-b;
		dfs(p[i].rk,l);
	}
	sort(p+1,p+n+1,[](point a,point b)->bool{return a.y>b.y;});
	for(i=1;i<=n;i++)if(p[i].x==A&&!r[p[i].rk]){
		r[p[i].rk]=lower_bound(b+1,b+t+1,p[i].y)-b;
		dfs(p[i].rk,r);
	}
	sort(p+1,p+n+1,[](point a,point b)->bool{return a.rk<b.rk;});
}
int main(){
	read(n),read(m),read(A),read(B);
	for(i=1;i<=n;i++)read(p[i].x),read(p[i].y),b[++t]=p[i].y,p[i].rk=i;
	sort(b+1,b+t+1);t=unique(b+1,b+t+1)-b-1;
	for(i=1;i<=m;i++){
		int x,y,k;
		read(x),read(y),read(k);
		e[x].push_back(y);_e[y].push_back(x);
		if(k!=1)e[y].push_back(x),_e[x].push_back(y);
	}
	solve();
	for(i=1;i<=n;i++)if(p[i].x==0)q.push(make_pair(p[i].y,sum[r[i]]-sum[l[i]-1]));
	while(!q.empty()){
		printf("%d\n",q.top().second);
		q.pop();
	}
	return 0;
}

