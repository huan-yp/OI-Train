#include<iostream>
#include<cstdio>
using namespace std;
const int getmax=1e7+5,maxn=3e4+5;
const long long mod=1e9+7;
long long n,pri[getmax>>3][2],cnt,bg[maxn],ct,a[maxn],ans=1;bool flag[getmax];
void getprim(int k)
{
	flag[1]=1;
	for(int i=2;i<=k;i++)
	{
		if(flag[i]==0)
			pri[++cnt][0]=i;
		for(int j=1;j<=cnt&&pri[j][0]<=k/i;j++)
		{
			flag[i*pri[j][0]]=1;
			if(i%pri[j][0]==0)
				break;
		}
	}
}
void cutprim(long long k)
{
	for(int i=1;i<=cnt;i++)
		{
			long long con=0;
			while(k%pri[i][0]==0)
			{
				k/=pri[i][0];
				con++;
			}
			pri[i][1]=pri[i][1]>con?pri[i][1]:con;
			if(k==1)
				break;
		}
	bool p=0;
	if(k!=1)
		for(int i=1;i<=ct;i++)
			if(bg[i]==k)
				p=1;
	if(!p)
		bg[++ct]=k%mod;
}
int main()
{
	freopen("9.in","r",stdin);
	freopen("10wa.ans","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	getprim(1e7);
	for(int i=1;i<=n;i++)
			cutprim(a[i]);
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=pri[i][1];j++)
			ans=ans*pri[i][0]%mod;
	for(int i=1;i<=ct;i++)
		ans=ans*bg[i]%mod;
	printf("%lld",ans);
	return 0;
}

