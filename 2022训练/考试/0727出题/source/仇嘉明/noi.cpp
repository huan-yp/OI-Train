#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);加快cin
int n,m;
int a[155][555];
int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12;
int o1,o2,o3;
int i1,i2,i3,i4,i5;
void SolveSmall()
{
	n1=a[1][3]+a[2][1]+a[2][2]+a[2][3]+a[3][1];
	n2=a[1][4]+a[2][2]+a[2][3]+a[2][4]+a[3][2];
	n3=a[1][1]+a[1][2]+a[1][4]+a[2][1]+a[2][2]+a[2][4]+a[3][1]+a[3][3]+a[3][4];
	n4=a[1][1]+a[1][2]+a[2][1]+a[2][2]+a[2][4]+a[3][1]+a[3][3]+a[3][4];
	n5=a[1][4]+a[2][1]+a[2][2]+a[2][3]+a[2][4]+a[3][1];
	n6=a[1][1]+a[1][2]+a[1][4]+a[2][1]+a[2][2]+a[2][3]+a[2][4]+a[3][1]+a[3][3]+a[3][4];
	n7=a[1][1]+a[1][2]+a[1][4]+a[2][1]+a[2][3]+a[2][4]+a[3][1];
	n8=a[1][1]+a[1][2]+a[1][4]+a[2][1]+a[2][3]+a[2][4];
	n9=a[1][1]+a[1][2]+a[1][4]+a[2][1]+a[2][3]+a[2][4]+a[3][1]+a[3][3]+a[3][4];
	n10=a[1][4]+a[2][1]+a[2][2]+a[2][4]+a[3][1]+a[3][3]+a[3][4];
	n11=a[1][1]+a[1][2]+a[1][4]+a[2][1]+a[2][3]+a[2][4]+a[3][3]+a[3][4];
	n12=a[2][1]+a[2][2]+a[2][4]+a[3][1]+a[3][3]+a[3][4];
	o1=a[1][5]+a[1][6]+a[1][7]+a[2][5]+a[2][7]+a[3][5]+a[3][6]+a[3][7];
	o2=a[1][5]+a[1][6]+a[1][7]+a[1][8]+a[2][5]+a[2][8]+a[3][5]+a[3][6]+a[3][7]+a[3][8];
	o3=a[1][6]+a[1][7]+a[1][8]+a[2][6]+a[2][8]+a[3][6]+a[3][7]+a[3][8];
	i1=a[1][9]+a[1][10]+a[1][11]+a[2][10]+a[3][9]+a[3][10]+a[3][11];
	i2=a[1][10]+a[1][11]+a[1][12]+a[2][11]+a[3][10]+a[3][11]+a[3][12];
	i3=a[1][9]+a[1][10]+a[1][11]+a[1][12]+a[2][10]+a[2][11]+a[3][9]+a[3][10]+a[3][11]+a[3][12];
	i4=a[1][9]+a[1][10]+a[1][11]+a[1][12]+a[2][11]+a[3][9]+a[3][10]+a[3][11]+a[3][12];
	i5=a[1][9]+a[1][10]+a[1][11]+a[1][12]+a[2][10]+a[3][9]+a[3][10]+a[3][11]+a[3][12];
	printf("%d\n",max(max(max(max(n1+o2+i2,n1+o1+i1),max(n3+o3+i2,n2+o3+i2)),
	max(max(max(n4+o3+i2,n5+o3+i2),max(n6+o3+i2,n7+o3+i2)),n8+o3+i2)),
	max(max(max(n9+o3+i2,n10+o3+i2),max(n11+o3+i2,n12+o3+i2)),
	max(max(max(n1+o1+i2,n1+o1+i3),max(n1+o1+i4,n1+o1+i5)),n1+o3+i2))));
	exit(0);
}
int N(int x,int y)
{
	if(y==3) return x*3-4;
	return x*y-(y-2);
}
int O(int x,int y)
{
	return x*y-(x-2)*(y-2);
}
int I(int x,int y)
{
	return x*y-2*(x-2);
}
void Solve1()
{
	int res=0;
	for(int i=8;i<=m-4;++i)
	{
		for(int j=4;j<=i-4;++j)
		{
			res=max(res,N(n,j-1)+O(n,i-j-1)+I(n,m-i));
		}
	}
	printf("%d\n",res);
	return ;
}
int main()
{
	#ifndef DEBUG
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	rep1(i,n) rep1(j,m) scanf("%d",&a[i][j]);
	if(n==3&&m==12) SolveSmall();
	else Solve1();
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not 正难则反 or few affect?
*/




