#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m,ans;
const int N=1e6+10;
struct edge{
	int op,val;
	friend bool operator <(const edge &a,const edge &b)
	{
		return a.val<b.val;
	}
}e[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(e[i].val),e[i].op=1;
	for(j=1;j<=m;j++)
	read(e[n+j].val),e[j+n].op=2;
	sort(e+1,e+n+m+1);
	int cntn=0,cntm=0;
	for(i=1;i<=n+m;i++)
	{
		if(e[i].op==1)
		{
			cntn++;
			if(cntn==1)ans+=e[i].val*(m-1);
			else ans+=e[i].val*min((m-cntm),m-1);
		}
		else
		{
			cntm++;
			if(cntm==1)ans+=e[i].val*(n-1);
			else ans+=e[i].val*min((n-cntn),n-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}

