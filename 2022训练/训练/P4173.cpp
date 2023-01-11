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
const int N=1.2e6+10;
const double Pi=acos(-1.0);
int i,j,k,n,s,t,m,lim;
struct comple{
	double x,y;
	comple operator +(const comple &a){
		return comple{x+a.x,y+a.y};
	}
	comple operator -(const comple &a){
		return comple{x-a.x,y-a.y};
	}
	comple operator *(const comple &a){
		return comple{x*a.x-y*a.y,x*a.y+y*a.x};
	}
	void operator +=(const comple &a){
		x+=a.x,y+=a.y;
	}
	void operator -=(const comple &a){
		x-=a.x,y-=a.y;
	}
	void operator *=(const comple &a){
		double tx=x;
		x=x*a.x-y*a.y,y=y*a.x+tx*a.y;
	}
};
int res[N],vala[N],valb[N];
comple a[N],b[N],c[N];
char ch[N],str[N];
void FFT(comple val[],int type=1){
	for(i=0;i<1<<lim;i++)
	if(res[i]>i)swap(val[i],val[res[i]]);
	for(i=1;i<=lim;i++){
		for(j=0;j<1<<lim;j+=1<<i){
			comple wn={cos(2*Pi/(1<<i)),type*sin(2*Pi/(1<<i))},w={1,0};
			for(k=0;k<1<<i-1;k++,w*=wn){
				comple y=val[j+k+(1<<i-1)]*w;
				val[j+k+(1<<i-1)]=val[j+k]-y,val[j+k]+=y;
			}
		}
	}
}

signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(m),read(n);
	while(1<<lim<=n+m)lim++;
	for(i=1;i<1<<lim;i++)res[i]=res[i>>1]>>1|i%2<<lim-1;
	scanf("%s%s",str+1,ch+1);
	for(i=1;i<=m;i++)valb[i]=str[i]=='*'?0:str[i]-'a'+1;
	for(i=1;i<=n;i++)vala[i]=ch[i]=='*'?0:ch[i]-'a'+1;
	for(i=1;i<=n;i++)a[i]={pow(vala[i],3)};
	for(i=1;i<=m;i++)b[i]={valb[m-i+1]};
	FFT(a),FFT(b);
	for(i=0;i<1<<lim;i++)c[i]+=a[i]*b[i];
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)a[i]={vala[i]};
	for(i=1;i<=m;i++)b[i]={pow(valb[m-i+1],3)};
	FFT(a),FFT(b);
	for(i=0;i<1<<lim;i++)c[i]+=a[i]*b[i];
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)a[i]={pow(vala[i],2)};
	for(i=1;i<=m;i++)b[i]={-2*pow(valb[m-i+1],2)};
	FFT(a),FFT(b);
	for(i=0;i<1<<lim;i++)c[i]+=a[i]*b[i];
	FFT(c,-1);
	
	int ans=0;
	for(i=1+m;i<=n+1;i++)
	if(abs(c[i].x)/(1<<lim)<=0.1)ans++;
	cout<<ans<<endl;
	for(i=1+m;i<=n+1;i++)
	if(abs(c[i].x)/(1<<lim)<=0.1)cout<<i-m<<' ';
	return 0;
}


