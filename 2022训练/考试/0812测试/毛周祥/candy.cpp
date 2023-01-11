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
const int N=2e5+10; 
int i,j,k,n,s,t,m,ans;
int a[N];
set<int>st;
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		st.clear();
		read(n);
		for(i=1;i<=n;i++){
			read(a[i]);
			auto it=st.find(a[i]-1);
			if(it==st.end()){
				st.insert(a[i]);
			}	
			else{
				st.erase(it);
				st.insert(a[i]);
			}
		}
		cout<<int(log2(st.size()-1))+1<<endl;
	}
	return 0;
}


