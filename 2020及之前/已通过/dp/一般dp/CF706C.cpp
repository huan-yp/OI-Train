#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
const int N=1e5+10;
string a[N*2];
long long v[N],dp[N][2];
long long miin(long long aa,long long bb)
{
	return aa<bb?aa:bb;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&v[i]);
	char ch[N];
	for(i=1;i<=n;i++)
	{
	 	scanf("%s",ch);
	 	int l=strlen(ch);
		for(j=0;j<l;j++)
		a[i]+=ch[j];
		for(j=l-1;j>=0;j--)
		a[i+n]+=ch[j]; 
		dp[i][1]=dp[i][2]=1e17+10;
	}
	dp[1][1]=v[1];
	dp[1][0]=0;
	for(i=2;i<=n;i++)
	{
		if(a[i+n]>=a[i-1])
		dp[i][1]=miin(dp[i][1],dp[i-1][0]+v[i]);
		if(a[i]>=a[i-1])
		dp[i][0]=miin(dp[i][0],dp[i-1][0]);
		if(a[i+n]>=a[i+n-1])
		dp[i][1]=miin(dp[i][1],dp[i-1][1]+v[i]);
		if(a[i]>=a[i+n-1])
		dp[i][0]=miin(dp[i][0],dp[i-1][1]);
	}
	if(dp[n][0]<1e17||dp[n][1]<1e17)
	cout<<miin(dp[n][0],dp[n][1]);
	else
	cout<<-1; 
	return 0;
}

