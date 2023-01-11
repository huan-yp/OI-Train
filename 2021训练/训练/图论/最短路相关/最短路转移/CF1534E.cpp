#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=505;
int i,j,k,n,s,t,m,ans;
int dp[N];
set<int> st1,st2;
queue<int> q;
void ask(int x)
{
	set<int> st;st.clear();
	printf("?");
	for(int i=1;i<=x;i++)
	{
		auto it=st1.begin();
		printf(" %d",*it);
		st.insert(*it);
		st1.erase(it);
	}
	for(int i=1;i<=k-x;i++)
	{
		auto it=st2.begin();
		printf(" %d",*it);
		st1.insert(*it);
		st2.erase(*it);
	}
	for(auto v:st)
	st2.insert(v);
	
	printf("\n");
	fflush(stdout);
	read(x);ans^=x;
}
void solve(int x)
{
	if(x==0)return ;
	for(int i=0;i<=k;i++)
	{
		if(x<i||n-x<k-i)continue;
		int to=x+k-2*i;
		if(dp[to]+1==dp[x])
		{
			ask(i);
			solve(to);
			return ;
		}
	}
}
void bfs()
{
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(i=0;i<=k;i++)
		{
			int to=u+k-2*i;
			if(u<i||n-u<k-i)continue;
			if(~dp[to])continue;
			dp[to]=dp[u]+1;
			q.push(to);
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dp,-1,sizeof(dp));
	read(n),read(k);
	if(n%2==1&&k%2==0)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)st1.insert(i);
	q.push(0);dp[0]=0;bfs();
	solve(n);
	printf("! %d\n",ans);
	return 0;
}

