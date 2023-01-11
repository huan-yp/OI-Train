#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=1e6+10,mod=1e9+7;
int n,m;
int a[N],fa[N*20];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int make(int x,int y){return x*20+y;}
int make(pair<int,int> w){return make(w.first,w.second);}
pair<int,int> uzip(int x){return make_pair(x/20,x%20);}
void merge(int u,int v){fa[find(u)]=find(v);}
void ___solve(){
	int i,j;
	read(n),read(m);
	for(i=1;i<=n*20;i++)fa[i]=i;
	for(i=1;i<=m;i++){
		int x,y,len;
		read(len),read(x),read(y);
		for(j=0;j<20;j++)if(1<<j&len)
		merge(make(x,j),make(y,j)),x+=1<<j,y+=1<<j;			
	}
	for(i=19;i>=0;i--)
	for(j=1;j+(1<<i)-1<=n;j++){
		int rt=uzip(find(make(j,i))).first;
		merge(make(j,i-1),make(rt,i-1));
		merge(make(j+(1<<i-1),i-1),make(rt+(1<<i-1),i-1));
	}
	
	int ans=1;
	for(i=1;i<=n;i++){
		if(find(make(i,0))==make(i,0))
		ans=26ll*ans%mod;
	}
	cout<<ans<<endl;
}
signed main()
{
 	freopen("dealing.in","r",stdin);
	freopen("dealing.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


