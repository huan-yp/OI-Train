#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=5e5+10;
int i,j,k,m,n,s,t;
struct opponent{
	int s,rk;
	bool operator <(const opponent &a){
		return s<a.s;
	}
}a[N];
bool cmp(const opponent &a,const opponent &b){
	return a.rk<b.rk;
} 
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);
		int cnt=0,s=0,cnt2=-1;
		a[n+1].s=1e9;
		for(i=1;i<=n;i++)read(a[i].s),a[i].rk=i;	
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			s+=a[i].s;if(s>m)break;
			cnt++;
		}
		sort(a+1,a+n+1,cmp);
		s=a[cnt+1].s;
		sort(a+1,a+n+1);
		if(m>=s){
			cnt2=1;
			for(i=1;i<=n;i++){
				if(a[i].rk==cnt+1)continue;
				s+=a[i].s;if(s>m)break;
				cnt2++;
			}
		}
		sort(a+1,a+n+1,cmp);
		cout<<min(n-cnt+1,n-cnt2)<<endl;
	}
	return 0;
} 
