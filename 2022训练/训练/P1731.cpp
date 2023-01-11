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
int i,j,k,n,s,t,m,tp1,tp2,ans=INF,sum;
bool calc(int r,int h,int l,int lim){
	int v=0;
	for(int i=1;i<=l;i++){
		v+=r*r*h;
		r--,h--;
	}
	return v>=lim;
}
void dfs(int dep,int r,int h,int lif){
	if(lif<0)return ;
	if(sum+lif/(r)*2>=ans)return ;
	if(dep>=m+1){
		if(lif!=0)return ;
		s++;
		cmin(ans,sum);
		return ;
	}
	h--,r--;
	for(int nr=r;calc(nr,h,m-dep+1,lif)&&nr>=m-dep+1;nr--){
		for(int nh=h;calc(nr,nh,m-dep+1,lif)&&nh>=m-dep+1;nh--){
			sum+=2*nr*nh+nr*nr*(dep==1);
			dfs(dep+1,nr,nh,lif-nr*nr*nh);
			sum-=2*nr*nh+nr*nr*(dep==1);
		}
	}
}
signed main()
{
	read(n),read(m);
	dfs(1,sqrt(n)+1,n/(m*m)+1,n);
	if(ans!=INF)
	cout<<ans<<endl;
	else
	cout<<0<<endl;
	return 0;
}
