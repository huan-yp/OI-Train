#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,s,t;
const int N=2e5+10;
vector <int> a[N],b[N],c[N];
set <int> sit[N];
int sum[N],cnt[N],val[N],sum2[N],cr[N];
int mod=998244353;
void op()
{
	freopen("data19.in","w",stdout);
}
int main()
{
	srand(time(NULL));
	int d=175;
	int js=0;
	int tmp;
	a[1].reserve(10),a[d].reserve(10); 
	a[1][1]=i;
	for(i=2;i<=d-1;i++)
	{
		tmp=rand()%375+250;
		if(rand()%75==0)
		tmp=cnt[i]=1e4;
		a[i].reserve(tmp+1);
		for(j=1;j<=tmp;j++)
		a[i][j]=++js;
		cnt[i]=tmp;
	}
	n=a[d][1]=++js;
	cnt[1]=cnt[d]=1;
	int now=0;
	for(i=1;i<d;i++)
	{
		tmp=rand()%375+350;
		for(j=1;j<=tmp;j++)
		{
			int u=now+rand()*rand()%cnt[i]+1;
			int v=now+rand()*rand()%(cnt[i]+cnt[i+1])+1;
			sum[u]++;
			b[u].push_back(v);
		}
		now+=cnt[i];
	}
	now=0;
	js=0;
	int pp=0;
	for(i=1;i<d;i++)
	{
		tmp=rand()%5;
		for(j=1;j<=tmp;j++)
		{
			int siz=rand()%5+1;
			if(cnt[i+1]==1e4)
			siz=20000,pp=1;
			++js;
			val[js]=rand()*rand()%mod;
			//
			for(k=1;k<=siz;k++)
			{
				int x=now+rand()*rand()%(cnt[i]+cnt[i+1])+1;
				c[js].push_back(x);
			}
		}
		now+=cnt[i];
	}
	for(i=1;i<=n;i++)
	{
		sum2[i]=sum[i];
		for(j=0;j<sum[i];j++)
		if(b[i][j]==i)
		sum2[i]--,b[i][j]=0;
	}
	m=0;
	for(i=1;i<=n;i++)
	m+=sum2[i];
	for(i=1;i<=js;i++)
	{
		tmp=c[i].size();
		for(j=0;j<tmp;j++)
		sit[i].insert(c[i][j]);
	}
	printf("%d %d %d %d\n",n,m,js,pp);
	op();
	printf("%d %d %d\n",n,m,js);
	for(i=1;i<=n;i++)
	for(j=0;j<sum[i];j++)
	if(b[i][j]!=0)
	printf("%d %d %d\n",i,b[i][j],rand()*rand()%mod);
	set <int> ::iterator it;
	for(i=1;i<=js;i++)
	{
		printf("%d %d ",sit[i].size(),0);
		for(it=sit[i].begin();it!=sit[i].end();it++)
		printf("%d ",*it);
		printf("\n");
	}
	return 0;
}
