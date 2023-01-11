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
const int N=35;
int i,j,k,n,s,t,m,ans;
int dp[2][N][N][N*N*4],pos[N][3],a[N],cnt[3];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1);n=strlen(ch+1);
	read(k);k=min(k,1000ll);
	for(i=1;i<=n;i++)
	{
		if(ch[i]=='K')a[i]=0,pos[++cnt[0]][0]=i;
		if(ch[i]=='E')a[i]=1,pos[++cnt[1]][1]=i;
		if(ch[i]=='Y')a[i]=2,pos[++cnt[2]][2]=i;
	}
	dp[0][0][0][0]=1;
	for(i=0;i<n;i++)
	for(int c0=0;c0<=i&&c0<=cnt[0];c0++)
	for(int c1=0;c1+c0<=i&&c1<=cnt[1];c1++)
	{
		int c2=i-c0-c1;if(c2>cnt[2])continue;
		int to0=0,to1=0,to2=0;
		for(int j=1;j<=c0;j++)to1+=pos[j][0]>pos[c1+1][1],to2+=pos[j][0]>pos[c2+1][2];
		for(int j=1;j<=c1;j++)to0+=pos[j][1]>pos[c0+1][0],to2+=pos[j][1]>pos[c2+1][2];
		for(int j=1;j<=c2;j++)to0+=pos[j][2]>pos[c0+1][0],to1+=pos[j][2]>pos[c1+1][1];
		for(int r=0;r<=k*2;r++)
		{
			int &val=dp[i&1][c0][c1][r];
			if(val==0)continue;
			
			to0=max(to0,0ll);to1=max(to1,0ll);to2=max(to2,0ll);
			if(c0!=cnt[0])dp[(i+1)&1][c0+1][c1+0][r+to0]+=val;
			if(c1!=cnt[1])dp[(i+1)&1][c0+0][c1+1][r+to1]+=val;
			if(c2!=cnt[2])dp[(i+1)&1][c0+0][c1+0][r+to2]+=val;
			val=0;
		}
	}
	for(int r=0;r<=k;r++)
	{
	//	if(r%2)
	//	assert(dp[n&1][cnt[0]][cnt[1]][r]==0);
		ans+=dp[n&1][cnt[0]][cnt[1]][r];
	}
	printf("%lld\n",ans);
	return 0;
}

