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
we can maintain an array dp[i],denote the length of LIS begin in position i 
we assume that heights don't change
added tree i has a height of h[i]-t,and only has a influence on few trees added before.
erased tree i will only influence few position
notes: no same height any time
notes: no position will be added twice.
主席树维护。 
*/
const int N=200005;
struct node{
	int ls,rs,val;
}a[N<<6];
int i,j,k,n,s,t,m;
int T[N],pos[N],w[N];
set <int> st;
void push_up(int rt)
{
	a[rt].val=max(a[a[rt].ls].val,a[a[rt].rs].val);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);k=nst.insert(n+1);
	for(i=1;i<=n+1;i++)T[i]=i;
	
	for(i=1;i<=m;i++)
	{
		int type,p,h;
		read(type);
		if(type==1)
		{
			read(p),read(h);h+=m-i,w[p]=h;
			st.insert(p);
			
			int fir=*st.begin();
			printf("%d\n",quert(1,m+10,T[fir],1,m+10));
		}
		else
		{
			read(p);auto it=st.begin();p--;
			while(p--)it++;
			auto tmp=it;if(it!=st.begin())it--;st.earse(tmp);
			
			for(i=p-1;p>=1;p--)
			{
				tmp=it;tmp++;
				int ans=quert(1,n,T[*tmp],1,w[*it]-1)+1;
				updata(1,m+10,T[*it],T[*tmp],w[*it],ans);
				if(it!=st.begin())it--;
			}
			//暴力重算每一颗转移线段树. 
			
			int fir=*st.begin();
			printf("%d\n",quert(1,m+10,T[fir],1,m+10));
		}	
		pos[i]=p;
	} 
	return 0;
}

