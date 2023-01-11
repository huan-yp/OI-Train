#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
template <typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
const int N=5e6+10,mod=998244353;
int i,j,k,m,n,s,t,ans;
int cntl,cntr,nowl,nowr,nowboth,cntboth;
char ch[N];
void Inc(int &x,int y)
{
	x+=y;
	if(x>=mod)x-=mod;
}
void Dec(int &x,int y)
{
	x-=y;
	if(x<0)x+=mod;
}
signed main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i++)
	{
		if(ch[i]=='A')
		{
			nowl++,Inc(cntl,(n-i+1));
			nowl+=nowr+nowboth;Inc(cntl,cntr),Inc(cntl,cntboth);
			Inc(ans,cntr);
			nowr=cntr=nowboth=cntboth=0;
			Dec(cntl,nowl);
		}
		if(ch[i]=='B')
		{
			nowboth++,Inc(cntboth,(n-i+1));
			Dec(cntboth,nowboth),Dec(cntr,nowr),Dec(cntl,nowl);
		}
		if(ch[i]=='C')
		{
			nowr++,Inc(cntr,(n-i+1));
			nowr+=nowl+nowboth;Inc(cntr,cntl),Inc(cntr,cntboth);
			Inc(ans,cntl);
			nowl=cntl=nowboth=cntboth=0;
			Dec(cntr,nowr);
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}

