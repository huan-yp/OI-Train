#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1.6e6+100;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int i,j,k,n,s,t,m,h,w,sx,sy,gx,gy,cnt;
int b[N],dis[N],X[N],Y[N],vis[N];
set<int> stx[N],sty[N];
vector<int> e[N];
map<pii,int>mp;
priority_queue<pii>q;
int ok(int x,int y){
	return x>=1&&x<=m&&y>=1&&y<=m;
}
void dij(){
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:e[u]){
			if(dis[v]<=dis[u]+1)continue;
			dis[v]=dis[u]+1;
			q.push(make_pair(-dis[v],v));
		}
	}	
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(h),read(w),read(n);
	read(sx),read(sy),read(gx),read(gy);
	b[++cnt]=sx,b[++cnt]=sy,b[++cnt]=gx,b[++cnt]=gy;
	if(sx==gx&&sy==gy){
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++){
		read(X[i]),read(Y[i]);
		b[++cnt]=X[i],b[++cnt]=Y[i];
		if(X[i]!=h)b[++cnt]=X[i]+1;if(Y[i]!=w)b[++cnt]=Y[i]+1;
		if(X[i]!=1)b[++cnt]=X[i]-1;if(Y[i]!=1)b[++cnt]=Y[i]-1;
	}
	sort(b+1,b+cnt+1);m=unique(b+1,b+cnt+1)-b-1;
	sx=lower_bound(b+1,b+m+1,sx)-b,sy=lower_bound(b+1,b+m+1,sy)-b;
	gx=lower_bound(b+1,b+m+1,gx)-b,gy=lower_bound(b+1,b+m+1,gy)-b;
	mp[make_pair(sx,sy)]=++k;mp[make_pair(gx,gy)]=++k;
	for(i=1;i<=n;i++){
		X[i]=lower_bound(b+1,b+m+1,X[i])-b;
		Y[i]=lower_bound(b+1,b+m+1,Y[i])-b;
		stx[X[i]].insert(Y[i]);
		sty[Y[i]].insert(X[i]);
		for(j=0;j<4;j++){
			int tox=X[i]+dx[j],toy=Y[i]+dy[j];
			if(!ok(tox,toy))continue;
			if(mp.find(make_pair(tox,toy))!=mp.end())continue;
			mp.insert(make_pair(make_pair(tox,toy),++k));
		}
	}
	for(auto tmp:mp){
		auto pos=tmp.first;int rk=tmp.second;
		int x=pos.first,y=pos.second;
		auto it=sty[y].lower_bound(x);
		if(*it==x)continue;
		if(it!=sty[y].end())e[rk].push_back(mp.find(make_pair(*it-1,y))->second);
		if(it!=sty[y].begin())e[rk].push_back(mp.find(make_pair(*(--it)+1,y))->second);
		it=stx[x].lower_bound(y);
		if(it!=stx[x].end())e[rk].push_back(mp.find(make_pair(x,*it-1))->second);
		if(it!=stx[x].begin())e[rk].push_back(mp.find(make_pair(x,*(--it)+1))->second);
	}
	for(i=1;i<=k;i++)dis[i]=INF;
	dis[1]=0;dij();
	if(dis[2]!=INF)printf("%d",dis[2]);
	else puts("-1");
	return 0;
}

