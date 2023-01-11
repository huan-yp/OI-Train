#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,p[N],c[N],cnt;
int fac[N][50];
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;1ll*i*i<=m;i++)
	{
		int v=0;
		while(m%i==0)m/=i,v++;
		if(v)p[++cnt]=i,c[cnt]=v;
	}
	if(m>1)p[++cnt]=m,c[cnt]=1;
	for(int i=1;i<n;i++)
	{
		int tmp=i;
		for(int j=1;j<=cnt;j++)
		{
			int x=p[j],v=0;
			while(tmp%x==0)tmp/=x,v++;
			fac[i][j]=fac[i-1][j]+v;
		}
	}
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		bool ok=1;
		for(int j=1;j<=cnt;j++)ok&=(fac[n-1][j]-fac[i][j]-fac[n-i-1][j]>=c[j]);
		if(ok)ans.push_back(i+1);
	}
	printf("%d\n",(int)ans.size());
	for(int x:ans)printf("%d ",x);
	return 0;
}

