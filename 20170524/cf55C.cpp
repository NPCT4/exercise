#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int x,y;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m>>k){
		bool flag=0;
		while(k--){
			scanf("%d%d",&x,&y);
			if(x<=5||x>=n-4||y<=5||y>=m-4)
				flag=1;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
