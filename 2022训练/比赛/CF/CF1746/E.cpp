#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
int i,j,n,s,t,m;
int ask(vector<int> e){
	printf("? %d ",e.size());
	for(auto v:e)printf("%d ",v);puts("");
	fflush(stdout);
	string str;cin>>str;
	return str[0]=='Y';
}
int answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
	string str;
	cin>>str;
	if(str[1]=='(')return 0;
	return 1;
}
vector<int> merge(vector<int> v1,vector<int> v2){
	vector<int> v;
	for(auto w:v1)v.push_back(w);
	for(auto w:v2)v.push_back(w);
	return v;
}
void solve(vector<int> v){
	if(v.size()<=2){
		if(answer(v[0]))return ;
		answer(v[1]);
		return ;
	}
	vector<int> v1,v2,v3;
	int len=v.size()/3;
	v1.insert(v1.begin(),v.begin(),v.begin()+len);
	v.erase(v.begin(),v.begin()+len);
	len=v.size()/2;
	v2.insert(v2.begin(),v.begin(),v.begin()+len);
	v.erase(v.begin(),v.begin()+len);
	v3=v;
	int p1=ask(v1),p2,p3;
	if(!p1){
		p2=ask(v1);
		if(!p2){
			solve(merge(v2,v3));
			return ;
		}
	} 
	p1=ask(v2);
	if(p1)solve(merge(v1,v2));
	else solve(merge(v1,v3));
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	vector<int> v;
	for(i=1;i<=n;i++)v.push_back(i);
	solve(v);
	return 0;
}


