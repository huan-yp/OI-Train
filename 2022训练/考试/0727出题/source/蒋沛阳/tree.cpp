#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define ll long long
#define pii pair<int,int>
using namespace std;
template<typename T>inline void chmax(T &a,T b){a=max(a,b);}
template<typename T>inline void chmin(T &a,T b){a=min(a,b);}
const int maxn=2e5+10;
int n,a[maxn],b[maxn];
map<int,int>m1,m2;
bool uk[maxn];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		m1[a[i]]=i;
		uk[i]=true;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",b+i);
		m2[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		a[i]=m2[a[i]];
		b[i]=m1[b[i]];
	}
	double ans=(double)n;
	for(int i=1;i<n;i++){
		if(b[i]>b[i+1]){
			ans+=1.5;
			uk[i]=false;
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]<a[i+1]-1){
			for(int j=a[i];j<a[i+1];j++){
				if(uk[j]){
					ans+=0.5;
					uk[j]=false;
				}
			}
		}
	}
	printf("%0.6f\n",ans/2.0);
	return 0;
}
/*
Basic:
1. int or long long?
2. freopen?
3. memory limits?
Advanced:
1. use more functions
2. write carefully and check
3. think twice before writing
4. debug quickly
5. never copy others' codes
*/
