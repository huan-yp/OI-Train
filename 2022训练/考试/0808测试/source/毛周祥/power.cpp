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
const int N=2e7+10;
int phi[N],zs[N/10];
bool pd[N];
int i,j,k,n,s,t,m,tp1,tp2;
struct barret{
	unsigned long long im;
	unsigned m;
	barret(unsigned mm):im((~0ull/mm+1)),m(mm){}
	unsigned operator ()(unsigned a,unsigned b){
		unsigned long long z=1ull*a*b;
		unsigned v=z-((__int128)z*im>>64)*m;
		return v>m?v+m:v;
	}
};
int quick(int a,int s,int mod){
	int ret=1;
	barret reducer(mod);
	while(s){
		if(s&1)ret=reducer(ret,a);
		a=reducer(a,a),s>>=1;
	}
	return ret;
}
int quick_s(int a,int s,int mod){
	int ret=1;
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod,s>>=1;
	}
	return ret;
}
int solve(int x,int y){
	if(y==1)return 0;
	int r=solve(x,phi[y]);
	return quick(x,r+phi[y],y);
}
void init(){
	for(i=2;i<N;i++){
		if(!pd[i])zs[++s]=i,phi[i]=i-1;
		for(j=1;j<=s&&zs[j]*i<N;j++){
			pd[zs[j]*i]=1;
			if(i%zs[j]==0){
				phi[i*zs[j]]=phi[i]*zs[j];
				break;
			}
			phi[zs[j]*i]=phi[i]*(zs[j]-1);
		}
	}
}
signed main()
{
 	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
//	freopen(".in","w",stdout);
	init();
	read(t);
	while(t--){
		int x,y;
		read(x),read(y);
		printf("%d\n",solve(x,y));	
	}
	return 0;
}


