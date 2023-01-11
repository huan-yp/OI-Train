#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m,c;
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
const int M=1e8+10;
bitset <M> bst;
const int N=1e6+10;
int vis[65],p[N],q[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(i=1;i<=n;i++)
	{
		unsigned long long x;
		scanf("%llu",&x);
		int cnt=0;
		while(x)
		{
			if(x&1)
			vis[cnt]=1;
			cnt++;
			x>>=1;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p[i],&q[i]);
		if(vis[p[i]])
		bst[q[i]]=1;
	}
	int sum=0;
	for(i=0;i<k;i++)
	{
		int pd=1;
		for(j=1;j<=m;j++)
		if(p[j]==i&&bst[q[j]]==0)
		pd=0;
		sum+=pd;
	}
	unsigned long long ans=1;
	unsigned long long tmp=1;
	if(sum!=64)
	{
		ans=ans<<sum;
		ans-=n;
	}
	else
	{
		if(n==0)
		printf("184467440737095516116");
		else
		{
			ans=ans<<sum-1;
			ans-=n;
			tmp=tmp<<sum-1;
			ans+=tmp;
		}
	}
	printf("%llu",ans);
	return 0;
}

