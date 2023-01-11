#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
#define ll long long
using namespace std;
int a[1000005];
ll in(char*s)
{
	int i=0;
	ll t=0;
	while(s[i]>='0'&&s[i]<='9')
	{
		t=t*10+s[i]-'0';
		i++;
	}
	return t;
}
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	ll maxn=in(argv[1]);
	int c=atoi(argv[2]);
	int t=rnd.next(70,100);
	printf("%d %d\n",c,t);
	if(c==9)
	{
		printf("%d",rnd.next(1,9));
		for(int i=1;i<9;i++)printf("%d",rnd.next(0,9));
		printf("\n");
	}
	else
	{
		printf("%d",rnd.next(1,9));
		for(int i=1;i<50;i++)printf("%d",rnd.next(0,9));
		printf(".");
		for(int i=1;i<=50;i++)printf("%d",rnd.next(0,9));
		printf("\n");
	}
	while(t--)printf("%lld\n",rnd.next(maxn/3*2,maxn));
	return 0;
}
