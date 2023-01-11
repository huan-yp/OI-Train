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
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
dp[i][j] 填好了前 i 个，一共有 j 个相同的缝隙
cnt[i]
for (k cnt[i])
dp[i-1][j] -> dp[i][j+cnt[]] 

cout<<dp[][];
*/
const int N=1005,mod=1234567891;
int i,j,k,n,s,t,m;
int a[N],cnt[N],C[N][N],f[N]={1};
LL dp[N][N];
void init()
{
	C[0][0]=1;
	for(i=1;i<N;i++)
	{
		f[i]=1ll*f[i-1]*i%mod;
		C[i][0]=1;
		for(j=1;j<N;j++)
		C[i][j]=(0ll+C[i-1][j]+C[i-1][j-1]),C[i][j]%=mod;
	}
}
class PSequence{
	public:
	int count(vi S, int p)
	{
		init();
		n=S.size();int all=1;
		for(i=1;i<=n;i++)
		a[i]=S[i-1],cnt[(a[i]%p+p)%p]++;
		
		for(i=0;i<=p;i++)
		if(cnt[i])break;
		
		dp[i][cnt[i]-1]=f[cnt[i]]; 
		for(;i<p-1;i++)
		{
			all+=cnt[i];
			for(j=0;j<all;j++)
			{
				if(dp[i][j]==0)continue;
				if(cnt[i+1]==0)dp[i+1][j]=dp[i][j];
				for(k=1;k<=cnt[i+1];k++)
				{
					for(s=0;s<=k&&s<=j;s++)
					{
						int to=j+cnt[i+1]-k-s;
						dp[i+1][to]+=1ll*dp[i][j]*C[j][s]%mod*C[all-j][k-s]%mod*C[cnt[i+1]-1][k-1]%mod*f[cnt[i+1]]%mod;
						dp[i+1][to]%=mod;
					}
				}
			}
		}
		return int(dp[p-1][0]);
	}
};


