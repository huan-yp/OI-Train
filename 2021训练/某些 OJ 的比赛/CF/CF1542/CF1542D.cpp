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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=505,mod=998244353;
int i,j,k,n,s,t,m;
int dp1[N][N][N];
int val[N],op[N];
struct oper{
	int val,rk;
	friend bool operator <(oper aa,oper bb)
	{
		return aa.val<bb.val;
	}
}b[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		char ch[10];
		scanf("%s",ch+1);
		if(ch[1]=='+')
		read(val[i]),b[++t]=(oper){val[i],i};
		else
		op[i]=1;
	}
	sort(b+1,b+t+1);
	for(i=1;i<=t;i++)
	val[b[i].rk]=i;
	for(s=1;s<=t;s++)
	{
		dp1[s][0][0]=1;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(op[i+1])
			{
				dp1[s][i+1][j]+=dp1[s][i][j],dp1[s][i+1][j]%=mod;
				dp1[s][i+1][j-(j>0)]+=dp1[s][i][j],dp1[s][i+1][j-(j>0)]%=mod;
			}
			else
			{
				dp1[s][i+1][j]+=dp1[s][i][j],dp1[s][i+1][j]%=mod;
				dp1[s][i+1][j+(val[i+1]<s)]+=dp1[s][i][j],dp1[s][i+1][j+(val[i+1]<s)]%=mod;
			}
		}	
	}
	int ans=0;
	for(s=1;s<=t;s++)
	{
		dp1[s][n+1][0]=1;
		for(i=n+1;i>=1;i--)
		{
			if(val[i]==s&&op[i]==0)
			{
				for(j=0;j<=n;j++)
				for(k=0;k<=j;k++)
				ans+=1ll*b[val[i]].val*dp1[val[i]][i-1][j]%mod*dp1[val[i]][i+1][k]%mod,ans%=mod;
			}
			memset(dp1[s][i-1],0,sizeof(dp1[s][i-1]));
			for(j=0;j<n;j++)
			{
				if(op[i-1])
				{
					dp1[s][i-1][j]+=dp1[s][i][j],dp1[s][i-1][j]%=mod;
					dp1[s][i-1][j+1]+=dp1[s][i][j],dp1[s][i-1][j+1]%=mod;
				}
				else
				{
					dp1[s][i-1][j]+=dp1[s][i][j],dp1[s][i-1][j]%=mod;
					dp1[s][i-1][j-(val[i-1]<s&&j)]+=dp1[s][i][j],dp1[s][i-1][j-(val[i-1]<s&&j)]%=mod;
				}
			}
		}
	}
	cout<<ans%mod;
	return 0;
}

