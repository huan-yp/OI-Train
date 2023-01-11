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
const int N=18;
int i,j,k,n,s,t,m,tp1,tp2;
int a[1<<N];
LL mx[1<<N/2],mi[1<<N/2],sum[1<<N/2],ans[1<<N];
signed main()
{
	freopen("in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=0;i<1<<n;i++)read(a[i]);
	int now=0;
	for(int mask1=0;mask1<1<<n/2;mask1++){
		LL gap=1<<n/2,max_val=0,m=n>>1;
		memset(mx,0,sizeof(mx)),memset(mi,0,sizeof(mi));
		for(i=0;i<1<<n;i+=gap){
			LL sm=0;
			for(j=i;j<i+gap;j++){
				sm+=a[j^mask1];
				if(sm>mx[i>>m])mx[i>>m]=sm;
				if(sm<mi[i>>m])mi[i>>m]=sm;
				cmax(max_val,sm-mi[i>>m]);
			}
			sum[i>>m]=sm;
		}
		for(int mask2=0;mask2<1<<n;mask2+=gap){
			ans[mask2^mask1]=max_val;
			LL min_val=0,sm=0;
			for(i=0;i<1<<n;i+=gap){
				cmax(ans[mask2^mask1],sm+mx[(i^mask2)>>m]-min_val);
				cmin(min_val,sm+mi[(i^mask2)>>m]);
				sm+=sum[(i^mask2)>>m];
			}
		}
	}
	int q;read(q);
	for(i=1;i<=q;i++){
		read(tp1);
		s^=1<<tp1;
		cout<<ans[s]<<endl;
	}
	return 0;
}
//test2

