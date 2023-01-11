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
const int N=1e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],p[N];
set<int> st;
vector<int> e[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		int maxnn=0,ans=INF;
		read(n),read(k);st.clear(); 
		for(i=0;i<N;i++)e[i].clear();int a1=0;
		for(i=1;i<=n;i++)read(a[i]),cmax(maxnn,a[i]),cmax(a1,a[i]/k);
		sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
		ans=a1;int maxn=0;
		int T=2000;
		for(int minu=1;minu<=T&&minu<=a[1];minu++){
			if(minu<a[1]/k)continue;
			int maxn=0;
			for(i=1;i<=n;i++)
			cmax(maxn,a[i]/min(a[i]/minu,k));
			
			cmin(ans,maxn-minu);
		}
		for(j=1;j<=k&&j<=N/T+1;j++){
			for(i=1;i<=n;i++){
				e[a[i]/j].push_back(i);	
			}
		}
		for(i=1;i<=n;i++){
			p[i]=min(N/T+1,k);
			while(p[i]>0&&a[i]/p[i]<T)p[i]--;
			if(p[i]==0){maxn=INF;break;}
			cmax(maxn,a[i]/p[i]);
		}
		for(int minu=T+1;minu<=a[1];minu++){
			for(auto x:e[minu-1]){
				while(p[x]>0&&a[x]/p[x]<minu)p[x]--;
				if(p[x]==0){maxn=INF;break;}
				cmax(maxn,a[x]/p[x]);
			}
			if(maxn==INF)break;
			cmin(ans,maxn-minu);
		}
		cout<<ans<<endl;
	}
	return 0;
}


