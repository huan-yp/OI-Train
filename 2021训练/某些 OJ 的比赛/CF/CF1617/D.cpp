#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e5+10;
int i,j,k,n,s,t,m;
int pd[N],col[N];
int ask(int a,int b,int c)
{
	printf("? %d %d %d\n",a,b,c);fflush(stdout);
	int x;read(x);
	return x;
}
void answer()
{
	int cnt=0;
	for(i=1;i<=n;i++)if(pd[i]==0)cnt++;
	printf("! %d ",cnt);
	for(i=1;i<=n;i++)if(pd[i]==0)printf("%d ",i);
	printf("\n");
	fflush(stdout);
}
void check(int p[])
{
	for(i=1;i<=n;i+=3)
	{
		if(pd[i]!=-1&&pd[i+1]!=-1&&pd[i+2]!=-1)continue;
		if(col[i/3+1]==0)
		{
			int a1=ask(p[1],i,i+1),a2=ask(p[1],i,i+2);
			if(a1==1&&a2==1)pd[i]=1,pd[i+1]=pd[i+2]=0;
			if(a1==0&&a2==0)pd[i]=pd[i+1]=pd[i+2]=0;
			if(a1==1&&a2==0)pd[i+1]=1,pd[i]=pd[i+2]=0;
			if(a2==1&&a1==0)pd[i+2]=1,pd[i]=pd[i+1]=0;
		}
		else
		{
			int a1=ask(p[0],i,i+1),a2=ask(p[0],i,i+2);
			if(a1==0&&a2==0)pd[i]=0,pd[i+1]=pd[i+2]=1;
			if(a1==1&&a2==1)pd[i]=pd[i+1]=pd[i+2]=1;
			if(a1==0&&a2==1)pd[i+1]=0,pd[i]=pd[i+2]=1;
			if(a2==0&&a1==1)pd[i+2]=0,pd[i]=pd[i+1]=1;
		}
	
	}
}
void solve(int y)
{
	int p[10]={0,0,0};
	for(i=1;i<=2;i++)
	for(j=i+1;j<=3;j++)
	for(k=1;k<=2;k++)
	{
		if(ask(i,j,y*3-3+k)!=col[1])
		{
			if(i==1&&j==2)pd[3]=col[1],p[col[1]]=3;
			if(i==1&&j==3)pd[2]=col[1],p[col[1]]=2;
			if(i==2&&j==3)pd[1]=col[1],p[col[1]]=1;
			pd[y*3-3+k]=col[y],p[col[y]]=y*3-3+k;
			check(p);return ;
		}
	}
	pd[1]=pd[2]=pd[3]=col[1];p[col[1]]=1;
	for(i=1;i<=2;i++)
	for(j=i+1;j<=3;j++)
	{
		if(ask(1,y*3-3+i,y*3-3+j)!=col[y])
		{
			if(i==1&&j==2)pd[y*3]=col[y],p[col[y]]=y*3;
			if(i==1&&j==3)pd[y*3-1]=col[y],p[col[y]]=y*3-1;
			if(i==2&&j==3)pd[y*3-2]=col[y],p[col[y]]=y*3-2;
			check(p);return ;
		}
	}
	pd[y*3-1]=pd[y*3-2]=pd[y*3]=col[y],p[col[y]]=y*3;
	check(p);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)pd[i]=-1;
		for(i=1;i<=n;i+=3)
		col[i/3+1]=ask(i,i+1,i+2);
		for(i=4;i<=n;i+=3)
		{
			if(col[1]!=col[i/3+1])
			{
				solve(i/3+1);
				break;
			}
		}
		answer();
	}
	return 0;
}

