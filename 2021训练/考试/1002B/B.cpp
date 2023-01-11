#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=405;
int i,j,k,m,n,s,t;
int cnt[3],dp[2][N][N][3],a[N],pos[3][N],sum[3][N][N];
char ch[N];
//dp[i][na][nb][0/1/2]
int main()
{
//	freopen("s.in","r",stdin);
//	freopen("s.out","w",stdout);
	read(n);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i++)
	{
		if(ch[i]=='R')cnt[0]++,a[i]=0,pos[0][cnt[0]]=i;
		if(ch[i]=='G')cnt[1]++,a[i]=1,pos[1][cnt[1]]=i;
		if(ch[i]=='Y')cnt[2]++,a[i]=2,pos[2][cnt[2]]=i;
	}
	for(int op=0;op<=2;op++)
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++)
	sum[op][i][j]=sum[op][i][j-1]+(a[j]==op);

	memset(dp,1,sizeof(dp));
	if(cnt[0])dp[1][1][0][0]=0;
	if(cnt[1])dp[1][0][1][1]=0;
	if(cnt[2])dp[1][0][0][2]=0;
 	for(i=1;i<n;i++)
	for(int c0=0;c0<=cnt[0]&&c0<=i;c0++)
	for(int c1=0;c1<=cnt[1]&&c0+c1<=i;c1++)
	{
		int c2=i-c0-c1;
		if(c2<0||c2>i)continue;
		for(int t0=0;t0<=2;t0++)
		{
			if(dp[i&1][c0][c1][t0]>=1e7)continue;
			if(t0!=0&&c0+1<=cnt[0])
			cmin(dp[(i+1)&1][c0+1][c1][0],dp[i&1][c0][c1][t0]+sum[1][pos[0][c0+1]][pos[1][c1]]+sum[2][pos[0][c0+1]][pos[2][c2]]);
			if(t0!=1&&c1+1<=cnt[1])
			cmin(dp[(i+1)&1][c0][c1+1][1],dp[i&1][c0][c1][t0]+sum[0][pos[1][c1+1]][pos[0][c0]]+sum[2][pos[1][c1+1]][pos[2][c2]]);
			if(t0!=2&&c2+1<=cnt[2])
			cmin(dp[(i+1)&1][c0][c1][2],dp[i&1][c0][c1][t0]+sum[0][pos[2][c2+1]][pos[0][c0]]+sum[1][pos[2][c2+1]][pos[1][c1]]);
			dp[i&1][c0][c1][t0]=1e7;
		}
	}
	int ans=min(dp[n&1][cnt[0]][cnt[1]][0],dp[n&1][cnt[0]][cnt[1]][1]);
	cmin(ans,dp[n&1][cnt[0]][cnt[1]][2]);
	if(ans<1e6)
	printf("%d\n",ans);
	else
	printf("-1\n");
	return 0;
}

