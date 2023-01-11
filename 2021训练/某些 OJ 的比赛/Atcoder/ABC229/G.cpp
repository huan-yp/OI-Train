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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int p[N];
char ch[N];
int check(int x)
{
	int l=1,r=x-1,pos=1,lcnt=1,lsum=0,rcnt=0,rsum=0,maxn=1ll*INF*INF,minu=maxn;
	for(i=l;i<=r;i++)
	rcnt++,rsum+=p[i];
	
	for(r++;r<=s;r++)
	{
		l++,lcnt--,lsum-=p[r-x],rcnt++,rsum+=p[r];
		maxn=p[pos]*lcnt-lsum+rsum-rcnt*p[pos]-lcnt*(lcnt+1)/2-rcnt*(rcnt-1)/2;
		while(pos<(r+l)/2)
		{
			lcnt++,lsum+=p[pos],rcnt--,rsum-=p[pos],pos++;
			maxn=p[pos]*lcnt-lsum+rsum-rcnt*p[pos]-lcnt*(lcnt+1)/2-rcnt*(rcnt-1)/2;
		}
		cmin(minu,maxn);
	}
	return minu<=k;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1);read(k);
	n=strlen(ch+1);
	for(i=1;i<=n;i++)if(ch[i]=='Y')p[++s]=i;
	int l=2,r=s,ans=1;
	if(s==0)
	{
		puts("0");
		return 0;
	}
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

