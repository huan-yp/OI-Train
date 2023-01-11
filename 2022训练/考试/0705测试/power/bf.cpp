#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
using namespace __gnu_pbds;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int B=1e5,S=1e7;
int i,j,k,n,s,t,m,p;
int pw[max(B,S)+10];
gp_hash_table<int,int> mp;
int get_step(int target){
	auto it=mp.find(target);
	if(it==mp.end())return B;
	return it->second;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%p;
		a=1ll*a*a%p;s>>=1;
	}
	return ret;
}
signed main()
{
 	freopen("power.in","r",stdin);
	freopen("power.ans","w",stdout);
	//freopen(".in","w",stdout);
	read(p),read(t);
	while(t--){
		int x;LL ans=1;
		read(x);mp.clear();
		int now=x,mx=x;pw[0]=1;

		mp.insert(make_pair(1,0));
		
		for(i=1;i<min(S,p);i++){
			ans+=mx;mp.insert(make_pair(now,i));pw[i]=now;
			now=1ll*now*x%p,cmax(mx,now);
		}
		for(int i=S;i<=B;i++)
		pw[i]=1ll*pw[i-1]*x%p;
		
		if(p<=S){
			cout<<ans<<endl;
			continue;
		}
		for(;i+B<p;){
			int inv=quick(now,p-2);
			int min_pos=get_step(inv);
			for(int tar=mx+1;tar<p;tar++)
				cmin(min_pos,get_step(1ll*tar*inv%p));
				
			now=1ll*now*pw[min_pos]%p;
			ans+=1ll*mx*min_pos;
			i+=min_pos;cmax(mx,now);
			if(now==1){
				ans+=1ll*(p-i)*mx;i=p;
				break;
			}
		}
		for(;i<p;i++){
			if(mx==p-1)break;
			ans+=mx;now=1ll*now*x%p;cmax(mx,now);
		}
		ans+=1ll*mx*(p-i);
		cout<<ans<<endl;
	}
	return 0;
}


