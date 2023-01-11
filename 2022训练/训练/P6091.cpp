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
const int N=1e6+10;
int i,j,k,n,s,t,m,d;
int zs[N],pd[N],g_exist[N<<1],a[N],has[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%n;
		a=1ll*a*a%n;s>>=1;
	}
	return ret;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void init(){
	for(i=2;i<N;i++){
		if(!pd[i])zs[++s]=i;
		for(j=1;j<=s&&zs[j]*i<N;j++){
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)break;
		}
	}
	g_exist[2]=g_exist[4]=1;
	for(i=2;i<=s;i++){
		LL now=zs[i];
		while(now<N){
			g_exist[now]=g_exist[now*2]=1;
			now*=zs[i];
		}
	}
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	init();
	while(t--){
		int cnt=0,ans=0,pw;
		read(n),read(d);
		if(!g_exist[n]){
			printf("0\n\n");
			continue;
		}
		
		int phi=n,x=n;
		for(i=2;i*i<=x;i++){
			if(x%i==0)phi=phi/i*(i-1);
			while(x%i==0)x/=i;
		}
		if(x!=1)phi/=x,phi*=x-1;
		
		x=phi;
		for(i=2;i*i<=x;i++){
			if(x%i==0)has[++cnt]=i;
			while(x%i==0)x/=i;
		}
		if(x!=1)has[++cnt]=x;
		
		for(i=1;i<=n;i++){
			int flag=1;
			if(gcd(i,n)!=1)continue;
			for(j=1;j<=cnt;j++){
				if(quick(i,phi/has[j])==1){
					flag=0;
					break;
				}
			}
			if(flag)break;
		}
		pw=a[ans=1]=i;
		
		for(i=2;i<=phi;i++){
			pw=1ll*pw*a[1]%n;
			if(gcd(i,phi)==1)
			a[++ans]=pw;
		}
		
		printf("%d\n",ans);
		sort(a+1,a+ans+1);
		for(i=d;i<=ans;i+=d)
		cout<<a[i]<<" ";
		cout<<endl;
		
	}
	return 0;
}


