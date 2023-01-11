#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
int i,j,k,m,n,s,t;
int a[2000005];
int Rand(int l,int r)
{
	return rand()*rand()%(r-l+1)+l;
}
int main()
{
	//freopen("o.in","w",stdout);
	//freopen(".out","w",stdout);
	srand(time(NULL));
	for(i=1;i<=1300;i++)
	{
		int len=1;
		if(Rand(0,2)==0)
		len=Rand(200,300);
		else
		len=Rand(1,20);
		
		a[n+1]=Rand(3e4,5e4);
		for(j=2;j<=len;j++)
		a[n+j]=a[n+j-1]-Rand(10,30);
		n+=len;
	}
	m=200000;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	printf("\n");
	for(i=1;i<=m;i++)
	{
		int l,r,t;
		l=Rand(1,n),r=Rand(1,n);
		if(l>r)swap(l,r);
		if(Rand(0,10)==0)
		t=Rand(n/3,n);
		else
		t=Rand(1,n/3);
		printf("%d %d %d\n",t,l,r);
	}
	return 0;
}

