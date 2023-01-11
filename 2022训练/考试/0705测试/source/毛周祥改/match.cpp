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
const int N=2e5+10;
const double Pi=acos(-1.0);
struct comple{
	double x,y;
	comple operator +(const comple &a){return comple{x+a.x,y+a.y};}
	comple operator -(const comple &a){return comple{x-a.x,y-a.y};}
	comple operator *(const comple &a){return comple{x*a.x-y*a.y,x*a.y+y*a.x};}
	void operator +=(const comple &a){x+=a.x,y+=a.y;}
	void operator -=(const comple &a){x-=a.x,y-=a.y;}
	void operator *=(const comple &a){double tp=x;x=x*a.x-y*a.y,y=tp*a.y+y*a.x;}
};
int i,j,k,n,s,t,m,lim,ans;
int res[N],vala[N],valb[N],sum[N],nxt[N];
int dp[N],border[N][2],pre[32][N][2],from[N];
char ch[N],str[N];
double d[N];
comple a[N],b[N],c[N];
void FFT(comple val[],int type=1){
	for(i=0;i<1<<lim;i++)if(res[i]>i)swap(val[res[i]],val[i]);
	for(i=1;i<=lim;i++){
		for(j=0;j<1<<lim;j+=1<<i){
			comple w={1,0},wn={cos(2*Pi/(1<<i)),type*sin(2*Pi/(1<<i))};
			for(k=0;k<1<<i-1;k++,w*=wn){
				comple y=val[k+j+(1<<i-1)]*w;
				val[k+j+(1<<i-1)]=val[k+j]-y,val[k+j]+=y;
			}
		}
	}
	if(type==-1)for(i=0;i<1<<lim;i++)c[i].x/=(1<<lim);
}
void get_border(int x){
	if(x==0)return ;
	border[++s][0]=nxt[x],border[s][1]=x-nxt[x];
	if(nxt[x]*2>x)get_border(x%(x-nxt[x]));
	else get_border(nxt[x]);
}
void print(int pos,int lst){
	if(dp[pos]==0)return ;
	for(i=1,j=pos-m+1;i<=m&&j<lst;i++,j++){
		if(ch[j]!='?'&&ch[j]!=str[i]){
			printf("Error");
			return ;
		}
		if(j<1)continue;
		ch[j]=str[i];
	}
	print(from[pos],pos-m+1);
}
signed main()
{
 	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	//freopen(".in","w",stdout);
	scanf("%s%s",ch+1,str+1);
	n=strlen(ch+1),m=strlen(str+1);
	nxt[0]=j=-1;
	for(i=1;i<=m;i++){
		while(j!=-1&&str[j+1]!=str[i])j=nxt[j];
		nxt[i]=++j;
	}
	get_border(m);border[s][1]=1;
	while(1<<lim<=n+m)lim++;
	for(i=1;i<1<<lim;i++)res[i]=res[i>>1]>>1|(i&1)<<lim-1;
	for(i=1;i<=n;i++)vala[i]=ch[i]=='?'?0:ch[i]-'a'+1,sum[i]=sum[i-1]+vala[i]*vala[i]*vala[i];
	for(i=1;i<=m;i++)valb[i]=str[i]-'a'+1;
	
	for(i=1;i<=n;i++)a[i]={pow(vala[i],2)};
	for(i=1;i<=m;i++)b[i]={-2*valb[m-i+1]};
	FFT(a),FFT(b);
	for(i=0;i<1<<lim;i++)c[i]+=a[i]*b[i];
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)a[i]={vala[i]};
	for(i=1;i<=m;i++)b[i]={pow(valb[m-i+1],2)};
	FFT(a),FFT(b);
	for(i=0;i<1<<lim;i++)c[i]+=a[i]*b[i];
	FFT(c,-1);
	for(i=m;i<=n;i++)
	d[i]=sum[i]-sum[i-m]+c[i+1].x;

	for(i=m;i<=n;i++){
		for(j=1;j<=s;j++){
			if(pre[j][i-m+border[j][0]][0]+1>dp[i]){
				dp[i]=pre[j][i-m+border[j][0]][0]+1;
				from[i]=pre[j][i-m+border[j][0]][1];
			}
		}
		if(abs(d[i])>0.1)dp[i]=0;
		for(j=1;j<=s;j++){
			pre[j][i][0]=dp[i],pre[j][i][1]=i;
			if(pre[j][i-border[j][1]][0]>pre[j][i][0]){

				pre[j][i][0]=pre[j][i-border[j][1]][0];
				pre[j][i][1]=pre[j][i-border[j][1]][1];
			}
		}
		if(dp[i]>dp[ans])ans=i;
	}
	cout<<dp[ans]<<endl;
	print(ans,ans+1);
	for(i=1;i<=n;i++)if(ch[i]=='?')ch[i]='a';
	cout<<ch+1<<endl;
	return 0;
}


