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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N],cnt[N],ans[N];
set<int> st;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);m=0;int now=0;
		for(i=1;i<=n;i++)read(a[i]),cnt[a[i]]++;
		while(1)
		{	
			for(i=0;i<=n;i++)
			{
				if(cnt[i]==0)break;	
				st.insert(i);
			}
			int val=i;
			for(i=now+1;i<=n;i++)
			{
				st.erase(a[i]);
				now=i;cnt[a[i]]--;
				if(st.empty())break;
			}
			ans[++m]=val;
			if(now==n)
			break;
		}
		printf("%d\n",m);
		for(i=1;i<=m;i++)
		printf("%d ",ans[i]);
		printf("\n");
	}

	return 0;
}

