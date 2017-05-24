#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;
const ll MOD=1e9+7;

int n;
char s[maxn],t[maxn];
ll all[maxn],f[maxn],g[maxn],h[maxn];

void init(){
	all[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'&&t[i]=='?') all[i]=(all[i-1]*10*10)%MOD;
		else if(s[i]=='?'||t[i]=='?') all[i]=(all[i-1]*10)%MOD;
		else all[i]=all[i-1];
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'&&t[i]=='?') f[i]=(f[i-1]*55)%MOD;
		else if(s[i]=='?') f[i]=(f[i-1]*(t[i]-'0'+1))%MOD;
		else if(t[i]=='?') f[i]=(f[i-1]*('9'-s[i]+1))%MOD;
		else if(s[i]>t[i]) f[i]=0;
		else f[i]=f[i-1];
	}
	g[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'&&t[i]=='?') g[i]=(g[i-1]*55)%MOD;
		else if(s[i]=='?') g[i]=(g[i-1]*('9'-t[i]+1))%MOD;
		else if(t[i]=='?') g[i]=(g[i-1]*(s[i]-'0'+1))%MOD;
		else if(s[i]<t[i]) g[i]=0;
		else g[i]=g[i-1];
	}
	h[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'&&t[i]=='?') h[i]=(h[i-1]*10)%MOD;
		else if(s[i]=='?'||t[i]=='?'||s[i]==t[i]) h[i]=h[i-1];
		else h[i]=0;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		scanf("%s%s",s+1,t+1);
		init();
		printf("%lld\n",(all[n]-f[n]-g[n]+h[n]+MOD*10)%MOD);
	}
	return 0;
}

