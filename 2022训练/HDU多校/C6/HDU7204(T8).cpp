#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
#define pres(x) (x*(x+1)/2*(2*x+1)/3)
#define pre(x) (x*(x+1)/2)
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
int i,j,k,n,s,t,m,tp1,tp2;
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);int im=m;	
		int b1=0,b2=0,bi=0;k=1;
		while(m>1){
			if(!(m&1)){
				b1=b1*2-1;
				if(im!=m)bi=bi*2-1;
				else bi=bi*2;
				b2=b2*2;
			}
			else{
				b1=b1*2;
				b2=b2*2+1;
				bi=bi*2;
			}
			k*=2;
			m>>=1;
		}
		int ans=0;
		
		if(n-b2-k>0){
			int lim=(n-2*k-b1)/k;
			ans+=b2-bi+1;
			ans+=(lim+pre(lim))*(b2-b1+1);
			lim++;
			int lst=n-(lim*k+b2);lim++;
			ans+=lim*lst;
		}
		else{
			ans=max(n-(k+bi)+1,0ll);
		}
		cout<<ans<<endl;
	} 
	return 0;
}


