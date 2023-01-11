#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,s) for(register int i=j;i<=s;++i)
#define g(i,j,s) for(register int i=j;i>=s;--i)
int n,m,s,l;
int a[20];
int b[20];
int c[20][101010];
queue<int>ans;
signed main(){
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		f(i,1,n)ans.push(i);
	}else{
		for(register int i=2;i*i<=m;++i)if(!(m%i)){
	    	a[++s]=i;
			for(;!(m%i);m/=i)++b[s];
	    }
		if(m>1){
			a[++s]=m;b[s]=1;
		}
		// f(i,1,s)cout<<a[i]<<" ";cout<<endl;
		// f(i,1,s)cout<<b[i]<<" ";cout<<endl;
		f(i,1,s)f(j,1,n)c[i][j]=c[i][j/a[i]]+j/a[i];
		f(i,1,n){
			l=1;
			f(j,1,s)l&=(b[j]<=c[j][n-1]-c[j][i-1]-c[j][n-i]);
			if(l)ans.push(i);
		}
	}
	printf("%lld\n",ans.size());
	while(ans.size()){
		printf("%lld ",ans.front());
		ans.pop();
	}
	return putchar('\n'),0;
}
/*
CompileRun 涂竣博\random.cpp
10 1
CompileRun 涂竣博\random.cpp
3 2
CompileRun 涂竣博\random.cpp
7 12

*/