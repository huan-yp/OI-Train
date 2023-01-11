#include<iostream>
#include<cstdio>
#include<algorithm>
#define Re register
#define In inline
using namespace std;
const int maxn=5e6+5;
//const long long Max=(1ll<<62)-1+(1ll<<62);
int n,m,l=1,r=0;
long long p,ans,sum;
struct que
{
	int id;
	long long num;
}qu[maxn];
struct monster
{
	long long t,b;
}s[maxn];
int mp[1001][1001];
In void humqueue()
{
	for(Re int i=1;i<=n;i++)
	{
		while(r>=l&&qu[r].num<=s[i].t)
			r--;
		qu[++r].id=i;
		qu[r].num=s[i].t;
		if(i<=m-1)
			continue;
		s[i-m+1].t=qu[l].num;
		while(r>=l&&qu[l].id<=i-m+1)
			l++;
	}
	long long mx=0;
	for(Re int i=n;i>=n-m+1;i--)
	{
		mx=max(mx,s[i].t);
		s[i].t=mx;
	}
}
const int N=1e6+10;
struct fu{
	int rak1,rak2;
	double num;
	int val;
	fu()
	{
		val=0;
	}
}at[N];
bool cmp(fu aa,fu bb)
{
	return aa.num<bb.num;
}
int main()
{
//	freopen("data7.in","r",stdin);
//	freopen("data7.txt","w",stdout);
	scanf("%d%lld%d",&n,&p,&m);
	for(Re int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i].t);
		}
	for(Re int i=1;i<=n;i++)
	scanf("%lld",&s[i].b);
	humqueue();
	for(Re int i=1;i<=n;i++)
	{
		s[i].t=(s[i].t-1)/p+1;
	}
	int js=0,i,j;
	for( i=1;i<=1e3/p+1;i++)
	for( j=1;j<=1e3;j++)
	{
		at[++js].rak1=i;
		at[js].rak2=j;
		at[js].num=double(i)/j;
	}
	sort(at+1,at+int(1e3*(1e3/p+1)),cmp);
	for( i=1;i<=1e3*(1e3/p+1);i++)
	{
		mp[at[i].rak1][at[i].rak2]=i;
	}
	for( i=1;i<=n;i++)
	{
		at[mp[s[i].t][s[i].b]].val++;
	}
		js=0;
	for( i=1;i<=1e3*(1e3/p+1);i++)
	{
		while(at[i].val)
		{
			s[++js].t=at[i].rak1;
			s[js].b=at[i].rak2;
			at[i].val--;
		}
	}
//		for(int i=1;i<=n;i++)
//	{
//		printf("%0.6lf ",double(s[i].t)/s[i].b);
//		if(i%10==0)
//		cout<<endl;
//	}
	for(Re int i=1;i<=n;i++)
	{
		sum+=s[i].t;
//		if((double)(Max-ans)/(double)sum<=(double)s[i].b)
//		{
//			printf("Boom!!!");
//			return 0;
//		}
		ans+=sum*s[i].b;
	}//×îÓÅ½â 
	printf("%lld",ans);
	return 0;
}
