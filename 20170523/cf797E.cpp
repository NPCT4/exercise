#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=100010;
const int INF=1e9+10;
const double EPS=1e-10;

int n,q;
int a[maxn];
int p,k;
int dp[maxn][322];

int dfs(int p,int k){
	if(p>n) return 0;
	if(k>sqrt(1.0*n)+EPS) return dfs(p+a[p]+k,k)+1;
	int &res=dp[p][k];
	if(~res) return res;
	return res=dfs(p+a[p]+k,k)+1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<sqrt(1.0*n)+EPS;j++)
				dp[i][j]=-1;
		cin>>q;
		while(q--){
			scanf("%d%d",&p,&k);
			printf("%d\n",dfs(p,k));
		}
	}
	return 0;
}
