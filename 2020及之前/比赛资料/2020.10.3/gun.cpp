#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
int main()
{
	cin>>n>>m;
	int mi=0,ma=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&t);	
		ma+=(t==1?0:t-2);
		mi+=(t-1)/2;
		if(t%2==0&&t!=2)
		mi++;
	}
	printf("%d %d",ma,mi);
	return 0;
}
