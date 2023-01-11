#include<bits/stdc++.h>
using namespace std;
long long i,j,k,m,n,s,t,zs[4100000],pd[11000000],mod=1e9+7;
long long a[110000],ys[410000][3];
int main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout); 
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(i=2;i<=1e7;i++)
	{
		if(!pd[i])
		zs[++k]=i;
		for(j=1;j<=k&&zs[j]*i<=1e7;j++)
		{
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)
			break; 
		} 
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			long long cnt=0;
			while(a[i]%zs[j]==0)
				{
				cnt++;	
				a[i]/=zs[j];
				}
			if(cnt>=1)
			{
				t=1;
				for(t=1;t<=s;t++)
				if(ys[t][1]==zs[j])
				{
					ys[t][2]=max(ys[t][2],cnt);
					break;
				}
				if(t==s+1)
				{
					s++;
					ys[s][1]=zs[j];
					ys[s][2]=cnt;
				}
			}
		} 
		if(a[i]>1)
		{  
		for(j=1;j<=s;j++)
		if(ys[j][1]==a[i])
		break;
		if(j==s+1)
		{
			s++;
			ys[s][1]=a[i];
			ys[s][2]=1;
		}
		}
		 
	}
		long long ans=1;
		for(i=1;i<=s;i++)
		for(j=1;j<=ys[i][2];j++)
		ans=ans*(ys[i][1]%mod)%mod;
		cout<<ans;
	return 0;
}
