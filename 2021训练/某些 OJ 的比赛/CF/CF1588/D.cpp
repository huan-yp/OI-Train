#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
const int N=512;
int i,j,k,n,s,t,m;
int dp[N][N],pos[N][N][2],from[N][N][2],len[N],maxn[N];
char ch[N][N];
void print(int x,int mask)
{
	if(dp[x][mask]>1)
	print(from[x][mask][0],from[x][mask][1]);
	if(dp[x][mask])
	printf("%c",ch[n][x]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(pos,0,sizeof(pos));
		memset(maxn,0,sizeof(maxn));
		read(n);
		for(i=1;i<=n;i++)
		scanf("%s",ch[i]+1),len[i]=strlen(ch[i]+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=len[i];j++)
			if(pos[i][ch[i][j]][0]==0)
			pos[i][ch[i][j]][0]=j;
			else
			pos[i][ch[i][j]][1]=j;
		}
		for(i=1;i<=len[n];i++)
		for(int mask=0;mask<1<<n-1;mask++)
		{
			int flag=0;
			for(j=1;j<n;j++)
			{
				int es=((1<<j-1)&mask)?1:0;
				if(pos[j][ch[n][i]][es]==0)flag=1;
			}
			if(flag)continue;
			dp[i][mask]=1;
			for(j=1;j<i;j++)
			{
				int cnt=0,all=0;
				for(k=1;k<n;k++)
				{
					int es=((1<<k-1)&mask)?1:0;
					if(pos[k][ch[n][j]][0]==0||pos[k][ch[n][j]][0]>pos[k][ch[n][i]][es])
					cnt=-1;
				}
				if(cnt==-1)continue;
				for(k=1;k<n;k++)
				{
					int es=((1<<k-1)&mask)?1:0;
					if(pos[k][ch[n][j]][1]==0||pos[k][ch[n][j]][1]>pos[k][ch[n][i]][es])continue;
					all|=1<<k-1;
				}
				if(ch[n][i]==ch[n][j])
				{
					int tomask=0;
					if(dp[j][tomask]+1>dp[i][mask]&&mask==(1<<n-1)-1)
					dp[i][mask]=dp[j][tomask]+1,from[i][mask][0]=j,from[i][mask][1]=tomask;
					continue;
				}
				
				for(int mask2=all;;mask2=(mask2-1)&all)
				{
					if(maxn[j]<dp[i][mask])break;
					if(dp[j][mask2]+1>dp[i][mask])
					dp[i][mask]=dp[j][mask2]+1,from[i][mask][0]=j,from[i][mask][1]=mask2;
					if(mask2==0)break;
				}
			}
			cmax(maxn[i],dp[i][mask]);
		}
		int ans=0,flag=1;
		for(i=1;i<=len[n];i++)
		for(int mask=0;mask<1<<n-1;mask++)
		cmax(ans,dp[i][mask]);
		for(i=1;i<=len[n]&&flag;i++)
		for(int mask=0;mask<(1<<n-1)&&flag;mask++)
		{
			if(ans==dp[i][mask])
			{
				cout<<ans<<endl;
				print(i,mask);
				printf("\n");
				flag=0;
			}
		}
	}
	return 0;
}

