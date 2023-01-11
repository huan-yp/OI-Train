#include<bits/stdc++.h>
#include "D.h"
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define vi vector<int> 
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
vector<pii> ans;
vi operator -(const vi &a,const vi &b){
	vi res=a;
	for(auto w:b)res.erase(find(res.begin(),res.end(),w));
	return res;
}
vi operator +(const vi &v1,const vi &v2){
	vi res=v1;
	res.insert(res.end(),v2.begin(),v2.end());
	return res;
}
vi operator +(const vi &v1,int v2){
	vi res=v1;
	res.push_back(v2);
	return res;
}
vi operator -(const vi &v1,int v2){
	vi res=v1;
	res.erase(find(res.begin(),res.end(),v2));
	return res;
}
int solve(vi v,int x){
	if(v.size()==1){
		ans.emplace_back(v[0],x);
		return v[0];
	}
	int mid=v.size()/2;
	vi l=vi(v.begin(),v.begin()+mid),r=vi(v.begin()+mid,v.end());
	if(ask(l+1,x))return solve(l,x);
	else return solve(r,x);	
}
vector<pii> work(int n){
	vi p,v,all;
	for(i=1;i<=n;i++)all.push_back(i);
	for(i=2;i<=n;i++)if(!ask(all-i,i))
	v.push_back(i);
	for(i=2;i<=n;i++)if(find(v.begin(),v.end(),i)==v.end()){
		auto b=p.begin();
		int l=0,r=p.size()-1,res=-1;
		while(r>=l){
			int mid=(l+r)/2;
			if(ask(vi(b+mid,p.end())+1,i))
			res=mid,l=mid+1;
			else
			r=mid-1;
		}
		p.insert(b+res+1,i);
	}
	auto b=p.begin();
	while(b!=p.end()){
		vi v2;auto now=b;
		while(b!=p.end()&&!ask(vi(now,p.end())-*b+1,*b))
		v2.push_back(*(b++));
		for(auto w:v2){
			while(ask(v+1,w)){
				int res=solve(v,w);
				v.erase(find(v.begin(),v.end(),res));
			}
		}
		v=v+v2;
	}
	for(auto w:v)ans.emplace_back(w,1);
	return ans;
}
