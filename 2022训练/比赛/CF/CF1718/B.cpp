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
int f[N],sm[N],a[N];
int i,j,k,n,s,t,m,tp1,tp2;
int get(int x){
	return upper_bound(f+1,f+i+1,x)-f-1;
}
int solve(int x,int lim=50){
	if(x==0)return 1;
	int pos=get(x);
	if(x>sm[pos])return 0;
	if(pos==j+1&&tp1&&tp2==k){
		if(x==f[pos]&&lim!=0){
			tp1=0;
			return 1;
		}
	}
	if(((1ll<<pos)&s)&&pos<lim){
		s^=1ll<<pos;
		return solve(x-f[pos],pos-1);
	}
	return 0;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	f[0]=f[1]=1;sm[0]=sm[1]=1;
	for(i=2;i<=44;i++)f[i]=f[i-1]+f[i-2],sm[i]=sm[i-2]+f[i];
//	for(i=1;i<=43;i++)cout<<f[i]<<' '<<sm[i-1]<<endl;
//	cout<<f[43]<<endl;
	read(t);
	while(t--){
		read(n);
		int flag=0;m=0;
		for(i=1;i<=n;i++)read(a[i]),m+=a[i];
		if(n==1&&a[1]==1){
			puts("YES");
			continue;
		}
		if(n>=45){
			puts("NO");
			continue;
		}
		for(i=1;i<=43;i++){
			int bm=(1ll<<i+1)-1;
			if(m!=sm[i]+sm[i-1])continue;
			for(j=0;j<=i;j+=2){
				bm^=1ll<<j;
				for(tp2=1;tp2<=n;tp2++){
					if(a[tp2]<f[j+1])continue;
					tp1=1;
					int pd=1;s=bm;	
					for(k=1;k<=n;k++){
						if(!solve(a[k])){
							pd=0;
							break;
						}
					}
					flag|=pd;
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}


