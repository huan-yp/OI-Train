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
const int N=105; 
int i,j,k,n,s,t,m,mod;
int dp[2][N][N],sum[2][N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		//dp[i][j][k]
		//���ǵ��� i ����,���������Ϊ j,SCC ��СΪ k �ķ�����  
		//dp[i][j][k] �ǲ��ظ���
		//k ��ͬ��Ȼ���أ��ڲ���Ȼ����
		//���� j ��ͬ����������ǵ�ǰ�����������ת�ƹ����� 
		// ������Ϊ j>0 ʱת�Ʒ�ʽ�̶������Բ�ͬ�� j k �ı仯��ͬ
		// ����ת�Ʋ�ͬ 
		read(n),read(mod);
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		dp[0][n-1][1]=1;
		for(i=1;i<=n;i++)
		sum[0][n-1][i]=1;
		for(i=1;i<=n*(n-1);i++)
		{
			int opt=0;
			for(j=0;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					int size=n*(n-1)/2+k*(k-1)/2-i;
					sum[1&i][j][k]=sum[1&i][j][k-1];
					if(k+j>n)continue;
					int &val=dp[1&i][j][k];
					val+=dp[(i-1)&1][j+1][k];if(val>=mod)val-=mod;
					val+=sum[(i-1)&1][j][k-1];if(val>=mod)val-=mod;
					if(j==0&&size>=0)val+=dp[(i-1)&1][0][k];
					if(val>=mod)val-=mod;
					sum[1&i][j][k]+=dp[1&i][j][k];
					if(sum[1&i][j][k]>=mod)sum[1&i][j][k]-=mod;
				}
				opt+=sum[1&i][j][n];
				if(opt>=mod)opt-=mod;
			}
			memset(sum[(i-1)&1],0,sizeof(sum[(i-1)&1]));
			memset(dp[(i-1)&1],0,sizeof(dp[(i-1)&1]));
			cout<<opt<<' ';
		}
		printf("\n");
	}
	return 0;
}

