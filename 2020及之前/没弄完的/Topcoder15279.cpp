#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define vi vector<int>
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
//dp[s1][s2]=;
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
考虑图的 bfs 遍历 
发现横叉边只会出现在同一层
dp[s][s1] 表示考虑完 s,末状态 s1 

*/
const int N=25,M=14;
const int mod=1e9+7;
int i,j,k,n,s,t,m;
vi e[N];
int dp[1<<15][205];
class SpanningSubgraphs{
	public:
	vi count(int N,vi a,vi b)
	{
		n=N-1;
		for(i=0;i<a.size();i++)
		e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]);
		dp[0][0]=1;
		for(int v:e[0])
		{
			for(int mask=0;mask<1<<n;mask++)
			dp[mask|v][mask|v]+=dp[mask][mask],dp[mask|v][mask|v]%=mod;
		}
		
		for(int mask1=0;mask1<1<<n;mask1++)
		{
			for(int mask2=mask1;mask2;mask2=(maks2-1)&mask1)
			dp[mask1][mask2]
		}
	}
}; 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	SpanningSubgraphs solve;
	vi ans=solve.count();
	for(auto v:ans)
	printf("%d ",v);	
	
	return 0;
}

