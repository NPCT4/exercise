#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=100010;
const int INF=1e9+10;
const double EPS=1e-10;

char s[maxn];int n;
int K;
int val[26][26];
char x,y;int v,m;
int dp[120][26][120];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(~scanf("%s%d",s+1,&K)){
		n=strlen(s+1);
		scanf("%d",&m);
		memset(val,0,sizeof(val));
		while(m--){
			cin>>x>>y>>v;
			val[x-'a'][y-'a']=v;
		}
		for(int j=0;j<26;j++)
			for(int k=0;k<=K;k++)
				dp[1][j][k]=((k==0&&j!=s[1]-'a')?-INF:0);
		for(int i=2;i<=n;i++){
			for(int j=0;j<26;j++){
				for(int k=0;k<=K;k++){
					dp[i][j][k]=-INF;
					if(k==0&&j!=s[i]-'a') dp[i][j][k]=-INF;
					else{
						for(int w=0;w<26;w++){
							if(j==s[i]-'a')
								dp[i][j][k]=
									max(dp[i][j][k],
											dp[i-1][w][k]+val[w][j]);
							else
								dp[i][j][k]=
									max(dp[i][j][k],
											dp[i-1][w][k-1]+val[w][j]);
						}
					}
				}
			}
		}
		int res=-INF;
		for(int i=0;i<26;i++) res=max(res,dp[n][i][K]);
		cout<<res<<endl;
	}
	return 0;
}

