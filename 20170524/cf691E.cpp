#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=120;
const int INF=1e9+10;
const ll MOD=1e9+7;

int n;ll K;
ll a[maxn];
struct Matrix{
	ll a[maxn][maxn];
	friend Matrix operator*(Matrix A,Matrix B){
		Matrix C;
		memset(C.a,0,sizeof(C.a));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]+10*MOD)%MOD;
		return C;
	}
};Matrix A;

int Cnt(ll x){
	int res=0;
	while(x){
		res+=x%2;
		x/=2;
	}
	return res;
}

void init(){
//	sort(a,a+n);
//	n=unique(a,a+n)-a;
//	cout<<"n="<<n<<endl;
//	for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Cnt(a[i]^a[j])%3==0) A.a[i][j]=1;
			else A.a[i][j]=0;
		}
	}
}

Matrix qpow(Matrix A,ll k){
	Matrix res;
	memset(res.a,0,sizeof(res.a));
	for(int i=0;i<n;i++) res.a[i][i]=1;
	while(k){
		if(k&1) res=res*A;
		A=A*A;
		k>>=1;
	}
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>K){
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		init();
		Matrix B=qpow(A,K-1);
		ll res=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				res=(res+B.a[i][j])%MOD;
		cout<<res<<endl;
	}
	return 0;
}
