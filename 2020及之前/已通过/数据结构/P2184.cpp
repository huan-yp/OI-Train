#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int j,k,m,n,s,t,c1[N],c2[N];
int low(int x)
{
	return x&(-x);
} 
void add1(int aa)
{
	int i;
	for(i=aa;i<=n;i+=low(i))
	c1[i]++;
}
void add2(int aa)
{
	int i;
	for(i=aa;i<=n;i+=low(i))
	c2[i]++;
}
int quert1(int aa)
{
	int i;
	int ss=0;
	for(i=aa;i>=1;i-=low(i))
	ss+=c1[i];
	return ss;
}
int quert2(int aa)
{
	int i;
	int ss=0;
	for(i=aa;i>=1;i-=low(i))
	ss+=c2[i];
	return ss;
}
int main()
{
	int i;
	cin>>n>>m;
	int op,l,r;
	for(i=1;i<=m;i++)	
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
		add1(l);
		add2(r);
		}
		if(op==2)
		printf("%d\n",quert1(r)-quert2(l-1));
	}
	return 0;
 } 
