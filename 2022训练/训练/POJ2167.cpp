#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
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
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2,fsz;
vector<int> factors;
struct Num{
	int cnt[25];
	Num(int x){
		memset(cnt,0,100);
		for(int i=0;i<fsz;i++){
			while(x%factors[i]==0){
				x/=factors[i];
				cnt[i]++;
			}
		}
	}
	Num(){
		
	}
	Num operator =(int x){
		memset(cnt,0,100);
		for(int i=0;i<fsz;i++){
			while(x%factors[i]==0){
				x/=factors[i];
				cnt[i]++;
			}
		}
		return *this;
	}
	void operator *=(const Num &x){
		for(int i=0;i<fsz;i++)
		cnt[i]+=x.cnt[i];
	}
	void operator *=(const int num){
		Num x(num);
		for(int i=0;i<fsz;i++)
		cnt[i]+=x.cnt[i];
	}
	Num operator *(Num x){
		for(int i=0;i<fsz;i++)
		x.cnt[i]+=cnt[i];
		
		return x;
	}
	void operator /=(const Num &x){
		for(int i=0;i<fsz;i++)
		cnt[i]-=x.cnt[i];
	}
	void operator /=(const int num){
		Num x=num;
		for(int i=0;i<fsz;i++)
		cnt[i]-=x.cnt[i];
	}
	bool ok(){
		for(int i=0;i<fsz;i++)if(cnt[i]<0)
		return false;
		return true;
	}
};
Num inv[N],f[N];
Num C(int n,int m){
	return f[n]*inv[m]*inv[n-m];
}
signed main()
{
	read(n),read(m);int r=m;
	for(i=2;i*i<=m;i++)if(m%i==0){
		factors.push_back(i);
		do{
			m/=i;
		}while(m%i==0);
	}
	if(m!=1)factors.push_back(m);
	m=r;
	fsz=factors.size();
	for(i=1;i<=n;i++){
		f[i]=f[i-1],inv[i]=inv[i-1];
		f[i]*=i,inv[i]/=i;
	}
	int ans=0;
	inv[0]=f[0]=1;
	for(i=1;i<=n;i++){
		Num res=C(n-1,i-1);res/=m;
		if(res.ok())ans++;
	}
	cout<<ans<<endl;
	for(i=1;i<=n;i++){
		Num res=C(n-1,i-1);res/=m;
		if(res.ok())printf("%d ",i);
	}
	puts("");
	return 0;
}


