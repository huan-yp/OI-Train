#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
int i,j,k,n,s,t,m;
int a[200005];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--){
		read(n);s=0;
		for(i=1;i<=n;i++)read(a[i]),s+=a[i];
		if(s==0){
			printf("0\n");
			continue;
		}	
		sort(a+1,a+n+1);
		if(2*a[n]-s>=1)printf("%lld\n",2*a[n]-s);
		else printf("1\n");
		
	}
	return 0;
}

