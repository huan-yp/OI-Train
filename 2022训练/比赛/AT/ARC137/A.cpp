#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
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
int i,j,k,n,s,t,m;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	//gcd(x,y)=1
	//gcd(x,y+1)=
	//gcd(x,y)=gcd(x,x-y);
	//y<=r-x
	//x>=l;
	int l,r;read(l),read(r);
	for(i=0;;i++){
		for(j=l;j<=l+i;j++)
		if(gcd(j,j+r-l-i)==1){
			printf("%lld\n",r-l-i);
			return 0;
		}
	}
	
	
	
	
	return 0;
}


