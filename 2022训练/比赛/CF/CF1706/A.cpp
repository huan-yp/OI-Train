#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=55;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			if(a[i]<m-a[i]+1&&b[a[i]]==0)b[a[i]]=1;
			else if(b[m-a[i]+1]==0)b[m-a[i]+1]=1;
			else b[a[i]]=1;
		}
		for(i=1;i<=m;i++)if(b[i])putchar('A');else putchar('B');
		puts("");
	}
	return 0;
}


