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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int a[N],b[N];
vector<int> e[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);int ans=-1;
		for(i=1;i<=n;i++)e[i].clear();
		for(i=1;i<=n;i++)read(b[i]),a[i]=b[i];
		sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
		for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		for(i=1;i<=n;i++)e[a[i]].push_back(i);
		for(i=1;i<=m;i++)	
		for(j=1;j<e[i].size();j++)
		cmax(ans,n-e[i][j]+e[i][j-1]);
			
		
		cout<<ans<<endl;
	}

	return 0;
}

