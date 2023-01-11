#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1e7+10,M=1e4+10;
int i,j,k,n,s,t,m,tp1,tp2,cnt;
int a[N];
set<pii> st;
bool check(int x){
	while(x){
		if(x%3==1)return false;
		x/=3;
	}
	return true;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen("1.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);
	for(i=0;i<N/2;i++){
		if(check(i))
		a[++cnt]=i;
	}
	int now;
	for(now=a[1]=-N/2;a[1]<=-N/2+1;a[1]++,now=a[1]){
		for(i=2;i<=n;i++)
		now+=a[i],st.insert(make_pair(a[i]%n,i));
		for(i=n+1;i<=cnt;i++){
			int target=((now+a[i]-m)%n+n)%n;
			auto it=st.lower_bound(make_pair(target,0));
			if(it==st.end()||it->first!=target)continue;
			int pos=it->second;
			now+=a[i]-a[pos],a[pos]=a[i];
			break;
		}
		if(i<=cnt)break;
	}
	if(!(k<=n+10))exit(1);
//	printf("%lld %lld\n",n,m);
	int bias=(m-now)/n;
	for(i=1;i<=n;i++){
		printf("%lld ",a[i]+bias);
	}
	
	return 0;
}


