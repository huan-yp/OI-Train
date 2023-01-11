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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=5005;
int i,j,k,n,s,t,m;
int a[N],cnt[N];
long long ans=0;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(a[i]),cnt[a[i]]++;
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	if(a[i]>a[j])
	ans+=k;

	for(i=1;i<=5000;i++)
	cnt[i]+=cnt[i-1];
	for(i=1;i<=n;i++)
	ans+=1ll*cnt[a[i]-1]*k*(k-1)/2;
	
	cout<<ans<<endl;
	return 0;
}

