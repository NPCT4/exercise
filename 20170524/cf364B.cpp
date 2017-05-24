#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;
const ll MOD=1e9+7;

int n,d;
int a[maxn];
int dp[maxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>d){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			for(int j=sum;j>=0;j--){
				if(j>=a[i]&&dp[j-a[i]]) dp[j]=1;
			}
		}
		int cnt=0;
		int now=0;
		while(1){
			int x=now;
			for(int i=now+d;i>=now+1;i--){
				if(dp[i]){
					x=i;break;
				}
			}
			if(x==now) break;
			now=x;cnt++;
		}
		cout<<now<<" "<<cnt<<endl;
	}
	return 0;
}


