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
const int N=3e5+10;
int i,j,k,n,s,t,m;
multiset<int> st;
int a[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		st.clear();
		for(i=1;i<=n;i++){
			int x;
			read(x);a[i]=x;
			st.insert(x);
		}
		for(i=1;i<=n;i++){
			int val=st.count(a[i]);
			while(val>3){
				st.erase(st.find(a[i]));
				val--;
			}
		}
		if(st.size()>30){
			puts("NO");
			continue;
		}
		s=0;int flag=1;
		for(auto v:st)
		a[++s]=v;
		for(i=1;i<=s;i++)
		for(j=1;j<=s;j++)
		for(k=1;k<=s;k++){
			if(i==j||j==k||i==k)continue;
			int val=a[i]+a[j]+a[k];
			if(st.find(val) == st.end())
			flag=0;
		}
		if(flag)
		puts("YES");
		else 
		puts("NO");
		
	}

	return 0;
}


