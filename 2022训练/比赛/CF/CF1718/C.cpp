#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=3e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N][2];
vector<int> e[N];
//multiset<int> st;
struct Multiset{
	priority_queue<int> q1,q2;
	void clear(){
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
	}
	void ready(){
		while(!q2.empty()&&q1.top()==q2.top())q1.pop(),q2.pop();
	}
	int rbegin(){
		ready();
		return q1.top();
	}
	void erase(int x){
		q2.push(x);
	}
	void insert(int x){
		q1.push(x);
	}
}st;
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(k);
		st.clear();vector<int> v(0);m=n;
		for(i=2;i*i<=m;i++)if(m%i==0){
			v.push_back(n/i);
			do m/=i; while(m%i==0);
		}
		for(i=1;i<=n;i++)
		read(a[i]);	
		if(m!=1)v.push_back(n/m);
		for(auto x:v){
			e[x].resize(x+5);
			for(j=1;j<=x;j++){
				int val=0;
				for(i=j;i<=n;i+=x){
					val+=a[i];
				}
				e[x][j]=val;
				st.insert(e[x][j]*(x));
			}
		}
		cout<<st.rbegin()<<endl;
		for(i=1;i<=k;i++){
			int p,val;
			read(p),read(val);
			int inc=val-a[p];a[p]=val;
			for(auto x:v){
				int rp=(p-1)%x+1;
				st.erase(e[x][rp]*(x));
				e[x][rp]+=inc;
				st.insert(e[x][rp]*(x));
			}
			cout<<st.rbegin()<<endl;
		}
	}
	return 0;
}


