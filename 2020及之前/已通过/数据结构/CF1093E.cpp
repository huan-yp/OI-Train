#include<bits/stdc++.h>
using namespace std;
int j,k,n,s,t,m;
const int L=1000,N=2e5+10;
int a[N],b[N],rak[L*L+10],tid[L*L+10],c[300][N],rk[N]; 
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
inline int quert(int id,int x,int y)
{
	int i;
	if(x<y)
	swap(x,y);
	int ret=0;
	for(i=x;i>=1;i-=(i&(-i)))
	ret+=c[id][i];
	for(i=y;i>=1;i-=(i&(-i)))
	ret-=c[id][i]; 
	return ret;
}
inline void add(int id1,int id2,int x)
{
	int i;
	for(i=x;i<=n;i+=(i&(-i)))
	c[id1][i]--,c[id2][i]++;
}
inline void work(int id,int x)
{
	int i;
	for(i=x;i<=n;i+=(i&(-i)))
	c[id][i]++;
}
inline int query(int l,int r,int x,int y)
{
	int i;
	int ret=0;
	int tmp=min(r,rk[l]*L);
	for(i=l;i<=tmp;i++)
	ret+=(tid[i]<=y&&tid[i]>=x);
	for(i=rk[l]+1;i<=rk[r]-1;i++)
	ret+=quert(i,x,y);
	if(rk[l]==rk[r])
	return ret;
	for(i=rk[r]*L-L+1;i<=r;i++)
	ret+=(tid[i]<=y&&tid[i]>=x);
	return ret;
}
inline void updata(int x,int y)
{
	add(rk[x],rk[y],tid[y]);
	add(rk[y],rk[x],tid[x]);
	swap(tid[x],tid[y]);
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	t=read(),rak[t]=i;
	for(i=1;i<=n;i++)
	a[i]=read();
	for(i=1;i<=n;i++)
	tid[i]=rak[a[i]];
	int op,la,lb,ra,rb,l,r;
	for(i=1;i<=n/L;i++)
	for(j=1;j<=L;j++)
	rk[i*L-L+j]=i;
	for(i=n/L*L+1;i<=n;i++)
	rk[i]=n/L+1;
	for(i=1;i<=n;i++)
	work(rk[i],tid[i]);
	for(i=1;i<=m;i++)
	{
		op=read();
		if(op==2)
		{
			l=read();
			r=read();
			updata(l,r);
		}
		if(op==1)
		{
			lb=read(),rb=read();
			la=read(),ra=read();
			printf("%d\n",query(la,ra,lb,rb));
		}
	}
	return 0;
}

