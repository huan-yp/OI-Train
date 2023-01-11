#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
multiset<int> st;
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int q;read(q);
	for(i=1;i<=q;i++){
		int op,x;read(op);
		if(op==1){
			read(x);st.insert(x);
		}
		if(op==2){
			read(x),read(k);
			auto it=st.upper_bound(x);
			for(j=1;j<=k;j++){
				if(it==st.begin())break;
				it--;
			}
			if(j==k+1)printf("%lld\n",*it);
			else printf("-1\n");
		}
		if(op==3){
			read(x),read(k);
			auto it=st.lower_bound(x);
			for(j=1;j<k;j++){
				if(it==st.end())break;
				it++;
				if(it==st.end())break;
			}
			if(it!=st.end()&&j==k)printf("%lld\n",*it);
			else printf("-1\n");
		}
	}

	return 0;
}

