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
const int N=105;
int i,j,k,n,s,t,m,l;
int x[N],cnt[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(l);
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++)
		{
			read(x[i]);
			for(j=0;j<l;j++)
			if(1<<j&x[i])cnt[j]++;
		}	
		int ans=0;
		for(i=0;i<l;i++)
		if(cnt[i]*2>=n)ans|=1<<i;
		cout<<ans<<endl;
	}
	return 0;
}

