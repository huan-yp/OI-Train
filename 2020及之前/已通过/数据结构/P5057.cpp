#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int j,k,m,n,s,t,a[N],c[N];
int low(int x)
{
	return x&(-x);
}
void add(int aa,int cc)
{
	int i;
	for(i=aa;i<=n;i+=low(i))
	c[i]+=cc;
}
int quert(int aa)
{
	int i,ss=0;
	for(i=aa;i>=1;i-=low(i))
	ss+=c[i];
	return ss; 
}
int main()
{
	cin>>n>>m;
	int i;
	for(i=1;i<=m;i++)
	{
		int p,l,r;
		scanf("%d",&p);
		if(p==1)
		{
			scanf("%d%d",&l,&r);
			add(r+1,-1);
			add(l,1);
		}
		if(p==2)
		{
			scanf("%d",&l);
			printf("%d\n",quert(l)%2);
		}
	}
	
	return 0;
}
