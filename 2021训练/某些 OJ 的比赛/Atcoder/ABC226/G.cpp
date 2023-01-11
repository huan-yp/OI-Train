#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
int i,j,k,n,s,t,m;
int a[55],b[55];
int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		for(i=1;i<=5;i++)read(a[i]);
		for(i=1;i<=5;i++)read(b[i]);
		int flag=0;
		if(a[5]>b[5])flag=1;b[5]-=a[5];
		if(a[4]>b[5]+b[4])flag=1;
		int tmp=min(a[4],b[4]);a[4]-=tmp,b[4]-=tmp;
		tmp=min(a[4],b[5]);a[4]-=tmp,b[5]-=tmp,a[1]-=tmp;
		if(a[3]>b[5]+b[4]+b[3])flag=1;
		tmp=min(a[3],b[3]);a[3]-=tmp,b[3]-=tmp;
		tmp=min(a[3],b[5],a[2]);a[3]-=tmp,b[5]-=tmp,a[2]-=tmp;
		tmp=min(a[3],b[4]);a[3]-=tmp,b[4]-=tmp,a[1]-=tmp;
		tmp=min(a[3],b[5]);a[3]-=tmp,b[5]-=tmp,a[1]-=tmp*2;
		if(a[2]>b[5]*2+b[4]*2+b[3]+b[2])flag=1;
		tmp=min(a[2],b[2]);b[2]-=tmp,a[2]-=tmp;
		tmp=min(a[2],b[3]);b[3]-=tmp,a[2]-=tmp;a[1]-=tmp;
		if(a[2]>b[4]*2)
		{
			a[2]-=b[4]*2;
			b[4]=0;
		}
		else
		{
			if(a[2]%2)
			{
				b[4]-=a[2]/2+1;
				a[1]-=2;
			}
			else
			b[4]-=a[2]/2;
			
			a[2]=0;
		}
		int need=a[2]/2+a[2]%2;
		b[5]-=need,a[1]-=need*5-a[2]*2,a[2]=0;
		if(a[1]>b[5]*5+b[4]*4+b[3]*3+b[2]*2+b[1])flag=1;
		if(flag)
		puts("No");
		else
		puts("Yes");
	}
	return 0;
}

