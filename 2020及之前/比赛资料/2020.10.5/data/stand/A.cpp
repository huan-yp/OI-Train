#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[100005],b[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int ans=0,now=1;
	for(int i=1;i<=m;i++)
	{
		while(now<=n&&a[now]<b[i])now++;
		if(now<=n)ans++,now++;
	}
	printf("%d\n",ans);
	return 0;
}
