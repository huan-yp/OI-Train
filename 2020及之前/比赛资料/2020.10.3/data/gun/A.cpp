#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[1000005],v1,v2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		v1+=max(0,a[i]-2);
		if(a[i]&1)v2+=a[i]/2;
		else if(a[i]!=2)v2+=a[i]/2;
	}
	printf("%d %d\n",v1,v2);
	return 0;
}
