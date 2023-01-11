#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int n,a[200005];
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int maxv=atoi(argv[2]);
	int n=rnd.next(maxn/3*2,maxn);
	if(strcmp(argv[4],"-n")==0)n=maxn;
	printf("%d\n",n);
	if(strcmp(argv[3],"-1")==0)
	{
		int B=(int)sqrt(maxv);
		for(int i=1;i<=n;i++)
		{
			a[i]=rnd.next(1,B);
			if(rnd.next(0,1))
				a[i]=rnd.next(maxv/(a[i]+1),maxv/max(1,a[i]-1));
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	if(strcmp(argv[3],"-2")==0)
	{
		for(int i=1;i<=n;i++)
			a[i]=rnd.next(1,maxv);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	if(strcmp(argv[3],"-3")==0)
	{
		for(int i=1;i<=n;i++)
			a[i]=rnd.next(1,maxv);
		sort(a+1,a+n+1);
		for(int k=1;k<=n;k++)
		{
			int i=rnd.next(1,n);
			int j=rnd.next(-10,10);
			j+=i;
			j=max(j,1);
			j=min(j,n);
			swap(a[i],a[j]);
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
}
