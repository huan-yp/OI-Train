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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int a[N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	//maxval
	//
	//01234 x x+1
	//0 2 4 1
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);a[0]=-1;
	for(i=1;i<n;i++)s+=a[i]-a[i-1]-1;
	if(s%2)printf("Alice\n");
	else{
		if(a[n]==a[n-1]+1)printf("Bob\n");
		else printf("Alice\n");
	}
	
	
	return 0;
}


