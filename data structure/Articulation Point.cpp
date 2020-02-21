#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 10010
using namespace std;

int n,m,id,res,discovered[MAX];
bool cut[MAX];
vector<int> adj[MAX],cutAry;

int dfs(int here,bool isRoot) {
	discovered[here]=++id;
	int child=0;
	int ret=discovered[here];
	for(auto next : adj[here]) {
		if(discovered[next]==0) {
			++child;
			int node=dfs(next,0);
			if(!isRoot && node >= discovered[here]) cut[here]=1;
			ret=min(ret,node);
		}
		else ret=min(ret,discovered[next]);
	}
	if(isRoot && child>=2) cut[here]=1;
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	FOR(i,m) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	FORS(i,1,n+1) if(discovered[i]==0) dfs(i,1);
	FORS(i,1,n+1) if(cut[i]) ++res, cutAry.push_back(i);
	cout<<res<<'\n';
	FOR(i,cutAry.size()) cout<<cutAry[i]<<" ";
}
