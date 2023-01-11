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

int i,j,k,n,s,t,m;
int calc(int x,int y)
{
	int cntx=0,gx[40],cnty=0,gy[40],ret=0;
	memset(gx,0,sizeof(gx));
	memset(gy,0,sizeof(gy));
	
	while(x)
	{
		gx[++cntx]=x%k;
		x/=k;
	}
	while(y)
	{
		gy[++cnty]=y%k;
		y/=k;
	}
	for(int i=max(cntx,cnty);i>=1;i--)
	ret=ret*k+(gx[i]+gy[i])%k;
	
	return ret;
}
int inv(int x)
{
	int cnt=0,g[40],ret=0;
	memset(g,0,sizeof(g));
	
	while(x)
	{
		g[++cnt]=x%k;
		x/=k;
	}
	for(int i=cnt;i>=1;i--)
	ret=ret*k+(k-g[i])%k;
	
	return ret;
}
struct tagop{
	int res,val;
}tag;
set<int> st;
int calc(int x,tagop tag)
{
	if(tag.res=1)
	x=inv(x);
	x=calc(x,tag.val);
}

signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//x^z=y;
	//x^z^y'=0;
	//x^y'=z;
	//x'
	//x^y'=z';
	int now;
	cin>>k>>now;
	cout<<now<<endl;
	while(1)
	{
		int x,y;
		cin>>x;
		if(x==now)
		{
			cout<<1<<endl;
			break;
		}
		now=inv(calc(now,inv(x)));
		cout<<0<<' '<<now<<endl;
		
	}
	return 0;
}

