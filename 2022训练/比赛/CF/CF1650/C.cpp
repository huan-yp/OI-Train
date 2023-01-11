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
const int N=2e5+10;
int i,j,k,n,s,t,m;
struct point{
	int x,val,rk;
}p[N];
bool cmp1(point a,point b){
	return a.val<b.val;
}
bool cmp2(point a,point b){
	return a.x<b.x;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);
		for(i=1;i<=m;i++){
			read(p[i].x),read(p[i].val);
			p[i].rk=i;
		}	
		int ans=0;
		sort(p+1,p+m+1,cmp1);
		sort(p+1,p+2*n+1,cmp2);
		for(i=1;i<=2*n;i++){
			ans+=p[i].val;	
		}
		cout<<ans<<endl;
		for(i=1;i<=n;i++)
		printf("%lld %lld\n",p[i].rk,p[2*n-i+1].rk);
	}
	return 0;
}

