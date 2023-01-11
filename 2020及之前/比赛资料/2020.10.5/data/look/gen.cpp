#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int a[405];
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int n=rnd.next(maxn/3*2,maxn);
	int now=2;
	if(strcmp(argv[now],"-n")==0)now++,n=maxn;
	printf("%d ",n);
	if(strcmp(argv[now],"-11")==0)
	{
		printf("%d\n",2*n);
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=n+1;i<=2*n;i++)a[i]=1;
		shuffle(a+1,a+2*n+1);
		for(int i=1;i<=2*n;i++)printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	if(strcmp(argv[now],"-12")==0)
	{
		printf("%d\n",2*n);
		int v1=n,v2=n,c=0;
		for(int i=1;i<=2*n;i++)
		{
			if(c==0)printf("0 "),c++,v1--;
			else if(!v1)printf("1 "),c--,v2--;
			else if(!v2)printf("0 "),c++,v1--;
			else
			{
				if(rnd.next(0,1)==0)printf("0 "),c++,v1--;
				else printf("1 "),c--,v2--;
			}
		}
		printf("\n");
		return 0;
	}
	if(strcmp(argv[now],"-2")==0)
	{
		printf("0\n");
		return 0;
	}
	int m=rnd.next(n/3*2,n/3*4);
	printf("%d\n",m);
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=n+1;i<=2*n;i++)a[i]=1;
	shuffle(a+1,a+2*n+1);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
