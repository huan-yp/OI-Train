#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int n,m;
int a[160][510];
int pr[160][510],pc[510][160];
int dn[510][160][160][3],di[510][160][160][3];
int N[510],O[510][510],I[510];
int seg[2010];
void add(int t,int l,int r,int pos,int val)
{
	//cout <<t<<" "<<l<<" "<<r<<" "<<pos<<" "<<val<<" ##\n";
	if (l==r)
	{
		seg[t]=max(seg[t],val);
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid) add(t*2,l,mid,pos,val);
	else add(t*2+1,mid+1,r,pos,val);
}
int maxi(int t,int l,int r,int li,int ri)
{
	if (r<li || ri<l) return -2e9;
	if (li<=l && r<=ri) return seg[t];
	int mid=(l+r)>>1;
	return max(maxi(t*2,l,mid,li,ri),maxi(t*2+1,mid+1,r,li,ri));
}
inline void WORKN()
{
	for (int i=0;i<=m;i++)
		for (int j=0;j<n;j++)
			for (int k=j;k<n;k++)
				for (int it=0;it<3;it++) dn[i][j][k][it]=-2e9;
	for (int j=0;j<n;j++)
		for (int k=j;k<n;k++) dn[0][j][k][0]=0;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=j;k<n;k++)
				dn[i+1][j][k][0]=max(dn[i+1][j][k][0],dn[i][j][k][0]+pc[i][k+1]-pc[i][j]);
			int pmx=dn[i][j][n-1][0];
			for (int k=n-2;k>=j;k--)
			{
				dn[i+1][j][k][1]=max(dn[i+1][j][k][1],pmx+pc[i][k+1]-pc[i][j]);
				//cout <<dn[i+1][j][k][1]<<" "<<pmx<<" ##\n";
				pmx=max(pmx,dn[i][j][k][0]);
			}
		}
		//cout <<i<<" ##\n";
		fill(seg,seg+4*n+5,-2e9);
		for (int j=0;j<n;j++)
		{
			for (int k=j;k<n;k++) add(1,0,n-1,k,dn[i][j][k][1]),cout <<k<<" "<<dn[i][j][k][1]<<" %%\n";
			for (int k=j;k<n;k++) dn[i+1][j][k][1]=max(dn[i+1][j][k][1],maxi(1,0,n-1,max(0,j-1),k));
		}
		for (int k=0;k<n;k++)
		{
			for (int j=0;j<=k;j++)
				dn[i+1][j][k][2]=max(dn[i+1][j][k][2],dn[i][j][k][2]+pc[i][k+1]-pc[i][j]);
			int pmx=-2e9;
			for (int j=k;j>=0;j--)
			{
				pmx=max(pmx,dn[i][j][k][1]);
				cout <<i<<" "<<j<<" "<<k<<" "<<pmx<<" "<<pmx+pc[i][k+1]-pc[i][j]<<" %%\n";
				dn[i+1][j][k][2]=max(dn[i+1][j][k][2],pmx+pc[i][k+1]-pc[i][j]);
			}
		}
		for (int j=0;j<n;j++)
			for (int k=j;k<n;k++)
				for (int it=0;it<3;it++)
					cout <<i<<" "<<j<<" "<<k<<" "<<it<<" "<<dn[i][j][k][it]<<" dn ##\n";
	}
	for (int i=0;i<m;i++) N[i]=-2e9;
	for (int i=1;i<=m;i++)
		for (int j=0;j<n;j++)
			for (int k=j;k<n;k++) N[i-1]=max(N[i-1],dn[i][j][k][2]);
	for (int i=1;i<m;i++) N[i]=max(N[i],N[i-1]);
	//cout <<"op\n";
}
inline void WORKO()
{
	for (int l=0;l<m;l++)
	{
		for (int r=l+2;r<m;r++)
		{
			O[l][r]=-2e9;
			int pmx=pr[0][r+1]-pr[0][l]+a[1][l]+a[1][r];
			for (int i=2;i<n;i++)
			{
				O[l][r]=max(O[l][r],pmx+pr[i][r+1]-pr[i][l]);
				pmx=max(pmx,pr[i-1][r+1]-pr[i-1][l])+a[i][l]+a[i][r];
			}
		}
	}
	for (int l=m-1;l>=0;l--)
		for (int r=l+3;r<m;r++)
			O[l][r]=max(O[l][r],max(O[l][r-1],O[l+1][r]));
}
inline void WORKI()
{
	for (int i=0;i<=m;i++)
		for (int j=0;j<n;j++)
			for (int k=j+2;k<n;k++)
				for (int it=0;it<3;it++) di[i][j][k][it]=-2e9;
	for (int j=0;j<n;j++)
		for (int k=j;k<n;k++) di[m][j][k][0]=0;
	for (int i=m-1;i>=0;i--)
	{
		for (int j=0;j<n;j++)
		{
			for (int k=j+2;k<n;k++)
			{
				di[i][j][k][0]=max(di[i][j][k][0],di[i+1][j][k][0]+a[j][i]+a[k][i]);
				di[i][j][k][1]=max(di[i][j][k][1],max(di[i+1][j][k][0],di[i+1][j][k][1])+pc[i][k+1]-pc[i][j]);
				di[i][j][k][2]=max(di[i][j][k][2],max(di[i+1][j][k][1],di[i+1][j][k][2])+a[j][i]+a[k][i]);
			}
		}
	}
	for (int i=0;i<m;i++) I[i]=-2e9;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			for (int k=j;k<n;k++) I[i]=max(I[i],di[i][j][k][2]);
	for (int i=m-2;i>=0;i--) I[i]=max(I[i],I[i+1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++)
	{
		pr[i][0]=0;
		for (int j=0;j<m;j++) pr[i][j+1]=pr[i][j]+a[i][j];
	}
	for (int i=0;i<m;i++)
	{
		pc[i][0]=0;
		for (int j=0;j<n;j++) pc[i][j+1]=pc[i][j]+a[j][i];
	}
	WORKN(),WORKO(),WORKI();
	int res=-2e9;
	for (int i=0;i<m;i++)
	{
		for (int j=i+6;j<m;j++)
		{
			cout <<i<<" "<<j<<" ------------------------------------\n"; 
			cout <<i<<" "<<N[i]<<" N ##\n";
			cout <<j<<" "<<I[j]<<" I ##\n";
			cout <<i+2<<" "<<j-2<<" "<<O[i+2][j-2]<<" O ##\n"; 
			res=max(res,N[i]+I[j]+O[i+2][j-2]);
		}
	}
	printf("%d",res);
	return 0;
}
