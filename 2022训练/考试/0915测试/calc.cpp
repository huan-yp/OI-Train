#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=4949;
const int base[]={0,2,3,5,7,8,10};
const int _e[]={0,0,1,3,5,7,8,10,12};
const int only[]={0,1,0,0,1,1,0,0,1};
int i,j,k,n,t,m,tp1,tp2;
char ch[N];
struct interval{
	int c,l,s;
	void legal(){
		if(l>8)throw "level difference over 8";
	}
	void print(){
		if(c)printf("+");else printf("-");
		int d=s-_e[l]+2;
		if(only[l]){
			char opt[]="{[@]}";
			if(d>=0&&d<=4)printf("%c",opt[d]);
		}
		else{
			char opt[]="{[<>]}";
			if(d>=0&&d<=5)printf("%c",opt[d]);
		}
		printf("%d",l);
	}
	bool operator ==(const interval &b){
		return c==b.c&&l==b.l&&s==b.s;
	}
};
struct note{
	char b;int f=0,l;
	friend interval operator -(const note &a,const note &b){
		interval res;res.c=0;
		res.l=(b.l-a.l)*7+(b.b-a.b);
		if(res.l>=0)res.c=1;res.l=abs(res.l)+1;
		res.s=(b.l-a.l)*12+((base[b.b-'A']+b.f)-(base[a.b-'A']+a.f));
		if(res.c==0)res.s=-res.s;
		return res;
	}
};
pair<char*,int> match_chars(char *c,const char* chs){
	int res=-1;
	for(int i=0;i<strlen(chs);i++)
	if(chs[i]==c[0])res=i;
	if(res==-1)throw "match faild";
	return make_pair(c+1,res);
}
pair<char*,note> match_note(char *c){
	note v;int res=0,times=0;
	tie(c,res)=match_chars(c,"ABCDEFG");v.b='A'+res;
	tie(c,res)=match_chars(c,"0123456789b#-");
	if(res==10)v.f=-1,tie(c,res)=match_chars(c,"0123456789-");
	if(res==11)v.f=1,tie(c,res)=match_chars(c,"0123456789-");
	if(res==0){v.l=0;return make_pair(c,v);}
	
	int x=0,f=1;
	if(res==12||res==10){
		f=-1;
		if(c[0]=='0')throw "extra -";
	}
	else x=res,times=1;
	while(c[0]>='0'&&c[0]<='9'){x=x*10+c[0]-48;c++,times++;}
	if(times>9)throw "too many numbers";v.l=x*f;
	return make_pair(c,v);
};
pair<char*,interval> match_interval(char* c){
	int l,s;interval v;
	tie(c,v.c)=match_chars(c,"-+");
	tie(c,s)=match_chars(c,"{[<@>]}");
	tie(c,l)=match_chars(c,"012345678");
	if(((2==s||s==4)&&only[l])||l==0||(!only[l]&&s==3))throw "illegal interval";
	v.l=l;
	if(only[l]){
		int add[]={-2,-1,0,0,0,1,2};	
		v.s=_e[l]+add[s];
	}
	else{
		int add[]={-2,-1,0,0,1,2,3};
		v.s=_e[l]+add[s];
	}
	return make_pair(c,v);
}
signed main()
{
// 	freopen("calc.in","r",stdin);
//	freopen("calc.out","w",stdout);
	while(~scanf("%s",ch)){
		note n1,n2;
		interval out,res;
		char* now=ch;
		try{
			tie(now,n1)=match_note(now);
			tie(now,tp1)=match_chars(now,"-");
			tie(now,n2)=match_note(now);
			tie(now,tp1)=match_chars(now,"=");
			tie(now,out)=match_interval(now);
			res=n1-n2;
			out.legal();res.legal();
			if(strlen(now)>0)throw "too many characters";
		}
		catch(const char *e){
			puts("Compile Error");
			continue;
		}
		if(out==res)puts("Accepted");
		else printf("Wrong Answer,excepted "),res.print(),puts("");
	}
	return 0;
}
