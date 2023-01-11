#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while((ch<='9'&&ch>='0'))x=x*10+ch-48,ch=getchar();
	x*=f;
}

void cmin(int &x,int y){x=min(x,y);}
void cmax(int &x,int y){x=max(x,y);}
const int N=1e6+10;
int i,j,k,m,n,s,t,C;
int rk[N],nxt[N],lst[N],a[N],b[N],ans[N],pd[N],lt[N];
int check(int x,int y)
{
	return (x-lt[x]==y-lt[y])||(lt[x]==0&&lt[y]<y-j);
}
int check2(int x,int y)
{
	return (x-lt[x]==y-lst[a[y]])||(lt[x]==0&&lst[a[y]]<y-j);
}
int main()
{
	int tot=3;
	read(tot),read(C);
	while(tot--)
	{
		read(n),read(m);s=0,t=0;
		for(i=1;i<=C;i++)
		lst[i]=0;
		for(i=1;i<=n;i++)
		read(a[i]);
		for(i=1;i<=m;i++)
		read(b[i]);
		nxt[0]=j=-1;
		for(i=1;i<=m;i++)
		{
			lt[i]=lst[b[i]];lst[b[i]]=i;
			while(j!=-1&&check(j+1,i)==0)
			j=nxt[j];
			nxt[i]=++j;
		}
		j=0;
		for(i=1;i<=C;i++)
		lst[i]=0;
		for(i=1;i<=n;i++)
		{
			while(nxt[j]!=-1&&check2(j+1,i)==0)j=nxt[j];
			j++;
			if(j==m)
			{
				ans[++t]=i-m+1;
				j=nxt[j];
			}
			lst[a[i]]=i;
		}
		cout<<t<<endl;
		for(i=1;i<=t;i++)
		printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}


