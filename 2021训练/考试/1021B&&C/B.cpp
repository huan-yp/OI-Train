#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=2e6+10;
int i,j,k,m,n,s,t,ans,js;
int zs[N],pd[N],sum[N],base[N];
void init()
{
	for(i=1;i*i<N;i++)
	sum[i*i]++;
	for(i=1;i<N;i++)
	sum[i]=sum[i-1]+sum[i],base[i]=i;
	for(i=2;i<N;i++)
	{
		for(j=1;j*i*i<N;j++)
		{
			while(base[i*i*j]%(i*i)==0)
			base[i*i*j]/=i*i;
		}
	}
}
signed main()
{
//	freopen("one.in","r",stdin);
//	freopen("one.out","w",stdout);
	read(n),read(m);
	init();
	for(i=1;i<=n;i++)
	ans+=sum[m/base[i]];	
	
	cout<<ans<<endl;
	return 0;
}

