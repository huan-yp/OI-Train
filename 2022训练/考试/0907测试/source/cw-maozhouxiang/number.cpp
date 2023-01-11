#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=1e7+10;
int i,j,k,n,s,t,m,tp1,tp2;
int zs[N/10],sum[N];
bool pd[N];
bool ok(int x,int sm=0){
	while(x)sm+=x%10,x/=10;
	return !pd[sm];
}
void init(){
	sum[1]=0;pd[1]=1;
	for(i=2;i<N;i++){
		sum[i]=sum[i-1];
		if(!pd[i])zs[++s]=i,sum[i]+=ok(i);
		for(j=1;zs[j]*i<N&&j<=s;j++){
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)break;
		}
	}
}
signed main()
{
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen(".in","w",stdout);
	cin.tie()->sync_with_stdio(0);
	int l,r,a,b,c;
	cin>>t;
	cin>>l>>r>>a>>b>>c;
	init();
	s=0;
	while(t--){
		int ans=sum[r]-sum[l-1]; 
		s^=sum[r]-sum[l-1];
		l=((l^b)+a)%c+1,r=((r^b)+a)%c+1;
		if(l>r)swap(l,r);	
	}
	cout<<s<<endl;
	return 0;
}


