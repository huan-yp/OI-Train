#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define vi vector<int>
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
const int N=2e3+10;
int i,j,k,n,s,t,m;
set<vi> st;
vector<vi> a;
int cnt[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T=1;read(T);
	while(T--)
	{
		read(n);memset(cnt,0,sizeof(cnt));a.clear();
		vi tmp;tmp.clear(),tmp.push_back(0);
		for(i=1;i<=n;i++)
		{
			int x;read(x);
			tmp.push_back(x);
			cnt[x]++;
		}
		a.push_back(tmp);
		for(i=1;i<=n;i++)
		{	
			tmp.clear();tmp.push_back(0);
			for(j=1;j<=n;j++)
			tmp.push_back(cnt[a[i-1][j]]);

			memset(cnt,0,sizeof(cnt));
			for(j=1;j<=n;j++)
			cnt[tmp[j]]++;
			int flag=1;
			a.push_back(tmp);
			for(j=1;j<=n;j++)
			if(cnt[tmp[j]]!=tmp[j])flag=0;
			if(flag)break;
		}
		read(m);
		for(i=1;i<=m;i++)
		{
			int x;
			read(x),read(k);
			if(k>=a.size())
			printf("%d\n",a[a.size()-1][x]);
			else
			printf("%d\n",a[k][x]);
		}
	}
	return 0;
}

