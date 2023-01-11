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
const int N=2e5+10;
int i,j,k,n,s,t,m,flag=0,head,tail;
int a[N],q[N*2];
void solve(int l,int r,int lst)
{
	if(l>r)
	{
		flag=1;
		return ;
	}
	if((lst==l-1&&q[tail]>a[l])||(lst==r+1&&q[head]>a[l]))
	{
		q[--head]=a[l];
		solve(l+1,r,l);
	}
	if(flag)return ;
	if((lst==l-1&&a[r]<q[tail])||(lst==r+1&&a[r]<q[head]))
	{
		q[++tail]=a[r];
		solve(l,r-1,r);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);flag=0;
		for(i=1;i<=n;i++)read(a[i]);
		q[head=tail=N]=a[1],solve(2,n,1);
		if(flag)
		{
			for(i=head;i<=tail;i++)
			printf("%d ",q[i]);
			cout<<endl;
			continue;
		}
		q[head=tail=N]=a[n],solve(1,n-1,n);
		if(flag)
		{
			for(i=head;i<=tail;i++)
			printf("%d ",q[i]);
			cout<<endl;
		}
		else
		puts("-1");
	}
	return 0;
}

