#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;
const ll MOD=1e9+7;

int n;
ll fac[maxn],invfac[maxn];

ll qpow(ll n,ll k,ll p){
	ll res=1;
	while(k){
		if(k&1) res=(res*n)%MOD;
		n=(n*n)%MOD;
		k>>=1;
	}
	return res;
}

void init(){
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=(fac[i-1]*i)%MOD;
	for(int i=0;i<maxn;i++) invfac[i]=qpow(fac[i],MOD-2,MOD);
}

ll C(ll n,ll k){
	return (((fac[n]*invfac[k])%MOD)*invfac[n-k])%MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	init();
	while(~scanf("%d",&n)){
		printf("%lld\n",(2*C(2*n-1,n-1)-n+MOD)%MOD);
	}
	return 0;
}



