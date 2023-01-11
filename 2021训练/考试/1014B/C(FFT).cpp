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
struct complx{
	double x,y;
	complx(double xx=0,double yy=0){x=xx;y=yy;}
	friend complx operator +(const complx &a,const complx &b){return complx(a.x+b.x,a.y+b.y);}
	friend complx operator -(const complx &a,const complx &b){return complx(a.x-b.x,a.y-b.y);}
	friend complx operator *(const complx &a,const complx &b){return complx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
};
const int N=(1<<20)+10,M=20;
const double Pi=acos(-1.0);
int i,j,k,m,n,s,t;
int a[N],d[N],sum[N],st[N][M],b[N],lo[N],rk[N];
complx tmp[N];
bool cmp(int x,int y)
{
	if(a[x]!=a[y])return a[x]>a[y];
	return x<y;
}
void fast_fast_tle(complx *A,int type)
{
	complx B[N];
	for(i=0;i<1<<M;i++)
	B[i]=A[rk[i]];
	for(i=0;i<1<<M;i++)
	A[i]=B[i];
	for(int len=1;len<1<<M;len<<=1)
	{
		complx wn=complx(cos(Pi/len),sin(Pi/len)*type);
		for(i=0;i<1<<M;i+=len*2)
		{
			complx w=complx(1,0);
			for(k=0;k<len;k++,w=w*wn)	
			{
				complx x=A[i+k],y=A[i+k+len]*w;
				A[i+k]=x+y,A[i+k+len]=x-y;
			}
		}	
	}
}
void init()
{
	for(i=1;i<(int)(5e5+10);i++)
	{
		for(j=1;j*i<(int)(5e5+10);j++)
		d[i*j]++;
	}
	for(i=0;i<1<<M;i++)
	tmp[i].x=d[i],rk[i]=(rk[i>>1]>>1)|((i&1)<<(M-1));
	fast_fast_tle(tmp,1);
	for(i=0;i<1<<M;i++)
	tmp[i]=tmp[i]*tmp[i];
	fast_fast_tle(tmp,-1);
	for(i=1;i<(int)(5e5+10);i++)
	a[i]=int(tmp[i].x/(1<<M)+0.5);

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
