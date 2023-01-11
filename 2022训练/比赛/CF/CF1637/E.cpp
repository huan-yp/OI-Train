#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
int a[N],b[N],cnt[N],ls[N],vis[N];
set<int> e[N];//¹Ò±ß 
set<int> st[N];//val,pos
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		read(n),read(m);int tot=0;
	
		for(i=1;i<=n;i++)e[i].clear(),st[i].clear();
		for(i=1;i<=n;i++)read(a[i]),b[i]=a[i];
		sort(b+1,b+n+1),s=unique(b+1,b+n+1)-b-1;
		for(i=1;i<=m;i++)
		{
			int x,y;read(x),read(y);
			x=lower_bound(b+1,b+s+1,x)-b;
			y=lower_bound(b+1,b+s+1,y)-b;
			e[x].insert(y),e[y].insert(x);
		}
		for(i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+s+1,a[i])-b,cnt[a[i]]++;
		for(i=1;i<=n;i++)
		if(cnt[a[i]])
		{
			st[cnt[a[i]]].insert(a[i]);
			cnt[a[i]]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(st[i].empty())continue;
			ls[++tot]=i;
		}
		int ans=0;
		for(i=1;i<=tot;i++)
		{
			for(j=1;j<=tot;j++)vis[j]=0;
			while(!st[ls[i]].empty())
			{
				for(j=1;j<=tot;j++)vis[j]=0;
				auto val=*st[ls[i]].rbegin();
				st[ls[i]].erase(val);
				for(j=i;j<=tot;j++)
				{
					auto it=st[ls[j]].rbegin();
					while(it!=st[ls[j]].rend()&&e[val].find(*it)!=e[val].end())
					it++;
					if(it!=st[ls[j]].rend())cmax(ans,(ls[i]+ls[j])*(b[val]+b[*it]));
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

