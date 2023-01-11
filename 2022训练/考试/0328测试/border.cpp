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
const int base=173,mod=1e9+27;
const int N=1e6+10;
int i,j,k,n,s,t,m;
char ch[N]; 
int h[N],p[N],ans[N];
int hsh(int l,int r){
	return (h[r]-1ll*h[l-1]*p[r-l+1]%mod+mod)%mod;
}
signed main()
{
 	freopen("border.in","r",stdin);
	freopen("border.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);p[0]=1;
	for(i=1;i<=n;i++)p[i]=1ll*base*p[i-1]%mod;
	for(i=1;i<=n;i++)h[i]=(1ll*h[i-1]*base%mod+ch[i])%mod;
//	printf("%d %d\n",hsh(1,5),hsh(5,9));
	for(i=1;i<=n/2;i++){
		int l=1,r=i,res=n;
		while(r>=l){
			int mid=(l+r)/2;
			int li=mid,ri=i*2-li;
			if(hsh(li,ri)==hsh(n-ri+1,n-li+1))
			res=mid,r=mid-1;
			else
			l=mid+1;
		}
		cmax(ans[res],i);
	}
	for(i=1;i<=(n+1)/2;i++){
		cmax(ans[i],ans[i-1]);
		if(ans[i]<i)printf("-1 ");
		else printf("%d ",(ans[i]-i)*2+1);
	}
	
	
	return 0;
}


