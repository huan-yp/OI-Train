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
const int N=106+10;
int i,j,k,n,s,t,m,tp1,tp2;
char a[N],b[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		int flag=0;
		read(n),read(m);
		if(n<m){
			puts("NO");
			continue;
		}
		scanf("%s%s",a+1,b+1);
		for(i=2;i<=m;i++)
		if(b[i]!=a[n-m+i])flag=1;
		if(flag){
			puts("NO");
			continue;
		}
		flag=0;
		for(i=1;i<=n-m+1;i++)
		if(b[1]==a[i])flag=1;
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}


