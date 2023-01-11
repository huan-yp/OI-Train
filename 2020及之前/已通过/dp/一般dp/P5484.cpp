#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
long long i,j,k,n,s,t,m;
//此行以下是函数板子,时间复杂度O(log10(n)^2)，空间复杂度O(log10(n))
//此版本为压位版本，请使用M调整压位位数，T调整计算范围 (10^(T*log10(M)/2)为最大支持范围)
//时间复杂度O(T^2)，空间复杂度O(T)
//目前仅支持log10(M)为正整数的情况
//在T>4e18/M时乘法不保证一定正确 
//除法暂时只支持除数小于1e9的situation
//FFT和NTT版本敬请期待
//作者：Mao_zx,欢迎转载 
	const long long M=1e17,T=20;
	int pw[10]={1,10,1e2,1e3,1e4,1e5,1e6,1e7,1e8};
	struct num{
		int op;
		long long t[T+1];
		num()
		{
			op=1; 
			for(int i=1;i<=T;i++)
			t[i]=0;
		}
	};
	int cmp(num aa,num bb)
	{
		int i;
		int pd=1;
		for(i=T;i>=1;i--)
		if(aa.t[i]!=bb.t[i])	
		{
			pd=aa.t[i]>bb.t[i];
			break;
		}
		return pd;
	} 
	num add(num aa,num bb)
	{
		int i;
		num ret;
		if(aa.op*bb.op==1)
		{
			ret.op=aa.op;
			for(i=1;i<=T;i++)
			ret.t[i]=aa.t[i]+bb.t[i];
		}
		else
		{
			if(aa.op==-1)
			swap(aa,bb);
			if(cmp(aa,bb))
			ret.op=1;
			else
			{
				ret.op=-1;
				swap(aa,bb);
			}
			for(i=1;i<=T;i++)
			{
				ret.t[i]=aa.t[i]-bb.t[i];
				if(ret.t[i]<0)
				ret.t[i]+=M,aa.t[i+1]-=1;
			}
		}
		for(i=1;i<=T;i++)
		if(ret.t[i]>=M)
		ret.t[i+1]++,ret.t[i]-=M;
		return ret;
	}
	void print(num aa)
	{
		if(aa.op==-1)
		putchar('-');
		int pd=0;
		int i=T;
		while(aa.t[i]==0&&i>1)
		i--;
		printf("%lld",aa.t[i]);
		i--;
		for(;i>=1;i--)
		{
			long long p=M/10;
			while(p!=1)
			{
				if(aa.t[i]/p==0)
				putchar('0');
				p/=10;
			}
			printf("%lld",aa.t[i]);
		}
		putchar('\n'); 
	}


const int N=2e3+10;
num dp[2][N];
char a[N],b[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%lld%lld%s%s",&n,&m,a+1,b+1);
	for(i=1;i<=m;i++)
	{
		if(b[i]=='T')
		b[i]='A';
		else
		if(b[i]=='A')
		b[i]='T';
		else
		if(b[i]=='G')
		b[i]='C';
		else
		b[i]='G';
	}
	for(i=1;i<=n;i++)
	dp[i%2][0].t[1]=1;
	for(i=1;i<=n;i++)
	for(j=1;j<=i&&j<=m;j++)
	{
		dp[i%2][j]=dp[(i-1)%2][j];
		if(a[i]==b[j])
		dp[i%2][j]=add(dp[(i-1)%2][j-1],dp[i%2][j]);
	}
	print(dp[n%2][m]);
	return 0;
}

