#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
int i,j,k,m,n,s,t;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> T;
signed main(){ 
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	//read(n),cout<<n<<endl;
	read(n);
	T.insert((int)-1e9);
	T.insert((int)1e18);
//	cout<<*T.find_by_order(2)<<endl;
	for(i=1;i<=n;i++){
		int op,k,ans=-1;read(op),read(k);
		if(op==0)T.insert((k<<20)+i);
		if(op==1)T.erase(T.lower_bound(k<<20));
		if(op==2)ans=(*T.find_by_order(k))>>20;
		if(op==3)ans=T.order_of_key(k<<20)-1;
		if(op==4)ans=(*prev(T.lower_bound(k<<20)))>>20;
		if(op==5)ans=(*T.lower_bound((k+1)<<20))>>20;
		if(ans==-1)continue;
		if(ans>1e10||ans<0)puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}

