#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);

// 等一个详细证明 
	read(t);
	while(t--){
		read(n);
		for(i=1;i<=n;i++)read(a[i]);
		memcpy(b,a,sizeof(int)*(n+5));
		LL s1=0,s2=0;
		for(i=2;i<=n;i++){
			if(i&1){
				int inc=max(b[i-1]+1-b[i],0ll);
				s1+=inc;
				b[i]+=inc;
			}
			else{
				int dec=max(b[i]-(b[i-1]-1),0ll);
				s1+=dec;
				b[i]-=dec;
			}
		}	
		memcpy(b,a,sizeof(int)*(n+5));
		for(i=2;i<=n;i++){
			if(!(i&1)){
				int inc=max(b[i-1]+1-b[i],0ll);
				s2+=inc;
				b[i]+=inc;
			}
			else{
				int dec=max(b[i]-(b[i-1]-1),0ll);
				s2+=dec;
				b[i]-=dec;
			}
		}
		cout<<min(s1,s2)<<endl;
	}
	return 0;
}


