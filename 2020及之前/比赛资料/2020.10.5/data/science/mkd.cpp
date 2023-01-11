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
map<int,int>mp;
int Rand()
{
		return (rand()<<15)+rand();
}
int main()
{
	  freopen("science.in","w",stdout);
	  srand((int)time(0));
	  int n=5,m=10;
	  printf("%d %d\n",n,m); 
	  for (i=1;i<=n;++i)
	  {
	  		int x=Rand()%10-5;
	  		while (mp[x]) x=Rand()%10-5;
			printf("%d ",x);
			mp[x]=1; 
	  }
	  puts("");
	  for (i=1;i<=n;++i) printf("%c",(Rand()&1)?'L':'R'); 
	  puts("");
	  for (;m--;)
	  	  printf("%d %d\n",Rand()%n+1,Rand()%10); 
}

