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
const int N=2e5+10;
int i,j,k,n,s,t,m,minu=INF*2,maxn,dec;
int a[N],b[N],pre[N];
signed main()
{	
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);int ans=0,now=0,ti=0,dec=0;
	for(i=0;i<n;i++)read(a[i]),cmax(maxn,a[i]);
	for(i=0;i<n;i++)pre[i]=max(0ll,a[i]-a[(i-1+n)%n]);
	for(i=0;i<n;i++)ans+=pre[i];
	cout<<max(ans,maxn)<<endl;
	return 0;
}

