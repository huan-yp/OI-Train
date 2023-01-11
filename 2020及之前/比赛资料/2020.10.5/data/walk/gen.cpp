#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include"testlib.h"
using namespace std;
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int v=atoi(argv[1]);
	int x=(int)sqrt(v);
	int n=rnd.next(1,2*x);
	x=v/n;
	int m=rnd.next(max(x/3*2,1),x);
	if(rnd.next(0,1))swap(n,m);
	printf("%d %d\n",n,m);
	bool flag=strcmp(argv[2],"-1");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1)printf("1 ");
			else if(j==1)printf("0 ");
			else if(!flag)printf("0 ");
			else printf("%d ",rnd.next(0,1));
		}
		printf("\n");
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		  printf("%d ",rnd.next(1,99));
		printf("\n");
	}
	return 0;
}
