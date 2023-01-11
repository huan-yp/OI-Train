#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(register int i=j;i<=k;++i)
#define g(i,j,k) for(register int i=j;i>=k;--i)
int n,m,s,l;
const double _=1;
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    f(i,1,n)scanf("%lld",&m);
    f(i,1,n)scanf("%lld",&m);
    return printf("%lf\n",_*(n-1)*(n+2)/2/(n-1)),0;
}
/*
CompileRun 涂竣博/tree.cpp
5
1 2 3 4 5
1 2 3 4 5

*/