#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1000000005
int n,m;
long long a[N];
int main(){
freopen ("random.in","r",stdin);
freopen ("random.out","w",stdout);
cin>>n>>m;
a[1]=1,a[n]=1;
int cnt=0;
if(m==1) cnt=2;
for(int i=2;i<n;i++){a[i]=(i-1)*(n-i+1);if(a[i]%m==0) cnt++;}
cout<<cnt<<endl;
for(int i=1;i<=n;i++)if(a[i]%m==0) cout<<i<<' ';
return 0;}