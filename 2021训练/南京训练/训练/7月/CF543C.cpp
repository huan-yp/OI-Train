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
const int N=1<<20,M=25;
int i,j,k,n,s,t,m;
int dp[N],a[M][M],g[M][M],cnt[N],val[M][M];
char ch[M][M];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	scanf("%s",ch[i]+1);
	
	for(i=1;i<N;i++)
	cnt[i]=__builtin_popcount(i);
	
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(a[i][j]);
	
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	for(k=1;k<=n;k++)
	if(ch[i][j]==ch[k][j])
	g[i][j]|=1<<k-1,val[i][j]+=a[k][j];
	
	
	for(i=1;i<=n;i++)
	{
		int flag=0;
		for(j=1;j<=m;j++)
		{
			int p=1;
			for(k=1;k<=n;k++)
			if(ch[i][j]==ch[k][j])
			p=0;
			
			flag|=p;
		}
//		s|=flag<<i-1;
	}
	for(i=0;i<N;i++)
	dp[i]=INF;
	
	dp[s]=0;
	//��һ����Ϊ��ֻͬ�����ַ�ʽ��
	//���Լ��͸���������
	//��һ����Ҫ��������һ��
	//һ�ο��Ըĺܶ� 
	//ת��˳��Ӱ��𰸣����Կ���ֻѡһ��ת��
	//����ע�⣬ת�ƶ����ʱ��Ӧ��ѡ���ŵ�
	for(int mask=s;mask<1<<n;mask++)
	{
		for(i=1;i<=n;i++)
		{
			if(mask&(1<<i-1))continue;
			for(j=1;j<=m;j++)
			{
				int to=mask|(1<<i-1);
				dp[to]=min(dp[to],dp[mask]+a[i][j]);
				to=mask|g[i][j];
				dp[to]=min(dp[to],dp[mask]+val[i][j]-a[i][j]);
			}
			break;
		}
	}
	printf("%d",dp[(1<<n)-1]);
	return 0;
}


