#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=2e5+10;
struct oepration{
	int op,x,p;
}q[N];
int i,j,k,m,n,s,t;
int a[N],maxn[N];
int main()
{
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]);
	read(m);
	for(i=1;i<=m;i++)
	{
		read(q[i].op);
		if(q[i].op==2)
		read(q[i].x);	
		else
		read(q[i].p),read(q[i].x);
	}
	for(i=m;i>=1;i--)
	{
		maxn[i]=maxn[i+1];
		if(q[i].op==2)
		maxn[i]=max(maxn[i+1],q[i].x);
	}
	for(i=1;i<=n;i++)
	cmax(a[i],maxn[1]);
	
	for(i=1;i<=m;i++)
	if(q[i].op==1)
	a[q[i].p]=max(q[i].x,maxn[i]);

	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}

