#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=105,M=100*7000+1;
int i,j,k,m,n,s,t;
int a[N];
bitset<M>dp[N];
bitset<M*2>gap[N];
int main()
{
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),s+=a[i];
	sort(a+1,a+n+1);
	dp[1][0]=1;
	for(i=1;i<=n;i++)
	dp[i+1]=(dp[i]<<a[i])|dp[i];
	
	for(i=1;i<=n;i++)
	{
		for(j=1+i;j<=n;j++)
		dp[i]=(dp[i]<<a[j])|dp[i];
		
		for(j=0;j<M;j++)
		gap[i][j]=dp[i][j];
		for(j=1;j<=n;j++)
		{
			if(j==i)continue;
			gap[i]=(gap[i]<<a[j])|gap[i];
		}
		gap[i]>>=(s-a[i]);
	}
	int p=0,q=0,maxn=0;
	for(i=1;i<=n;i++)
	{
		if(dp[i].count()*2+1>maxn)
		{
			maxn=dp[i].count()*2+1;p=a[i];
			for(j=M*2-1;j>=0;j--)
			if(gap[i][j]==0)q=j;
		}
		if(dp[i].count()*2+1==maxn)
		{
			if(a[i]<p)
			{
				p=a[i];
				for(j=M*2-1;j>=0;j--)
				if(gap[i][j]==0)q=j;
			}
			if(a[i]==p)
			{
				for(j=M*2-1;j>=0;j--)
				if(gap[i][j]==0&&j<q)q=j;
			}
		}
	}
	cout<<p<<' '<<q<<endl;
	return 0;
}

