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
const int N=5e4+10;
int i,j,k,n,s,t,m;
bool cmp(string aa,string bb)
{
	return aa+bb<bb+aa;
}
string a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	cout<<a[i];
	return 0;
}


