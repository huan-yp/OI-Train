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
const int N=(int)(1e6+10)<<1;
int i,j,k,n,s,t,m,ans=0;
int a[N],f[N],c[N],b[N];
int solve(int x){
	for(int i=2;i<=sqrt(x+1);i++)
	if(x%i==0)return i;
	return x;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=2;i<=n;i++){
		if(i%2)f[i]=solve(i);	
	}
	for(i=2;i<=n;i++){
		c[i-f[i]]+=a[i];
		c[i+f[i]]-=a[i];
	}
	for(i=1;i<=n*2;i++){
		c[i]=c[i-1]+c[i];
		cmax(ans,c[i]);
	}
	memset(c,0,sizeof(c));
	for(i=2;i<=n;i++){
		if(i%2==0)continue;
		c[i-f[i]+1]+=a[i];
		c[i+f[i]]-=a[i];
	}
	for(i=1;i<=n*2;i++){
		c[i]=c[i-1]+c[i];
		cmax(ans,c[i]+(i%2==0)*a[i]);
	}
	cout<<ans+a[1]<<endl;
	return 0;
}

