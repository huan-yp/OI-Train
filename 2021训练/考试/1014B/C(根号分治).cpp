#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
template<typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
const int N=5e5+10,M=20;
int i,j,k,m,n,s,t;
int a[N+10],d[N+10],sum[N+10],st[N+10][M],b[N+10],lo[N+10];
bool cmp(int x,int y)
{
	if(a[x]!=a[y])return a[x]>a[y];
	return x<y;
}
void init()
{
	for(i=1;i<N;i++)
	{
		for(j=1;j*i<N;j++)
		d[i*j]++;
	}
	for(i=1;i<=sqrt(N+0.5);i++)
	{
		for(j=1;j<=i;j++)
		sum[j]=2*d[j];
		for(j=i+1;j<N;j+=8)
		{
			sum[j]=sum[j-i]+2*d[j];
			sum[j+1]=sum[j-i+1]+2*d[j+1];
			sum[j+2]=sum[j-i+2]+2*d[j+2];
			sum[j+3]=sum[j-i+3]+2*d[j+3];
			sum[j+4]=sum[j-i+4]+2*d[j+4];
			sum[j+5]=sum[j-i+5]+2*d[j+5];
			sum[j+6]=sum[j-i+6]+2*d[j+6];
			sum[j+7]=sum[j-i+7]+2*d[j+7];
		}
		int sq=i*i,sq2=i*(i+1);
		for(j=i*i+1;j<N;j+=8)
		{
			a[j]+=d[j-sq];
			a[j+1]+=d[j-sq+1];
			a[j+2]+=d[j-sq+2];
			a[j+3]+=d[j-sq+3];
			a[j+4]+=d[j-sq+4];
			a[j+5]+=d[j-sq+5];
			a[j+6]+=d[j-sq+6];
			a[j+7]+=d[j-sq+7];
		}
		for(j=i*(i+1)+1;j<N;j+=8)
		{
			a[j]+=sum[j-sq2];
			a[j+1]+=sum[j-sq2+1];
			a[j+2]+=sum[j-sq2+2];
			a[j+3]+=sum[j-sq2+3];
			a[j+4]+=sum[j-sq2+4];
			a[j+5]+=sum[j-sq2+5];
			a[j+6]+=sum[j-sq2+6];
			a[j+7]+=sum[j-sq2+7];
		}
	}
	lo[1]=0,st[1][0]=1;
	for(i=2;i<N;i++)
	st[i][0]=i,lo[i]=lo[i>>1]+1;
	for(i=1;i<=19;i++)
	for(j=1;(1<<i)+j-1<N;j++)
	if(cmp(st[j][i-1],st[j+(1<<i-1)][i-1]))
	st[j][i]=st[j][i-1];
	else
	st[j][i]=st[j+(1<<i-1)][i-1];
}

int ask(int l,int r)
{
	int len=lo[r-l+1];
	int val1=st[l][len],val2=st[r-(1<<len)+1][len];
	if(cmp(val1,val2))return val1;
	return val2;
}
signed main()
{
//	freopen("parallelogram.in","r",stdin);
//	freopen("parallelogram.out","w",stdout);
	init();
	read(t);
	while(t--)
	{
		int x,y;
		read(x),read(y);
		printf("%d %d\n",ask(x,y),a[ask(x,y)]);
	}
	return 0;
}
