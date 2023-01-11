#include<bits/stdc++.h>
using namespace std;
long long i,j,k,m,n,s,t;
long long zs[1000000];
bool pd[100000000];
int main()
{

	freopen("lxm10.in","w",stdout);
	srand(time(NULL));
	cin>>n;
	cin>>m;
	long long tt;
	tt=m;
	if(m>9e7)
	tt=9e7;
	for(i=2;i<=tt;i++)
	{
		if(pd[i]==0)zs[++k]=i;
		for(j=1;i*zs[j]<=tt&&j<=k;j++)
		{
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)
			break;
		}
	}
	s=1;
	cout<<n<<endl;
	while(s<=n)
	{
		long long ans=1;
		long long x=1+rand()%4;
		if(x%2)
		ans*=2;
		if(x%3==0)
		ans*=3;
		if(s%5)
		for(i=1;i<=x;i++)
		ans*=zs[rand()%(k/100)];
		if(s%5==0)
		{
			long long d=0;
			while(d<=2*sqrt(m))
			{
				long long pp=rand()%k; 
			d=zs[k/3*2+pp%(k/3)];
			}
			ans*=d;
			if(ans<m/50000)
			ans*=49997;
		}
		if(ans<=m&&ans>=m/20)
		{
		s++;
		cout<<ans<<endl;
		}
	}
	return 0;
} 
