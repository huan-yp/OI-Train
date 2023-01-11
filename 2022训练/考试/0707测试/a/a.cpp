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
const int N=1005;
int i,j,k,n,s,t,m;
int a[N],b[N];
namespace generation{
	unsigned int SA, SB, SC;int p, A, B;
	unsigned int rng61(){
		SA ^= SA << 16;
		SA ^= SA >> 5;
		SA ^= SA << 1;
		unsigned int t = SA;
		SA = SB;
		SB = SC;
		SC ^= t ^ SA;
		return SC; 
	}
	void gen(){
		scanf("%d%d%d%d%u%u%u%d%d", &n, &k, &m, &p, &SA, &SB, &SC, &A, &B);
		for(int i = 1; i <= p; i++)scanf("%d%d", &a[i], &b[i]);
		for(int i = p + 1; i <= n; i++){
			a[i] = rng61() % A + 1;
			b[i] = rng61() % B + 1;
		} 
	}
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		generation::gen();
		
	}
	return 0;
}


