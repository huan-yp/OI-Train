#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m;
int a[N],p[N];
struct Ans{
	int a,b,c;
	void print()
	{
		if(a!=-1)
		printf("%d %d %d\n",a,b,c);
		else
		printf("-1\n");
	}
	friend bool operator <(Ans a,Ans b)
	{
		if(a.a==-1)return 0;
		if(b.a==-1)return 1;
		if(a.a!=b.a)return a.a<b.a;
		if(a.b!=b.b)return a.b<b.b;
		return a.c<b.c;
	}
}ans,Z;
void cmin(Ans &a,Ans b)
{
	a=a<b?a:b;
}
Ans check(int x,int end=n)
//
{
	Ans l1,l2;
	l1.a=a[1],l1.b=x,l1.c=1;
	l2=Z;
	for(int i=1;i<=n;i+=4)
	p[i]=p[i+1]=p[i+2]=p[i+3]=0;
	
	for(int i=2;i<=end;i++)
	{
		if(a[i]!=l1.a+l1.c*l1.b)
		continue;
		p[i]=1,l1.c++;
	}
	if(l1.c!=(a[end]-a[1])/x+1)
	return Z;
	for(int i=2;i<=n;i++)
	{
		if(p[i])continue;
		if(l2.c>1)
		{
			if(a[i]!=l2.a+l2.c*l2.b)
			return Z;
			l2.c++;
		}
		if(l2.c==1)
		l2.b=a[i]-l2.a,l2.c++;
		if(l2.a==-1)
		l2.a=a[i],l2.c=1;
	}
	return min(l1,l2);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	Z.a=-1;
	read(t);
	while(t--)
	{
		int first=-1;ans.a=-1;
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]);
		
		Ans l1,l2;
		l1.a=a[1],l1.b=a[2]-a[1],l1.c=2;
		for(i=3;i<=n;i++)
		{
			if(a[i]==a[1]+l1.b*l1.c)
			l1.c++;
		}
		if(l1.c==n)
		{
			printf("%d %d %d\n",a[1],a[2]-a[1],2);
			continue;
		}
		memset(p,0,sizeof(p));
		l1.b=a[n]-a[n-1],l1.c=2;
		for(i=n-2;i>=2;i--)
		{
			if(a[i]+l1.c*l1.b==a[n])
			{
				p[i]=1,l1.c++;
				continue;
			}
			if(p[i]==0&&first==-1)
			first=i;
		}
		if(first!=-1)
		{
			for(i=1;i<=sqrt(a[first]-a[1]);i++)
			{
				if((a[first]-a[1])%i)continue;
				cmin(ans,check(i,first));
				cmin(ans,check((a[first]-a[1])/i,first));
			}
		}
		//
		for(i=1;i<=sqrt(a[n]-a[1]);i++)
		{
			if((a[n]-a[1])%i)continue;
			cmin(ans,check(i));
			cmin(ans,check((a[n]-a[1])/i));
		}
		for(i=1;i<=sqrt(a[n-1]-a[1]);i++)
		{
			if((a[n-1]-a[1])%i)continue;
			cmin(ans,check(i,n-1));
			cmin(ans,check((a[n-1]-a[1])/i,n-1));
		}
		ans.print();
	}
	return 0;
}

