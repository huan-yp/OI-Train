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
5
4 3 2 1 2


*/
int i,j,k,n,s,t,m;
const int N=200005;
int a[N],pd[N],ass[N];
set<int> st;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		st.clear();
		int ans=0;
		read(n);
		for(i=1;i<=n;i++)
		pd[i]=0,ass[i]=0;
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			if(pd[a[i]]==0)
			{
				pd[a[i]]=i;
				ass[i]=a[i];
				ans++;
			}
		}
		for(i=1;i<=n;i++)
		if(pd[i]==0)
		st.insert(i);
		
		if(ans==n-1)
		{
			int val=*st.begin();
			if(ass[val]==0)
			{
				int to=pd[a[val]];
				ass[to]=val;
				ass[val]=a[val];
			}
			else
			{
				for(i=1;i<=n;i++)
				if(ass[i]==0)
				ass[i]=val;
			}
			printf("%d\n",ans);
			for(i=1;i<=n;i++)
			printf("%d ",ass[i]);
			printf("\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(ass[i])continue;
			if(st.count(i)==0)continue;
			auto it=st.lower_bound(i);
			
			if(it!=st.begin())
			it--;
			else	
			it=st.end(),it--;
		
			pd[*it]=i;
			ass[i]=*it;
			st.erase(it);
		}
		for(i=1;i<=n;i++)
		{
			if(ass[i])continue;
			auto it=st.lower_bound(i);
			if(it==st.end())it=st.begin();
			
			pd[*it]=i;
			ass[i]=*it;
			st.erase(it);
		}
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
		printf("%d ",ass[i]);
		printf("\n");
	}
	return 0;
}

