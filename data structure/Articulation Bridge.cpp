#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 100010
using namespace std;
typedef pair<int,int> pii;

int n,m,id,res,discovered[MAX];
vector<int> adj[MAX];
vector<pii> cutAry;

int dfs(int here,int parent) {
	discovered[here]=++id;
	int ret=discovered[here];
	for(auto next : adj[here]) {
		if(next==parent) continue;
		if(discovered[next]==0) {
			int node=dfs(next,here);
			if(node>discovered[here]) {
				int mn=min(here,next);
				int mx=max(here,next);
				cutAry.push_back({mn,mx});
			}
			ret=min(ret,node);
		}
		else {
			if(ret>discovered[next]) {
				ret=discovered[next];
			}	
		}
	}
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
	cout<<cutAry.size()<<'\n';
	sort(cutAry.begin(),cutAry.end());
	FOR(i,cutAry.size()) cout<<cutAry[i].first<<" "<<cutAry[i].second<<'\n';
}
