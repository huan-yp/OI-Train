#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
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
const int N=100005,M=55;
int i,j,k,n,s,t,m;
int ans[N],len[N],dp[M][M],mp[M][M];
int pre[11][N],nxt[11][N],vis[11][N],rk[11][N];
set<pii> st[11];
struct MidPoint{
	int k,a[11][2],mx,rank;
	void init(int r)
	{
		read(k);rank=r;
		for(int i=1;i<=k;i++)
		{
			read(a[i][0]),read(a[i][1]);
			a[i][1]=st[a[i][0]].lower_bound(make_pair(a[i][1],0))->second;
		}
		mx=rk[a[1][0]][a[1][1]];
	}
	void insert()
	{
		mp[rank][rank]=mx;
		for(int i=1;i<=k;i++)
		{
			int x=a[i][0],p=a[i][1];
			for(int j=p;j<=len[x];j++)
			{
				if(vis[x][j])
				{
					mp[vis[x][j]][rank]=mp[rank][vis[x][j]]=min(rk[x][j],rk[x][p]);
					break;
				}
				pre[x][j]=rank;
			}
			for(int j=a[i][1];j>=1;j--)
			{
				if(vis[x][j])
				{
					mp[vis[x][j]][rank]=mp[rank][vis[x][j]]=min(rk[x][j],rk[x][p]);
					break;
				}
				nxt[x][j]=rank;
			}
			vis[x][p]=rank;
		}
	}
	friend bool operator <(const MidPoint &a,const MidPoint &b)
	{return a.mx<b.mx;}
		 
}mip[M];
struct query{
	int lu,pu,lv,pv,rank;
	int calc(int mx,int p1,int p2)
	{
		return mx-min(dp[p1][p2],min(rk[lu][pu],rk[lv][pv]))+1; 
	}
	void ask(int mx)
	{
		cmax(mx,rk[lu][pu]);cmax(mx,rk[lv][pv]);
		
		if(nxt[lu][pu]&&nxt[lv][pv])
		cmin(ans[rank],calc(mx,nxt[lu][pu],nxt[lv][pv]));
		if(pre[lu][pu]&&nxt[lv][pv])
		cmin(ans[rank],calc(mx,pre[lu][pu],nxt[lv][pv]));
		if(pre[lu][pu]&&pre[lv][pv])
		cmin(ans[rank],calc(mx,pre[lu][pu],pre[lv][pv]));
		if(nxt[lu][pu]&&pre[lv][pv])
		cmin(ans[rank],calc(mx,nxt[lu][pu],pre[lv][pv]));
	}
}q[N];

signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		read(len[i]),read(len[i]);
		for(j=1;j<=len[i];j++)
		{
			int l,r;
			read(rk[i][j]),read(l),read(r);
			st[i].insert(make_pair(r,j));
		}
	}
	read(s);
	for(i=1;i<=s;i++)mip[i].init(i);
	for(int mp,i=1;i<=n;i++)
	{
		for(j=1;j<=len[i];j++)
		if(rk[i][j-1]>rk[i][j]&&rk[i][j]<rk[i][j+1])mp=j;
		
		mip[s+i].k=1,mip[s+i].mx=rk[i][mp],mip[s+i].rank=s+i;
		mip[s+i].a[1][0]=i,mip[s+i].a[1][1]=mp;
	}
	s+=n;sort(mip+1,mip+s+1);read(m);
	for(i=1;i<=m;i++)
	{
		int xa,xb,ya,yb,pa,pb;ans[i]=INF;
		read(xa),read(xb),read(ya),read(yb);
		int xp=st[xa].lower_bound(make_pair(xb,0))->second;
		int yp=st[ya].lower_bound(make_pair(yb,0))->second;
		q[i]=(query{xa,xp,ya,yp,i});		
		if(xa==ya&&abs(xp-yp)==abs(rk[xa][xp]-rk[xa][yp]))ans[i]=abs(xp-yp)+1;
	}
	for(i=1;i<=s;i++)
	{
		mip[i].insert();
		for(j=1;j<=s;j++)
		for(k=1;k<=s;k++)
		dp[j][k]=mp[j][k]?mp[j][k]:-INF; 
		
		for(t=1;t<=s;t++)
		for(j=1;j<=s;j++)
		for(k=1;k<=s;k++)
		cmax(dp[j][k],min(dp[j][t],dp[t][k]));
		
		for(j=1;j<=m;j++)
		q[j].ask(mip[i].mx);
	}	
	for(i=1;i<=m;i++)
	if(ans[i]>=1e8)printf("-1\n");
	else printf("%d\n",ans[i]);
	return 0;
}

