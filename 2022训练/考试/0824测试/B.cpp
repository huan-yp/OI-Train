#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
int i,j,k,n,s,t,m,tp1,tp2;
int ans[255];
struct bitnum{
	LL num;
	set<string> st;
	bitnum(int x){
		num=x;
		st.clear();
		st.insert(""s+(char('0'+x)));
		st.insert(""s);
	}
	bitnum(LL x,const set<string> &s){
		num=x;st=s;
	}
	friend bool operator <(const bitnum &a,const bitnum &b){
		return a.num<b.num;
	}
};
set<bitnum> nums;
signed main()
{
 	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(k);
	nums.insert(bitnum(1)),nums.insert(bitnum(0));

	for(i=1;i<n;i++){
		set<bitnum> tp;
		for(auto [num,st]:nums){
			for(LL op=0;op<=1;op++){
				set<string> strs;
				for(auto str:st){
				//	cout<<str<<"->";
					auto nstr=str+char('0'+op);
				//	cout<<nstr<<' ';
					strs.insert(nstr);
					strs.insert(str);
					if(strs.size()>k+1)break;
				}
				if(strs.size()<=k+1)
				tp.insert(bitnum{num<<1|op,strs});
			//	puts("");
			}
		}
		swap(nums,tp);
	}
	for(auto [num,strs]:nums){
		ans[strs.size()-1]++;
	}
	for(i=1;i<=k;i++)
	cout<<ans[i]<<' ';
	puts("");
	return 0;
}


