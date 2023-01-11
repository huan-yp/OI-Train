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
int i,j,k,n,s,t,m,a,b,ans,mod;
int p[20]={1};
void Inc(int &a,const int &b){a+=b;if(a>=mod)a-=mod;}
struct Matri{
	int a[3][3],n,m;
	friend Matri operator *(const Matri &a,const Matri &b){
		Matri res;res.n=b.n,res.m=a.m;
		for(int i=0;i<res.n;i++)
		for(int j=0;j<res.m;j++){
			res.a[i][j]=0;
			Inc(res.a[i][j],a.a[0][j]*b.a[i][0]%mod);
			Inc(res.a[i][j],a.a[1][j]*b.a[i][1]%mod);
			Inc(res.a[i][j],a.a[2][j]*b.a[i][2]%mod);
		}		
		return res;
	}
};
Matri quick(Matri a,int s){
	Matri ret=a;
	memset(ret.a,0,sizeof(ret.a));
	ret.a[0][0]=ret.a[1][1]=ret.a[2][2]=1;
	while(s){
		if(s&1)ret=ret*a;
		a=a*a;
		s>>=1;
	}
	return ret;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=ret*a%mod;
		a=a*a%mod;
		s>>=1;
	}
	return ret;
}
int calc(int start,int val,int n){
	Matri A,S;
	A.n=3,A.m=1,S.n=S.m=3;
	memset(S.a,0,sizeof(S.a));
	A.a[0][0]=start,A.a[1][0]=start+b%mod;A.a[2][0]=b%mod;
	S.a[0][0]=val,S.a[0][1]=S.a[1][2]=S.a[1][1]=S.a[2][2]=1;
	return (A*quick(S,n)).a[0][0];
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(a),read(b),read(mod);
	for(i=1;i<=18;i++)p[i]=p[i-1]*10;
	int now=1;
	for(i=17;i>=0;i--){
		int l=0,r=n-1,res=n;
		while(r>=l){
			int mid=(l+r)/2;
			if(a+b*mid>=p[i])
			r=mid-1,res=mid;
			else
			l=mid+1;
		}
		if(res==n)continue;
		int val=(a+b%mod*res%mod)%mod,len=n-res,tmp=calc(val,p[i+1]%mod,len-1);
		ans+=1ll*now*(tmp%mod);ans%=mod;
		now=now*quick(p[i+1]%mod,len)%mod;
		n=res;
		if(n==0)break;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}

