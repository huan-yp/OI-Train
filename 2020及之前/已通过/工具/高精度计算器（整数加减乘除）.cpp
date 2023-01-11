#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
#define itn int
using namespace std;
int k,n,s,t,m;
//此行以下是函数板子,时间复杂度O(log10(n)^2)，空间复杂度O(log10(n))
//此版本为压位版本，请使用M调整压位位数，T调整计算范围 (10^(T*log10(M)/2)为最大支持范围)
//时间复杂度O(T^2)，空间复杂度O(T)
//目前仅支持log10(M)为正整数的情况
//在T>4e18/M时乘法不保证一定正确 
//除法暂时只支持除数小于1e9的situation  
//FFT和NTT版本敬请期待
//作者：Mao_zx,欢迎转载 
namespace H_P
{
	const long long M=1e9,T=5000;
	int pw[10]={1,10,1e2,1e3,1e4,1e5,1e6,1e7,1e8};
	struct num{
		int op;
		long long t[T*2+1];
		num()
		{
			op=1; 
			for(int i=1;i<=T;i++)
			t[i]=0;
		}
	};
	int cmp(num aa,num bb)
	{
		int i;
		int pd=1;
		for(i=T;i>=1;i--)
		if(aa.t[i]!=bb.t[i])	
		{
			pd=aa.t[i]>bb.t[i];
			break;
		}
		return pd;
	} 
	num add(num aa,num bb)
	{
		int i;
		num ret;
		if(aa.op*bb.op==1)
		{
			ret.op=aa.op;
			for(i=1;i<=T;i++)
			ret.t[i]=aa.t[i]+bb.t[i];
		}
		else
		{
			if(aa.op==-1)
			swap(aa,bb);
			if(cmp(aa,bb))
			ret.op=1;
			else
			{
				ret.op=-1;
				swap(aa,bb);
			}
			for(i=1;i<=T;i++)
			{
				ret.t[i]=aa.t[i]-bb.t[i];
				if(ret.t[i]<0)
				ret.t[i]+=M,aa.t[i+1]-=1;
			}
		}
		for(i=1;i<=T;i++)
		if(ret.t[i]>=M)
		ret.t[i+1]++,ret.t[i]-=M;
		return ret;
	}
	num multi(num aa,num bb)
	{
		int i,j;
		num ret;
		ret.op=aa.op*bb.op;
		for(i=1;i<=T;i++)
		{
			if(aa.t[i]==0)
			continue;
			for(j=1;j<=T;j++)
			{
				ret.t[i+j-1]+=aa.t[i]*bb.t[j];
				ret.t[i+j]+=ret.t[i+j-1]/M;
				ret.t[i+j-1]%=M;
			}
		}
		return ret;
	}
	pair < num , long long >  division(num aa,long long bb)
	{
		num ret;
		long long r=0;
		if(bb==0)
		{
			printf("Error!!!\n");
			printf("The divisor mustn't be 0!\n");
			printf("Please press Enter to continue.\n");
			system("pause");
			return make_pair(ret,r); 
		}
		int tmp=(bb<0?-1:1);
		ret.op=tmp*aa.op; 
		if(bb<0)
		bb=-bb;
		for(int i=T;i>=1;i--)
		{
			aa.t[i]+=r*M;
			ret.t[i]+=aa.t[i]/bb;
			r=aa.t[i]%bb;
		}
		return make_pair(ret,r*aa.op);
	}
	void print(num aa)
	{
		if(aa.op==-1)
		putchar('-');
		int pd=0;
		int i=T;
		while(aa.t[i]==0&&i>1)
		i--;
		printf("%lld",aa.t[i]);
		i--;
		for(;i>=1;i--)
		{
			long long p=M/10;
			while(p!=1)
			{
				if(aa.t[i]/p==0)
				putchar('0');
				p/=10;
			}
			printf("%lld",aa.t[i]);
		}
		putchar('\n'); 
	}
	inline num read()
	{
		num ret;
		char a[T*9];
		int num=0;
		scanf("%s",a+1);
		int l=strlen(a+1);
		int pd=a[1]=='-';
		ret.op=(pd==1?-1:1);
		int i=l;
		int js=0;
		while(i>=1+pd)
		{
			js++;
			int cnt=0;
			int num=0;
			while(i>=1+pd&&cnt<9)
			{
				num=num+pw[cnt]*(a[i--]-'0'); 
				cnt++;
			}
			ret.t[js]=num;
		}
		return ret;
	}
}
//此行以上是板子函数
H_P :: num a;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	long long b;
	cin>>b;
	a=H_P :: read();
	pair < H_P :: num , long long >  ans;
	ans=H_P :: division(a,b);
	if(ans.second!=0)
	cout<<ans.second;
	else
	cout<<b;
	return 0;
}

