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
const int N=2e5+10,P=1400;
int i,j,k,n,s,t,m,tp1,tp2;
int cor[N][3],block[N],br[N];
int sum[N],b[N],lim[N],a[N],c[N];
bool in[N];
int check(int p1,int p2){
	//is p1 not cover p2?
	if(cor[p1][0]==2)return cor[p1][2]-1ll*abs(cor[p1][1]-cor[p2][1])*2<cor[p2][2];
	return cor[p1][2]-1ll*abs(cor[p1][1]-cor[p2][1])<cor[p2][2];
}
void add_block(int l,int r){
	for(int op=1;op<=2;op++){
		memset(sum,191,sizeof(sum));
		for(int i=l;i<=r;i++){
			if(op!=cor[i][0]||in[i])continue;
			if(cor[i][2]>sum[a[i]])
			sum[a[i]]=cor[i][2];
		}
		cmax(lim[1],sum[1]),cmax(lim[m],sum[m]);
		for(int i=1;i<m;i++){
			if(sum[m-i]<sum[m-i+1]-op*(b[m-i+1]-b[m-i]))
			sum[m-i]=sum[m-i+1]-op*(b[m-i+1]-b[m-i]);
			if(sum[i+1]<sum[i]-op*(b[i+1]-b[i]))
			sum[i+1]=sum[i]-op*(b[i+1]-b[i]);
			cmax(lim[i+1],sum[i+1]),cmax(lim[m-i],sum[m-i]);
		}
	}
}
int locate(int idx,int l,int r){
	for(int i=idx+1;i<=br[idx];i++){
		if(in[i])continue;
		if(check(i,idx))continue;
		return i;
	}
	for(cmax(l,br[idx]+1);l<=r;l++){
		if(in[l])continue;
		if(check(l,idx))continue;
		return l;
	}
	return n+1;
}
signed main()
{
 	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	read(n);
	for(i=1;i<=n;i++){
		read(cor[i][0]),read(cor[i][1]),read(cor[i][2]);
		b[i]=cor[i][1];
	}
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,cor[i][1])-b;
	for(int b=1;b<=n;b+=P){
		for(i=b;i<b+P&&i<=n;i++){
			if(lim[a[i]]>=cor[i][2]){
				in[i]=1;
			}
			if(in[i])continue;
			for(j=b;j<i;j++){
				if(in[j]||check(j,i))continue;
				in[i]=1;break;
			}
			if(in[i])continue;
			c[i]++;
		}
		add_block(b,min(b+P-1,n));
	}
	memset(lim,0,sizeof(lim));
	for(int b=1;b<=n;b+=P){
		for(int id=b;id<=n;id++){
			i=n-id+1;if(in[i])continue;	
			if(lim[a[i]]>=cor[i][2])block[i]=n-(b-P)+1;
		}
		for(int id=b;id<b+P&&id<=n;id++){
			i=n-id+1;if(in[i])continue;	
			br[i]=n-b+1;
		}
		memset(lim,0,sizeof(lim));
		add_block(max(1ll,n-(b+P-1)+1),n-b+1);
	}
	for(i=1;i<=n;i++){
		if(in[i])continue;
		int r=block[i],l=r-P+1;
		cmax(l,1);
		c[locate(i,l,r)]--;
	}
	for(i=1;i<=n;i++)c[i]+=c[i-1];
	for(i=1;i<=n;i++)printf("%lld\n",c[i]);
	return 0;
}
