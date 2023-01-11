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
const int N=2e5+10,mod=998244353;
int i,j,k,n,s,t,m,ans=1;
int a[N],pos[N],b[N],vis[N],vis2[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(s);int all=0;ans=1;
		memset(pos,0,sizeof(int)*(n+5));
		memset(vis,0,sizeof(int)*(n+5));
		memset(vis2,0,sizeof(int)*(n+5));
		for(i=1;i<=n;i++){
			read(a[i]);pos[a[i]]=i;
		}
		for(i=1;i<=n;i++){
			read(b[i]);
			if(b[i]==-1)continue;
			vis[i]=1;vis2[b[i]]=1;
			if(a[i]-b[i]>s)ans=0;
		}
		
		for(i=1;i<=s;i++)
		if(!vis[pos[i]])all++;
		
		for(i=1;i<=n;i++){
			if(i+s<=n&&vis[pos[i+s]]==0)all++;
			if(vis2[i])continue;
			ans=1ll*ans*all%mod,all--;
		}
		cout<<ans<<endl;
	}



	return 0;
}


