#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>
#include<ctime>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k;
int Rand()
{
	return (rand()<<15)+rand();
}
int main()
{
		freopen("animal10.in","w",stdout);
		int n=200000; printf("%d\n",n);
		srand((int)time(0));
		for (i=1;i<=n;++i) printf("%d ",Rand()%1000000+1);
}

