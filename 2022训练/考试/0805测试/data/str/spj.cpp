#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(LL i=0;i<n;++i)
#define repn(i,n) for(LL i=1;i<=n;++i)
#define LL long long
#define pii pair <LL,LL>
#define pdd pair <double,double>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

ifstream fin, fout, fstd;
 ofstream fscore, freport;

 inline void quit(int score, const char *msg)
 {
 fscore << score;
 freport << msg;
 fin.close();
 fout.close();
 fstd.close();
 fscore.close();
 freport.close();
 exit(0);
 }

 string too_string(double x)
 {
   string ret=to_string(x);
   rep(i,4) ret.pop_back();
   return ret;
 }

 int main(int argc, char **argv)
 {
 fin.open(argv[1]);
 fout.open(argv[2]);
 fstd.open(argv[3]);
 int fullScore = atoi(argv[4]);
 fscore.open(argv[5]);
 freport.open(argv[6]);
 
 ios::sync_with_stdio(false);
 string s;fin>>s;
 string ans;fstd>>ans;
 int a,b,c;fout>>a>>b>>c;
 if(a<0||b<0||c<0||a+b+c!=s.size()) quit(0,"Wrong Answer Score = -114514");
 string aa=s.substr(0,a),bb=s.substr(a,b),cc=s.substr(a+b,c);
 reverse(aa.begin(),aa.end());reverse(bb.begin(),bb.end());reverse(cc.begin(),cc.end());
 string ss=aa+bb+cc;
 if(ss!=ans) 
 {
    quit(0,"Wrong Answer Score = -114514");
 }
 else quit(fullScore,"Accepted");
 

 return 0;
 }