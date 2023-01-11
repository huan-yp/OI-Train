#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m,c;
int a[N],sum[N];
int es(int l,int r){
	cmin(r,c);
	return sum[r]-sum[l-1];
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--){
		read(n),read(c);int flag=1;
		for(i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+n+1);
		if(a[1]!=1){
			puts("No");
			continue;
		}
		for(i=1;i<=n;i++)sum[a[i]]++;
		for(i=1;i<=c;i++)sum[i]+=sum[i-1];
		for(i=2;i<=c;i++)
		for(j=1;i*j<=c;j++){
			if(es(i*j,(i+1)*j-1)&&es(j,j)&&!es(i,i))
			flag=0;
		}
		if(flag)puts("Yes");
		else puts("No");
		for(i=1;i<=c;i++)sum[i]=0;
	}

	return 0;
}

