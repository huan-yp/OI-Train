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
		return (ts.tv_sec*1000000000+ts.tv_nsec*1000)/1000;
	}
	void Srand(int seed=-1){
		if(seed==-1){
            int t=getTimeNs()%(32767);
            cout<<t<<endl;
			srand(t);
		}
		else{
			Srand(seed);
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
	void puts(string a){
		outputer<<a<<endl;
	}
	void puts(char c){
		outputer<<c<<endl;
	}
	int mpint(int l,int r,string end=" "){
		int num=Rand(l,r);
		print(num,end);
		return num;
	}
	void set_outputer(int sub,int test,string suf=".in"){
		outputer=ofstr(sub,test,suf);
	}
    void print_perm(vector<int> perm,string end="\n",string gap=" ", int print_sz=0,string sz_gap="\n",int sz=-1){
        if(print_sz){
            if(sz!=-1)sz=perm.size();
            outputer<<sz<<sz_gap;
        }
        for(auto x:perm)
            outputer<<x<<gap;

        outputer<<end;
    }
    vector<int> gp_perm(int sz,string gap=" ",string end="\n",int print_sz=0,string sz_gap="\n"){
        vector<int> perm(0);
        for(int i=1;i<=sz;i++)
            perm.push_back(i);
        cout<<perm.size()<<endl;
        random_shuffle(perm.begin(),perm.end());
        print_perm(perm,end,gap,print_sz,sz_gap);
        return perm;
    }
    
}dm;

signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	dm.Srand();
	int lim=1e5,lim2=1e9;
	int sub=2;
	for(i=9;i<=9;i++){
		dm.set_outputer(sub,i);
		int level=dm.Rand(1,min(i*2,16));
		int vallim=min(1<<min(i*2,20),lim);
		n=dm.mpint(max(int(vallim*0.9),1),vallim,"\n");
		for(j=2;j<=n;j++){
			dm.mpint(max(1,j-5),j-1);
			// if(j>n/2){
			// 	if(i%2==0)
			// 		dm.mpint(1,j-1);
			// 	else
			// 		dm.mpint(max(j-int(sqrt(2*j)),1),j-1);
			// }
			// else{
			// 	dm.mpint(max(1,j-4),j-1);
			// }
			
			if(dm.Rand(0,1<<level)<=level){
				dm.puts("Y");
			}
			else{
				dm.puts("N");
			}
		}
    }
	return 0;
}


