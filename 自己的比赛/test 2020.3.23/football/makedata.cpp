#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
const int maxn=1e6,maxk=1<<30,maxt=1<<15;
int k,n;
int Rand(int l,int r)
{
	return rand()*rand()%(r-l+1)+l;
}
int main()
{
//	freopen(".in","r",stdin);
	freopen("15.in","w",stdout);
	srand(time(NULL));
	k=Rand(5e8,1e9);
	n=Rand(9e5,1e6);
	printf("%d %d\n",k,n);
	for(int i=1;i<=n;i++)
	{
		double level=Rand(1,sqrt(i)+10)/100.0;
		printf("%d %d\n",(int)pow(4.5,level)*Rand(5,10),(int)pow(5.0,level)*Rand(5,10));
	}
	return 0;
}

