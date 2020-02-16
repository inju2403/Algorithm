#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 10005
using namespace std;

int n,m,id,a,b,inDegree[MAX],num[MAX],dp[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x) {
	num[x] = ++id;
	s.push(x);
	
	int parent=num[x];
	for(int i : adj[x]) {
		if(num[i]==0) parent=min(parent,dfs(i));
		else if(finished[i]==0) parent=min(parent,num[i]);
	}
	if(parent==num[x]) {
		vector<int> group;
		while(1) {
			int k=s.top(); s.pop();
			group.push_back(k); finished[k]=true;
			if(k==x) break;
		}
		SCC.push_back(group);
	}
	return parent;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	FOR(i,m) {
		cin>>a>>b;
		adj[b].push_back(a);
	}
	FORS(i,1,n+1) if(num[i]==0) dfs(i);
	
}
