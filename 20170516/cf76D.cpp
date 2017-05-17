#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const int maxn=1000100;
const int INF=1e9+10;

ull A,B,X,Y;
bool flag;

bool dfs(int now,int tag){
	if(now==-1) return tag==0;
	if(B&(1ULL<<now)){
		Y+=(1ULL<<now);
		if(tag){
			if(A&(1ULL<<now)) return 0;
			else{
				return dfs(now-1,1);
			}
		}
		else{
			if(A&(1ULL<<now)) return dfs(now-1,0);
			else return 0;
		}
	}
	else{
		if(tag){
			X+=(1ULL<<now);Y+=(1ULL<<now);
			if(A&(1ULL<<now)) return dfs(now-1,1);
			else return dfs(now-1,0);
		}
		else{
			if(A&(1ULL<<now)) return dfs(now-1,1);
			else return dfs(now-1,0);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>A>>B){
		X=0;Y=0;
		if(dfs(63,0)) cout<<X<<" "<<Y<<endl;
		else puts("-1");
	}
	return 0;
}
