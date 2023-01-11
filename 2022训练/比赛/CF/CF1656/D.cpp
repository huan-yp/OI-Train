#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e7+10;
int i,j,k,n,s,t,m;
bool pd[N];
int zs[N/5];
void init(){
	for(i=2;i<N;i++){
		if(!pd[i])zs[++s]=i;
		for(j=1;j<=s&&zs[j]*i<N;j++){
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)break;
		}
	}
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);init();
	while(t--){
		read(n);int ans=-1;
		for(i=2;i<1ll<<62;i*=2){
			int res=2*n/i;
			if(res%2){
				if(res>i){
					ans=i;
					break;	
				}
				else{
					ans=res;
					break;
				}
			}
		}
		if(ans==1)puts("-1");
		else printf("%lld\n",ans);
	} 
	return 0;
}


