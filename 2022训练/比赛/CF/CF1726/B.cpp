#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);
		if(m<n){
			puts("No");
			continue;
		}
		if(n%2){
			puts("Yes");
			for(i=1;i<n;i++)printf("1 ");
			printf("%d\n",m-n+1);
		}
		else{
	
			if(m%2==1)puts("No");
			else{
				puts("Yes");
				for(i=1;i<=n-2;i++)printf("1 ");
				m-=n-2;
				printf("%d %d\n",m/2,m/2);	
			}
		}
	}
	return 0;
}


