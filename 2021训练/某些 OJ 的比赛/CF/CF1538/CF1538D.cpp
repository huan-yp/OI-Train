#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=1e5+10;
int i,j,k,n,s,t,m;
int pd[N],zs[N];
void init()
{
	for(i=2;i<N;i++)
	{
		if(!pd[i])zs[++m]=i;
		for(j=1;j<=m&&zs[j]*i<N;j++)
		{
			pd[i*zs[j]]=1;
			if(i%zs[j]==0)break;
		}
	}
}
int fj(int x)
{
	int ret=0;
	int tmp=sqrt(x+1);
	for(i=1;zs[i]<=tmp;i++)
	{
		while(x%zs[i]==0)
		x/=zs[i],ret++;
		if(x==1)break;
	}
	if(x!=1)
	ret++;
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	read(t);
	while(t--)
	{
		int ans=0;
		int a,b;
		read(a),read(b),read(k);
		if(a<b)swap(a,b);
		if(k==1)
		{
			if(a%b==0&&a!=b)
			printf("YES\n");
			else
			printf("NO\n");
			continue;
		}
		ans+=fj(a),ans+=fj(b);	
		if(ans>=k)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}


