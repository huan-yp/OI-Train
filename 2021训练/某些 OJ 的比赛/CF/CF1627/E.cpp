#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=2e5+10;
struct point{
	int x,rk;
	friend bool operator <(point a,point b){return a.x<b.x;}
};
int i,j,k,n,s,t,m;
int x[N],dp[N],h[N];
vector<point> r[N]; 
int get(int rk){return rk%2?1:-1;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(m),read(k);
		for(i=1;i<=n;i++)r[i].clear();
		h[k+1]=-1ll*INF*INF;
		for(i=1;i<=k+1<<1;i++)dp[i]=1e18;
		r[1].push_back((point){1,k*2+1}),r[n].push_back((point){m,k*2+2});
		for(i=1;i<=n;i++)read(x[i]);
		for(i=1;i<=k;i++)
		{
			int x1,x2,y1,y2;
			read(x1),read(y1),read(x2),read(y2),read(h[i]);
			r[x1].push_back(point{y1,i*2-1});
			r[x2].push_back(point{y2,i*2});
		}
		dp[k*2+1]=0;
		for(i=1;i<=n;i++)
		{
			int lstpos=0,lstans=1e18;
			sort(r[i].begin(),r[i].end());
			for(j=0;j<r[i].size();j++)
			{
				int xx=r[i][j].x,rk=r[i][j].rk;
				cmin(dp[rk],dp[rk+get(rk)]-h[(rk+1)/2]);
				cmin(dp[rk],lstans+x[i]*(xx-lstpos)),
				lstans=dp[rk],lstpos=xx;
			}
			lstpos=m+1,lstans=1e18;
			for(j=(int)r[i].size()-1;j>=0;j--)
			{
				int xx=r[i][j].x,rk=r[i][j].rk;
				cmin(dp[rk],lstans+x[i]*(lstpos-xx)),
				lstans=dp[rk],lstpos=xx;
			}
		}
		if(dp[k+1<<1]>=1e17)
		puts("NO ESCAPE");
		else
		printf("%lld\n",dp[k+1<<1]);
	}
	return 0;
}

