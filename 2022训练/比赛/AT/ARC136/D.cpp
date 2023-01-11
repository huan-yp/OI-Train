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
const int N=1e6+10;
const int p[]={1,10,100,1000,10000,100000,1000000};
int i,j,k,n,s,t,m,ans;
int a[N],sum[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]),sum[a[i]]++;
		int x=a[i],flag=1;
		while(x){
			if(x%10>=5)flag=0;
			x/=10;
		}
		ans-=flag;
	}
	t=6;
	for(j=0;j<t;j++)
	for(i=0;i<p[t];i++){
		if(i/p[j]%10==0)continue;
		int tar=i-p[j];
		sum[i]+=sum[tar];
	}
	for(i=1;i<=n;i++)ans+=sum[p[t]-1-a[i]];
	
	cout<<ans/2<<endl;
	return 0;
}

