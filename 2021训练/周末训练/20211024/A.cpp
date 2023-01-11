#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<long long,long long>
#define fi first
#define se second
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,n,s,t,m,d,b;
int c[N],ls[N],dp[N];
priority_queue<int> q;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;read(T);
	while(T--)
	{
		read(n),read(d);
		for(i=1;i<=n;i++)read(c[i]);
		sort(c+1,c+n+1);
		for(i=1;i<=n;i++)c[i]=c[i]-(i-1)*d;
		q.push(c[1]);k=0,b=0;
		//dp[i][x]=min(dp[i-1][x]+|x-a[i]|)
		for(i=2;i<=n;i++)
		{
			q.push(c[i]);
			q.push(c[i]);

			k++,b-=c[i];
			while(!q.empty()&&q.top()>0&&k>0)
			{
				int x=q.top(),y=x*k+b;q.pop();
				k--,b=y-x*k;
			} 
			int nowx=q.empty()?(0ll):(max(q.top(),0ll));
			b=nowx*k+b;k=0;
			dp[i]=nowx*k+b;
		}
		while(!q.empty())q.pop();
		cout<<dp[n]<<endl;
	}
	return 0;
}

