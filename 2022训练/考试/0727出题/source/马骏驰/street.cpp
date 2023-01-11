#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-6;
int dplos[100001],n;
long double dp[100001];
bool dian[100001];
vector<int> edge[100001];
void dfs1(int x,int fa)
{
for(auto j:edge[x])
{
if(j==fa)
continue;
dfs1(j,x);
dplos[x]+=2;
if(dian[j]!=1)
dplos[x]+=dplos[j];

}	
//cout<<dplos[x]<<endl;		
}
void dfs2(int x,int fa)
{
long double sum=0;
long double sum1=0,sum2=0;
	for(auto j:edge[x])
	{
	if(j==fa)
	continue;
	dfs2(j,x);
	sum1+=dp[j]+1.0;	
//	cout<<dp[j]<<" "<<x<<endl;
	sum++;	
	}
if(sum==0)
return ;

sum2=dplos[x]*(sum-1)/(2*sum);

dp[x]=sum2+sum1*1.0/sum;
//cout<<x<<" "<<sum1<<" "<<dplos[x]<<" "<<sum-1<<" "<<2*sum<<" "<<sum2<<" "<<dp[x]<<endl;
}
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
scanf("%d",&n);
for(int i=2;i<=n;i++)
{
int fa;
char x;
scanf("%d",&fa);	
cin>>x;
if(x=='Y')
dian[i]=1;
else
dian[i]=0;
edge[fa].push_back(i);
edge[i].push_back(fa);
}	
dfs1(1,0);
dfs2(1,0);
printf("%0.6Lf",dp[1]);

}