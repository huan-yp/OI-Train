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

struct data_maker{
	ofstream outputer;
	long long getTimeNs(){
	    struct timespec ts;
	    clock_gettime(CLOCK_REALTIME,&ts);
		return ts.tv_sec*1000000000+ts.tv_nsec;
	}
	void srand(int seed=-1){
		if(seed==-1){
			srand(getTimeNs());
		}
		else{
			srand(seed);
		}
	}
	int Rand(int l,int r){
		return (rand()|(1ll<<15)*rand()|(1ll<<30)*rand()|(1ll<<45)*rand())%(r-l+1)+l;
	}
	static auto ifstr(int sub,int test,string suf=".in"){
		return ifstream(to_string(sub)+"-"+to_string(test)+suf);
	}
	static auto ofstr(int sub,int test,string suf=".in"){
		return ofstream(to_string(sub)+"-"+to_string(test)+suf);
	}
	void print(int a,string end=" "){
		outputer<<a<<end;
	}
	void print(string a,string end="\n"){	
		outputer<<a<<end;
	}
	int mpint(int l,int r,string end=" "){
		int num=Rand(l,r);
		print(Rand(l,r),end);
		return num;
	}
	void set_outputer(int sub,int test,string suf=".in"){
		outputer=ofstr(sub,test,suf);
	}
}dm;

signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	
	int lim=1e5,lim2=1e9;
	int sub=3;
	for(i=21;i<=25;i++){
		dm.set_outputer(sub,i);
		t=dm.mpint(lim/(1+i%3),lim);
		if(i%3==1){
			dm.mpint(t,t*10);
		}
		if(i%3==2){
			dm.mpint(lim2/10,lim2);
		}
		if(i%3==0){
			dm.mpint(t/2,t);
		}
	}
	return 0;
}


