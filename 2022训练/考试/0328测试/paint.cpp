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
const int N=3500;
int i,j,k,n,s,t,m,a,p;
char ans[N][N];
int construct1(int n,int m,int x){
	memset(ans,0,sizeof(ans));
	if(n*m/6%3)return 0;
	int need=(n*m/6-x)/3,inci=0,incj=0,cnt=0;p=0;
	for(i=1;i+3<=n&&need;i+=4,inci^=2){
		for(j=1;j+5<=m&&need;j+=6,incj^=1){
			cnt++;
			need--;char ch='H'+inci+incj;
			for(int ii=i;ii<=i+3;ii++)
			for(int jj=j;jj<=j+5;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(need)return 0;
	for(i=1;i+1<=n;i+=2,inci^=2){
		for(j=1;j+2<=m;j+=3,incj^=1){
			if(ans[i][j]!=0)continue;
			char ch='A'+inci+incj;cnt++;
			for(int ii=i;ii<=i+1;ii++)
			for(int jj=j;jj<=j+2;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(cnt!=x)return 0;
	return 1;
}
int construct2(int n,int m,int x){
	memset(ans,0,sizeof(ans));
	if(n*m/6%3)return 0;
	int need=(n*m/6-x)/3,inci=0,incj=0,cnt=0;p=0;
	for(i=1;i+5<=n&&need;i+=6,inci^=2){
		for(j=1;j+3<=m&&need;j+=4,incj^=1){
			cnt++;
			need--;char ch='H'+inci+incj;
			for(int ii=i;ii<=i+5;ii++)
			for(int jj=j;jj<=j+3;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(need)return 0;
	for(i=1;i+2<=n;i+=3,inci^=2){
		for(j=1;j+1<=m;j+=2,incj^=1){
			if(ans[i][j]!=0)continue;
			char ch='A'+inci+incj;cnt++;
			for(int ii=i;ii<=i+2;ii++)
			for(int jj=j;jj<=j+1;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(cnt!=x)return 0;
	return 1; 
}
int construct3(int n,int m,int x){
	p=1;memset(ans,0,sizeof(ans));
	if(n*m/6<200)return 0;
	int need=((n*m/6-16)-x)/3,inci=0,incj=0,cnt=2,need2=2;
	for(i=1;i+8<=n&&need2;i+=9,inci^=2){
		for(j=1;j+5<=m&&need2;j+=6,incj^=1){
			need2--;char ch='O'+inci+incj;
			for(int ii=i;ii<=i+8;ii++)
			for(int jj=j;jj<=j+5;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(need2)return 0;
	for(i=1;i+5<=n&&need;i+=6,inci^=2){
		for(j=1;j+3<=m&&need;j+=4,incj^=1){
			if(ans[i][j])continue;cnt++;
			need--;char ch='G'+inci+incj;
			for(int ii=i;ii<=i+5;ii++)
			for(int jj=j;jj<=j+3;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(need)return 0;
	for(i=1;i+2<=n;i+=3,inci^=2){
		for(j=1;j+1<=m;j+=2,incj^=1){
			if(ans[i][j]!=0)continue;
			char ch='A'+inci+incj;cnt++;
			for(int ii=i;ii<=i+2;ii++)
			for(int jj=j;jj<=j+1;jj++){
				ans[ii][jj]=ch;
			}	
		}
	}
	if(cnt!=x)return 0;
	return 1;
}
signed main()
{
 	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	read(m);
	for(int i=6;;i+=6){
		if(m%3==1){
			int val=i*i/3;a=i;
			if(val/6>=m-1){
				if(construct1(i/3,i,m-1))break;
				if(construct2(i/3,i,m-1))break;
			}
		}
		if(m%3==2){
			int val=i*i/6;a=i;
			if(val>=m){
				if(construct3(i,i,m))break;
			}
			if(val/6>=m-2){
				if(construct1(i/3,i/2,m-2))break;
				if(construct2(i/3,i/2,m-2))break;
			}
		}
		if(m%3==0){
			int val=i*i;a=i;
			if(val/6>=m){
				if(construct1(i,i,m))break;
				if(construct2(i,i,m))break;
			}
		}
	}
	cout<<a<<endl;
	if(m%3==0||p==1){
		for(i=1;i<=a;i++){
			for(j=1;j<=a;j++)
			printf("%c",ans[i][j]);
			puts("");
		}
	}
	if(m%3==1){
		for(i=1;i<=a/3*2;i++){
			for(j=1;j<=a;j++)
			printf("Z");
			puts("");
		}
		for(i=1;i<=a/3;i++){
			for(j=1;j<=a;j++)
			printf("%c",ans[i][j]);
			puts("");
		}
	}
	if(m%3==2&&p==0){
		for(i=1;i<=a/3*2;i++){
			for(j=1;j<=a;j++)
			printf("Z");
			puts("");
		}
		for(i=1;i<=a/3;i++){
			for(j=1;j<=a/2;j++)
			printf("Y");
			for(j=1;j<=a/2;j++)
			printf("%c",ans[i][j]);
			puts("");
		}
	}
	return 0;
}
