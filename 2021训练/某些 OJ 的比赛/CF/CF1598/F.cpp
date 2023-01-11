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
const int N=(1<<20)+10,M=22;
struct query{
	int rk,pos,val,op;
	friend bool operator <(query a,query b)
	{
		return a.pos<b.pos;
	}
}q[N];
const int T=4e5+10;
int i,j,k,n,s,t,m;
int dp[N],sum[N],need[M],cnt[M][N<<1],val[M],fp[M][N<<1],opt[M][T];
int cf[N],st[N],js[N<<1],r[N<<1];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		m=strlen(ch+1);
		int top=0;
		for(j=1;j<=m;j++)
		{
			if(ch[j]=='(')
			top++;
			else
			top--;
			cf[j]=top;
			cmin(need[i],top);
			cnt[i][top+N]++;
			if(fp[i][top+N]==0&&need[i]==top)
			fp[i][top+N]=j;
		}
		val[i]=top;
		cf[m+1]=-INF,st[top=1]=m+1;
		for(j=m;j>=0;j--)
		{
			while(cf[j]<=cf[st[top]]&&top)
			top--;
			r[j]=st[top];
			st[++top]=j;
		}
		for(j=1;j<=m;j++)
		{
			q[j*2]=(query){j,j,cf[j-1]+N,1};
			q[j*2-1]=(query){j,r[j-1],cf[j-1]+N,-1};
		}
		sort(q+1,q+2*m+1);
		int now=2*m;
		memset(js,0,sizeof(js));
		for(j=m+1;j>=1;j--)
		{
			while(q[now].pos==j&&now)
			{
				opt[i][q[now].rk]+=js[q[now].val]*q[now].op;
				now--;
			}
			if(j!=m+1)
			js[cf[j]+N]++;
		}
	}
	for(int mask=0;mask<1<<n;mask++)
	{
		for(i=1;i<=n;i++)
		if((1<<i-1)&mask)
		sum[mask]+=val[i];
	}
	memset(dp,191,sizeof(dp));
	dp[0]=0;int ans=0;
	for(int mask=0;mask<1<<n;mask++)
	{
		for(i=1;i<=n;i++)
		{
			if(mask&(1<<i-1))continue;
			ans=max(ans,dp[mask]+(fp[i][N-sum[mask]]!=0)*(1+opt[i][fp[i][N-sum[mask]]+1]));
			if(sum[mask]+need[i]<0)continue;
			cmax(dp[mask|(1<<i-1)],dp[mask]+cnt[i][N-sum[mask]]);
		}
		cmax(ans,dp[mask]);
	}
	cout<<ans<<endl;
	return 0;
}

