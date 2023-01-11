#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=6e5+10;
int n,m;
pii uzi(int x){
	return make_pair((x-1)/m,(x-1)%m+1);
}
int zip(int x,int y){
	return x*m+y;
}
int dis[N],vis[N];
char* ch[N];
priority_queue<pii> q;
void ___solve(){
	int i,j;
	read(n),read(m);
	int c1,c2;
	read(c1),read(c2);
	for(i=1;i<=n;i++){
		ch[i]= new char[m+5];
		scanf("%s",ch[i]+1);
	}
	memset(dis,31,sizeof(dis));
	int ans=1e18;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(ch[i][j]=='.'){
		q.push(make_pair(0,zip(i,j)));
		dis[zip(i,j)]=0;	
	}
	map<char,pii> d;
	vector<pii> v{{1,0},{-1,0},{0,1},{0,-1}};
	d['L']={0,1};
	d['R']={0,-1};
	d['U']={1,0};
	d['D']={-1,0};
	while(!q.empty()){
		int x,y;
		tie(x,y)=uzi(q.top().second);q.pop();
		if(vis[zip(x,y)])continue;
		vis[zip(x,y)]=1;
		for(auto [dx,dy]:v){
			int tx=x+dx,ty=y+dy;
			if(tx<1||tx>n||ty<1||ty>m||ch[tx][ty]=='.'||ch[tx][ty]=='#')continue;
			int fx=tx+d[ch[tx][ty]].first,fy=ty+d[ch[tx][ty]].second,ds=abs(fx-x)&1?c1:c2;
			if(dis[zip(fx,fy)]<=dis[zip(x,y)]+ds)continue;
			dis[zip(fx,fy)]=dis[zip(x,y)]+ds;
			q.push(make_pair(-dis[zip(fx,fy)],zip(fx,fy)));
		}
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		for(auto [dx,dy]:v){
			int tx=i+dx,ty=j+dy;
			if(tx<1||tx>n||ty<1||ty>m)continue;
			cmin(ans,dis[zip(i,j)]+dis[zip(tx,ty)]);
		}
	}
	if(ans<=1e16)
	cout<<ans<<endl;
	else
	puts("-1");
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


