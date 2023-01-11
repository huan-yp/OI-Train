#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
const int maxh=150+10,maxw=500+10;
//            _     _     _    
//  | \ |   | _ |   _  |  _    
//1 2 3 4 5 6 7 8 9 10 11 12 13
int f1[maxw];
int f2[maxw][maxh][maxh];
int f3[maxw][maxh][maxh];
int f4[maxw][maxh][maxh];
int f5[maxw];
int f6[maxw][maxh][maxh];
int f7[maxw][maxh][maxh];
int f8[maxw][maxh][maxh];
int f9[maxw];
int f10[maxw][maxh][maxh];
int f11[maxw][maxh][maxh];
int f12[maxw][maxh][maxh];
int f13[maxw];
int a[maxh][maxw];
int psum[maxh][maxw];
int g[maxh][maxh];
int l[maxh][maxh];
int calc(int h1,int w1,int h2,int w2){return psum[h2][w2]-psum[h1-1][w2]-psum[h2][w1-1]+psum[h1-1][w1-1];}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{
			cin>>a[i][j];
			psum[i][j]=a[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
		}
	for(int i=0;i<maxw;i++)
		for(int j=0;j<maxh;j++)
			for(int k=0;k<maxh;k++)
				f1[i]=
				f2[i][j][k]=
				f3[i][j][k]=
				f4[i][j][k]=
				f5[i]=
				f6[i][j][k]=
				f7[i][j][k]=
				f8[i][j][k]=
				f9[i]=
				f10[i][j][k]=
				f11[i][j][k]=
				f12[i][j][k]=
				f13[i]=
				l[j][k]=
				g[j][k]=
				-inf;
	
	//Part 1
	for(int i=0;i<=w;i++)
		f1[i]=0;
	//Part 1 -> Part 2
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j;k<=h;k++)
				f2[i][j][k]=f1[i-1]+calc(j,i,k,i);
	//Part 2
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j;k<=h;k++)
				f2[i][j][k]=max(f2[i][j][k],f2[i-1][j][k]+calc(j,i,k,i));
	//Part 2 -> Part 3
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
		{
			int mx=-inf;
			for(int k=h;k>=j;k--)
			{
				f3[i][j][k]=mx+calc(j,i,k,i);
				mx=max(mx,f2[i-1][j][k]);
			}
		}
	//Part 3
	for(int i=2;i<=w;i++)
	{
		for(int j=2;j<=h;j++)
			for(int k=j-1;k<=h;k++)
				g[j][k]=max(g[j-1][k],f3[i-1][j-1][k]);
		for(int j=2;j<=h;j++)
			for(int k=j-1;k<=h;k++)
				l[j][k]=max(l[j][k-1],g[j][k]);
		for(int j=1;j<=h;j++)
			for(int k=1;k<=h;k++)
				f3[i][j][k]=max(f3[i][j][k],l[j][k]+calc(j,i,k,i));
	}
	//Part 3 -> Part 4
	for(int i=1;i<=w;i++)
		for(int k=1;k<=h;k++)
		{
			int mx=-inf;
			for(int j=k;j;j--)
			{
				f4[i][j][k]=mx+calc(j,i,k,i);
				mx=max(mx,f3[i-1][j][k]);
			}
		}
	//Part 4
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=1;k<=h;k++)
				f4[i][j][k]=max(f4[i][j][k],f4[i-1][j][k]+calc(j,i,k,i));
	//Part 4 -> Part 5
	for(int i=1;i<w;i++)
		for(int j=1;j<=h;j++)
			for(int k=1;k<=h;k++)
				f5[i+1]=max(f5[i+1],f4[i][j][k]);
	//Part 5
	for(int i=2;i<=w;i++)
		f5[i]=max(f5[i],f5[i-1]);
	//Part 5 -> Part 6
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f6[i][j][k]=f5[i-1]+calc(j,i,k,i);
	//Part 6 -> Part 7
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f7[i][j][k]=f6[i-1][j][k]+a[j][i]+a[k][i];
	//Part 7
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f7[i][j][k]=max(f7[i][j][k],f7[i-1][j][k]+a[j][i]+a[k][i]);
	//Part 7 -> Part 8
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f8[i][j][k]=f7[i-1][j][k]+calc(j,i,k,i);
	//Part 8 -> Part 9
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f9[i]=max(f9[i],f8[i-1][j][k]);
	//Part 9
	for(int i=2;i<=w;i++)
		f9[i]=max(f9[i],f9[i-1]);
	//Part 9 -> Part 10
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f10[i][j][k]=f9[i-1]+a[j][i]+a[k][i];
	//Part 10
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f10[i][j][k]=max(f10[i][j][k],f10[i-1][j][k]+a[j][i]+a[k][i]);
	//Part 10 -> Part 11
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f11[i][j][k]=f10[i-1][j][k]+calc(j,i,k,i);
	//Part 11 -> Part 12
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f12[i][j][k]=f11[i-1][j][k]+a[j][i]+a[k][i];
	//Part 12
	for(int i=2;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f12[i][j][k]=max(f12[i][j][k],f12[i-1][j][k]+a[j][i]+a[k][i]);
	//Part 12 -> Part 13
	for(int i=1;i<=w;i++)
		for(int j=1;j<=h;j++)
			for(int k=j+2;k<=h;k++)
				f13[i+1]=max(f13[i+1],f12[i][j][k]);
	//Part 13
	for(int i=2;i<=w+1;i++)
		f13[i]=max(f13[i],f13[i-1]);
	
	cout<<f13[w+1]<<endl;
	return 0;
}
