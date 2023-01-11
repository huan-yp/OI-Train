#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 2000000000
#define LL long long
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
const int N=55;
int i,j,k,n,s,t,m;
int dp[N],from[N];
vector<int> ans;
struct coin{
	int val,rk;
	friend bool operator <(coin a,coin b)
	{
		return a.val<b.val;
	}
}a[N];
void print(int x)
{
	if(x==1)return ;
	ans[a[from[x]].rk-1]=dp[x]-dp[from[x]];
	print(from[x]);
}
class ChangeOptimizer{
	public:
	vector<int> fewestCoins(vector<int> coinTypes, int value)
	{
		n=coinTypes.size(),m=value;a[n+1].val=value+1;dp[n+1]=INF;
		for(i=1;i<=n;i++)a[i].val=coinTypes[i-1],dp[i]=INF,a[i].rk=i;
		
		sort(a+1,a+n+2);dp[1]=0;
		for(i=2;i<=n+1;i++)
		{
			for(j=1;j<i;j++)
			if(a[i].val%a[j].val==0&&dp[j]+a[i].val/a[j].val-1<=dp[i])
			dp[i]=dp[j]+a[i].val/a[j].val-1,from[i]=j;
		}
		for(i=1;i<=n+1;i++)if(a[i].rk==0)s=i;
		for(i=1;i<=n;i++)ans.push_back(0);
		print(s);
		
		return ans;
	}
};
//int main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	ChangeOptimizer solve;
//	ans=solve.fewestCoins(
//	{10, 1}, 1);
//	for(int v:ans)
//	printf("%d ",v);
//
//	return 0;
//}

