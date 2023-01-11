#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=3e3+10,mod=1e9+7;
int i,j,k,n,s,t,m,len;
int po[N]={1},f[N]={1};
int son[N][26],fail[N],dp[2][N][N];
char ch[N];
void add()
{
	for(i=1;i<=n;i++)
	{
		fail[i]=son[fail[i-1]][ch[i]-'a'];
		son[i-1][ch[i]-'a']=i;
		for(j=0;j<26;j++)
		{
			if(j!=ch[i+1]-'a')
			son[i][j]=son[fail[i]][j];
		}
	}
}
signed main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1);
	read(m);
	n=strlen(ch+1);
	add();
	for(i=1;i<=m;i++)
	po[i]=1ll*po[i-1]*26%mod;
	for(i=n-1;i>=0;i--)
	{
		int p=1;
		for(j=1;j<=i;j++)
		if(ch[j]!=ch[n-i+j])
		{
			p=0;
			break;
		}
		if(p)
		{
			len=i;
			break;
		}
	}
	if(m<n)
	{
		printf("%lld",po[m]);
		return 0;
	}
	int maxn=1+(m-n)/(n-len);
	dp[0][0][0]=1;
	for(i=0;i<m;i++)
	for(j=0;j<=n;j++)
	for(k=max(0,(i<n?0:(1+(i-n)/(n-len)))-1);k<=(i<n?0:(1+(i-n)/(n-len)));k++)
	{
		if(dp[i&1][j][k]==0)continue;
		for(s=0;s<26;s++)
		{
			if(son[j][s]==n)
			dp[(i+1)&1][fail[n]][k+1]=(dp[(i+1)&1][fail[n]][k+1]+dp[i&1][j][k])%mod;
			else
			dp[(i+1)&1][son[j][s]][k]=(dp[(i+1)&1][son[j][s]][k]+dp[i&1][j][k])%mod;
		}
		dp[i&1][j][k]=0;//滚动数组要清空 
	}
	int ans=0;
	for(i=0;i<=n;i++)
	ans=(ans+dp[m&1][i][maxn])%mod;
	cout<<ans;
	return 0;
}
