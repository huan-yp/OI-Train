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
const int N=2e5+10;
int i,j,k,n,s,t,m;
multiset<int> st;
struct point{
	int x,y;
	friend bool operator <(point a,point b)
	{
		return a.x<b.x;
	}
}a[N];
int getMax()
{
	if(st.end()==st.begin())return 0;
	auto it=st.end();
	it--;
	return *it;
}
int getMin()
{
	if(st.empty())return 2*INF;
	return *st.begin();
}
int check(int x)
{
	st.clear();
	j=1;
	for(i=1;i<=n;i++)
	{
		while(a[i].x-a[j].x>=x&&j<=n)
		st.insert(a[j].y),j++;
		
		if(getMax()-a[i].y>=x||a[i].y-getMin()>=x)
		return 1;
	}
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i].x),read(a[i].y);
	
	sort(a+1,a+n+1);
	int l=0,r=1e9,ans=0;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		ans=mid,l=mid+1;
		else
		r=mid-1;
	}
	cout<<ans<<endl;

	return 0;
}

