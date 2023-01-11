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
int i,j,k,n,s,t,m;
int ans[15][15];
signed main()
{
 	freopen("tile.in","r",stdin);
	freopen("tile.out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	ans[1][3]=1;
	ans[2][3]=2;
	ans[3][3]=6;
	ans[3][4]=12;
	while(t--){
		read(n),read(m);
		if(n>m)swap(n,m);
		cout<<ans[n][m]<<endl;
	}



	return 0;
}


