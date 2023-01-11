#include<bits/stdc++.h>
using namespace std;
template<typename T1>
void read(T1 &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
const int N=2e5+10;
int i,j,k,m,n,s,t;
vector<int> v[N],a;
bool solve(){
	int lim=0;
	read(n),read(m);
	for(i=1;i<=n;i++){
		v[i].resize(m+5);
		for(j=1;j<=m;j++)
		read(v[i][j]);
	}
	for(k=1;k<=n;k++){
		a=v[k];int cnt=0;
		for(i=1;i<=m;i++)cnt+=a[i]<a[i-1];
		if(cnt){
			swap(v[1],v[k]);
			break;
		}
	}
	vector<int> p;
	a=v[1];
	sort(a.begin()+1,a.begin()+m+1);
	for(i=1;i<=m;i++)if(a[i]!=v[1][i])p.push_back(i);
	if(p.size()>2)return 0;	
	if(p.size()==0)return puts("1 1"), 1;
	for(k=1;k<=n;k++){
		a=v[k];
		swap(a[p[0]],a[p[1]]);
		for(i=2;i<=m;i++)if(a[i]<a[i-1])return 0;
	}
	printf("%d %d\n",p.front(),p.back());
	return 1;
}
int main(){
	int tot;read(tot);
	while(tot--){
		if(!solve())
		puts("-1");
	}
	return 0;
}
