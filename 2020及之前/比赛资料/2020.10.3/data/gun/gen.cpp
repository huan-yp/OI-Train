#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int a[1000005];
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int n=rnd.next(maxn/3*2,maxn);
	if(strcmp(argv[3],"-1")==0)n=n/2*2+1;
	if(strcmp(argv[3],"-n")==0)n=maxn;
	int maxm=atoi(argv[2]);
	int m=rnd.next(1,maxm);
	m=min(m,n);
	printf("%d %d\n",n,m);
	n-=m;
	int x=min(n/2,m);
	n-=x;
	for(int i=1;i<=m;i++)
	{
		a[i]=rnd.next(0,n);
		n-=a[i];
	}
	a[1]+=n;
	for(int i=1;i<=x;i++)
		a[rnd.next(1,m)]++;
	for(int i=1;i<=m;i++)printf("%d ",a[i]+1);
	printf("\n");
	return 0;
}
