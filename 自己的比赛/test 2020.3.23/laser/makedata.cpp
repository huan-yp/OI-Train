#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=300,maxt=1e4,maxd=1e5; 
int n,cnt=0;
int main()
{
//	freopen(".in","r",stdin);
	freopen("20.in","w",stdout);
	srand(time(NULL));
	n=maxn-rand()%10;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
//		cnt+=rand()%((maxt-cnt)/(2*(n-i+1)))+1;
//		printf("%d ",cnt);
//		cnt+=rand()%((maxt-cnt)/(2*(n-i+1)-1))+1;
//		printf("%d %d\n",cnt,rand()*rand()%maxd);
		int a=rand()%maxt;
		int b=a+rand()%(maxt-a);
		printf("%d %d %d\n",a,b,rand()*rand()%maxd);
	}
	return 0;
}
