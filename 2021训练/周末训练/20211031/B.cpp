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
const int N=2e6+10;
int i,j,k,n,s,t,m,head,tail;
int sum[N],c[N],q[N],lst[N];
char ch[N];
int get(int st,int x,int minu,int pos)
{
	int b=sum[st+x-1]-sum[st-1];
	int need=max(minu-(max(n,m)-min(n,m)),0);
	return min(n,m)-(b+(need+1)/2);
}
int check(int st,int x,int minu,int pos)
{
	if(x==1)return 1;
	int b=sum[st+x-1]-sum[st-1];
	int need=max(minu-(max(n,m)-min(n,m)),0);
	int lt = get(st,x-1,c[st-1]-lst[st+x-2],pos);
	return (min(n,m)>b+(need+1)/2||(min(n,m)==b+(need+1)/2&&lt))&&n+m>x;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(m);int ans=1;head=tail=1;
		scanf("%s",ch+1);
		int len=strlen(ch+1);
		for(i=len+1;i<2*len;i++)
		ch[i]=ch[i-len];
		for(i=1;i<2*len;i++)
		{
			sum[i]=sum[i-1]+(ch[i]=='B');
			c[i]=c[i-1]+(ch[i]=='B'?1:-1);
		}	
		int r=1;q[tail++]=1,lst[1]=ch[1]=='B'?1:-1;
		for(int l=1;l<=len;l++)
		{
			if(q[head]==l-1&&head!=tail)head++;
			while(check(l,r-l+1,c[l-1]-(lst[r]=c[q[head]]),q[head])&&r<len*2)
			{
				r++;
				while(c[q[tail-1]]>=c[r]&&head!=tail)tail--;
				q[tail++]=r;
			}
		//	cout<<r-l<<endl;
			ans=max(ans,r-l);
		}
		printf("%d\n",min(ans,len));
	}
	return 0;
}

