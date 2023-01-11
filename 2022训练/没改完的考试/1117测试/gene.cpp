#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=1e5+10;
const int baseA=179,baseB=173;
const int modA=1000000021,modB=1000000033;
int i,j,k,m,n,s,t,cg,ct;
int pA[N]={1},pB[N]={1};
char ch[N],rch[N],trs[N];
class Hash{
	public:
	int A,B,len;
	bool operator ==(const Hash &a)const{return A==a.A&&B==a.B&&len==a.len;}
	Hash(char ch='\0'){
		len=ch!=0;
		A=B=ch;
	}
	Hash operator +(const Hash &a)const{
		Hash res=*this;
		res.len+=a.len;
		res.A=(1ll*res.A*pA[a.len]+a.A)%modA;
		res.B=(1ll*res.B*pB[a.len]+a.B)%modB;
		return res;
	}
	private:
	Hash& operator <<=(const int &x){
		A=1ll*A*pA[x]%modA;
		B=1ll*B*pB[x]%modB;
		return *this;
	}
	public:
	Hash operator -(Hash a)const{
		Hash res=*this;
		a<<=res.len-a.len;
		res.A-=a.A;res.A+=(res.A<0)*modA;
		res.B-=a.B;res.B+=(res.B<0)*modB;
		res.len-=a.len;
		return res;
	}
	Hash& operator +=(const Hash &a){return *this=*this+a;}
	Hash& operator -=(const Hash &a){return *this=*this-a;}
}lr[N],rl[N];
Hash get_rl(int l,int r){
	return rl[l]-rl[r+1];
}
Hash get_lr(int l,int r){
	return lr[r]-lr[l-1];
}
struct String{
	int l,r;
	String(int ll,int rr){
		l=ll,r=rr;
	}
	Hash get_hash(int len)const{
		if(len<=r-l+1)return get_rl(r-len+1,r);
		Hash base=get_rl(l,r);
		auto w=base+get_lr(r+1,l+len-1);
		return w;
	}
	char get_char(int x)const{
		if(x==n-l+2)return '\0';
		return x<=r-l+1?rch[r-x+1]:ch[l+x-1];
	}
	friend bool operator <(const String &a,const String &b){
		int l=1,r=n-a.l+1,res=0;
		while(r>=l){
			int mid=l+r>>1;
			if(a.get_hash(mid)==b.get_hash(mid))
			res=mid,l=mid+1;
			else 
			r=mid-1;
		}
		return a.get_char(res+1)<b.get_char(res+1);
	}
	bool operator >(const String &a)const{return a<*this;}
	bool operator ==(const String &a)const{return !(a<*this)&&!(*this<a);}
};
void solve(int x){
	int ans=x;
	for(i=x+1;i<=n;i++){
		if(String(x,i)<String(x,ans))
		ans=i;
	}
	string res="";
	for(i=1;i<x;i++)res+=ch[i];
	for(i=ans;i>=x;i--)res+=rch[i];
	for(i=ans+1;i<=n;i++)res+=ch[i];
	cout<<res<<endl;
}
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	scanf("%s",ch+1);
	trs['A']='T';trs['C']='G';trs['G']='C',trs['T']='A';
	n=strlen(ch+1);
	for(i=1;i<=n;i++)ct+=ch[i]=='T',cg+=ch[i]=='G',rch[i]=trs[ch[i]];
	for(i=1;i<=n;i++)pA[i]=1ll*pA[i-1]*baseA%modA,pB[i]=1ll*pB[i-1]*baseB%modB;
	for(i=1;i<=n;i++)lr[i]=lr[i-1]+Hash(ch[i]);
	for(i=n;i>=1;i--)rl[i]=rl[i+1]+Hash(rch[i]);
	if(ct+cg==0){
		ch[n]=rch[n];
		cout<<ch+1<<endl;
		return 0;
	}
	for(i=1;i<=n;i++){
		if(ch[i]>'A'&&ct)break;
		if(ch[i]>'C')break;
	}
	solve(i);
	return 0;
}

