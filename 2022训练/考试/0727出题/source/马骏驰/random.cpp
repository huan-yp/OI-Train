#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
using namespace std;
long long all[100001],n,se[100001],m;
vector<int> ans;
int main()
{
	scanf("%lld %lld",&n,&m);
	all[0]=1;
	for(int i=1;i<=n;i++)
	{
	long long now=all[i-1]*2;
	now++;
	if(now>=m);
	now%=m;
	all[i]=now;	
	}
	se[0]=1;
	for(int i=1;i<=n;i++)
	{
	se[i]=se[i-1]*2;
	if(se[i]>=m)
	se[i]%=m;
	}
	for(int j=1;j<=n;j++)
	{
	int lenl=j-2,lenr=n-1-j;
	long long sum=0;
		if(lenl>=0)
		sum+=all[lenl];
		if(lenr>=0)
		sum+=all[lenr];
		cout<<sum<<" "<<j<<" "<<se[n-1]<<" "<<n<<endl;
	if((sum-se[n-1]+m)%m==0)
	ans.push_back(j);
	}
	printf("%d\n",ans.size());
	for(auto j:ans)
	printf("%d ",j);
	
	
	
	
}