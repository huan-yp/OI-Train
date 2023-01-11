#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,n,s,t,m;
const int N=1e6+10;
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
struct fu{
	int op,l,r,x;
}tmp[N*2];
struct node{
	int rk,x;
}b[N*2]; 
int ls[N*73],rs[N*73],T[N],sum[N*73],use[N],use1[N],use2[N];
int tid[N],cnt,cnt2,cnt1,js;
int low(int x)
{
	return x&(-x);
}
void updata(int l,int r,int c,int op)
{
	int k;
	if(l==r)
	{
		for(k=1;k<=cnt;k++)
		sum[use[k]]+=op;
		return;
	}
	int mid=(l+r)/2;
	if(c<=mid)
	{
		for(k=1;k<=cnt;k++)
		{ 
			if(ls[use[k]]==0)
			ls[use[k]]=++js;
			use[k]=ls[use[k]];
		}
		updata(l,mid,c,op);
	}
	else
	{
		for(k=1;k<=cnt;k++)
		{
			if(rs[use[k]]==0)
			rs[use[k]]=++js;
			use[k]=rs[use[k]];
		} 
		updata(mid+1,r,c,op);
	}
}
int quert(int l,int r,int c)
{
	int ret=0;
	if(l==r)
	{
		int k;
		for(k=1;k<=cnt1;k++)
		ret-=sum[use1[k]];
		for(k=1;k<=cnt2;k++)
		ret+=sum[use2[k]];
		return ret;	
	}
	int mid=(l+r)/2;
	int k;
	if(c<=mid)
	{
		for(k=1;k<=cnt1;k++)
		use1[k]=ls[use1[k]];
		for(k=1;k<=cnt2;k++)
		use2[k]=ls[use2[k]];
		return quert(l,mid,c);
	}
	else
	{
		for(k=1;k<=cnt1;k++)
		use1[k]=rs[use1[k]];
		for(k=1;k<=cnt2;k++)
		use2[k]=rs[use2[k]];
		return quert(mid+1,r,c);
	}
}
bool cmp(node aa,node bb)
{
	return aa.x<bb.x;	
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int k;
	scanf("%d%d",&n,&m);
	char op[2];
	for(i=1;i<=n;i++)
	{
		T[i]=++js;
		scanf("%d",&b[i].x);
		b[i].rk=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%s",&op);
		if(op[0]=='Q')
		{
			scanf("%d%d%d",&tmp[i].l,&tmp[i].r,&tmp[i].x);
			b[n+i].rk=n+i;
			b[n+i].x=tmp[i].x;
			tmp[i].op=1;
		}
		else
		{
			scanf("%d%d",&tmp[i].l,&tmp[i].x);
			b[n+i].rk=n+i;
			b[n+i].x=tmp[i].x;
			tmp[i].op=0;
		}		
	}
	sort(b+1,b+m+n+1,cmp);
	for(i=1;i<=n+m;i++)
	{
		if(b[i].x!=b[i-1].x)
		t++;
		if(b[i].rk<=n)
		tid[b[i].rk]=t;
		else
		tmp[b[i].rk-n].x=t;
	} 
	for(i=1;i<=n;i++)
	{
		cnt=0;
		for(k=i;k<=n;k+=low(k))
		use[++cnt]=T[k];
		updata(1,t,tid[i],1);
	}
	for(i=1;i<=m;i++)
	{
		cnt1=cnt2=cnt=0;
		if(tmp[i].op)
		{
			for(k=tmp[i].l-1;k>=1;k-=low(k))
			use1[++cnt1]=T[k];
			for(k=tmp[i].r;k>=1;k-=low(k))
			use2[++cnt2]=T[k];
			printf("%d\n",quert(1,t,tmp[i].x));
		} 
		else
		{
			for(k=tmp[i].l;k<=n;k+=low(k))
			use[++cnt]=T[k];
			updata(1,t,tmp[i].x,1);
			for(k=tmp[i].l;k<=n;k+=low(k))
			use[++cnt]=T[k];
			updata(1,t,tid[tmp[i].l],-1);
			tid[tmp[i].l]=tmp[i].x;
		}	
	}
	return 0;
}

