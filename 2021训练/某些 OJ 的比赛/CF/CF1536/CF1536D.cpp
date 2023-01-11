#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
const int N=2e5+10;
int a[N];
set<int>st;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	// consider the nature of mideans
	// when you add two elements to array,the position of it will change at most 1;
	// once the mideans change at most one ,we can have a constrction :
	// only add the midean ,to move it,we add INF and -INF
	// use this to solve the poblem
	// there is a specail condition:
	// if there are the same mideans , we actually can let the midean be at any position
	// obviously , only at the same value
	// so we have to find the next or last different element
	// the only condition that the answer is "No" is that new midean is strictly lower or higher than them. 
	read(t);
	while(t--)
	{
		int flag=1;
		read(n),read(a[1]);
		st.clear();
		st.insert(a[1]);
		st.insert(int(-2e9));
		st.insert(int(+2e9));
		for(i=2;i<=n;i++)
		{
			read(a[i]);
			auto it=st.lower_bound(a[i-1]);
			int pre=*(--it);
			int suf=*st.lower_bound(a[i-1]+1);
			if(a[i]<pre||a[i]>suf)
			flag=0;
			st.insert(a[i]);
		}
		if(flag)
		puts("YES");
		else
		puts("NO");
	}
	return 0;
}


