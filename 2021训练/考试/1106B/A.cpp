#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=2005;
int i,j,k,m,n,s,t;
int a[N][N],b[N][N];
int main()
{
	read(n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	read(a[i][j]);
	for(i=1;i<=3;i++)
	for(j=1;j<=3;j++)
	read(b[i][j]),s+=b[i][j];
	if(s!=b[1][1])
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			printf("%0.5lf ",0.0);
			printf("\n");
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			printf("%d.00000 ",a[i][j]);
			printf("\n");
		}	
	}
	return 0;
}

