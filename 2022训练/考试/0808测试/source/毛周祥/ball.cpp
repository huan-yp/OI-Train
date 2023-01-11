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
const int N=10048,M=105;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int a[M];
bitset<N> ball[M];
signed main()
{
 	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	while(n--){
		bitset<N> now,statu;now.reset(),statu.reset();
		bool ok[M];memset(ok,0,sizeof(ok));
		read(m);
		for(i=1;i<=m;i++)read(a[i]),ok[a[i]]=1;
		for(i=0;i<=100;i++){
			now|=ball[i];
			if(ok[i]){
				statu^=now;
				now.reset();
			}
		}
		for(i=1;i<=m;i++)ball[a[i]][n]=1;
		ans+=statu.count();
	}
	cout<<ans<<endl;
	return 0;
}


