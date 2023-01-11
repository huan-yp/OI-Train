#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m,d;
int a[N];
multiset<int> st;
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--){
		st.clear();
		read(n),read(d);
		for(i=1;i<=n;i++)read(a[i]),st.insert(a[i]-a[i-1]-1);
		int ans=0;
		for(i=1;i<=n;i++){
			st.erase(st.find(a[i]-a[i-1]-1));
			if(i!=n){
				st.insert(a[i+1]-a[i-1]-1);
				st.erase(st.find(a[i+1]-a[i]-1));
				int maxgap=max(*st.rbegin(),d-a[n]);
				cmax(ans,min(max((maxgap-1)/2,d-a[n]-1),*st.begin()));
				st.erase(st.find(a[i+1]-a[i-1]-1));
				st.insert(a[i+1]-a[i]-1);
			}
			else{
				int maxgap=max(*st.rbegin(),d-a[n-1]);
				cmax(ans,min(max((maxgap-1)/2,d-a[n-1]-1),*st.begin()));
			}
			st.insert(a[i]-a[i-1]-1);
		}
		cout<<ans<<endl;
	}

	return 0;
}

