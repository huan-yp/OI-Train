#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=1<<18; 
int i,j,k,n,s,t,m;
int val[N];
char ch[N];
tuple<int,int,int> a[N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n);
	scanf("%s",ch);m=strlen(ch);
	for(i=0;i<m;i++)val[i]=ch[i];
	for(s=0;s<n;s++){
		for(int mask=0;mask<m;mask++){
			if(1<<s&mask)a[mask]={val[mask],val[mask^1<<s],mask};
			else a[mask]={val[mask],val[mask|1<<s],mask};
		}	
		sort(a,a+m);t=0;val[get<2>(a[0])]=0;
		for(i=1;i<m;i++){
			int valn1,valn2,rkn,val1,val2;
			tie(val1,val2,rkn)=a[i-1];tie(valn1,valn2,rkn)=a[i];
			if(valn1==val1&&valn2==val2)t--;t++;
			val[rkn]=t;
		}
	}
	for(i=0;i<m;i++)putchar(ch[get<2>(a[0])^i]);
	return 0;
}


