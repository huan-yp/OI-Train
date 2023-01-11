#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		a[0]=-1,a[n+1]=INF+10;
		for(i=1;i<=n;i++)read(a[i]);
		int maxpos=0,minpos=n+1;
		for(i=1;i<=n;i++){
			if(a[i]>a[maxpos])maxpos=i;
			if(a[i]<a[minpos])minpos=i;
		}
		printf("%d %d\n",maxpos,minpos);
	} 
	return 0;
}


