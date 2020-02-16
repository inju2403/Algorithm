#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
#define MAX 10005
using namespace std;
typedef pair<int,int> pii;

int v,e,cost;

struct DisjointSet {
	vector<int> parent,depth;
	DisjointSet(int n): parent(n+1),depth(n+1) {
		for(int i=1;i<=n;++i) parent[i]=i;
	}
	int find(int x) {
		return parent[x] == x ? x : find(parent[x]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if(depth[a]==depth[b]) ++depth[a],parent[b]=a;
		else if(depth[a]<depth[b]) parent[a]=b;
		else parent[b]=a;
	}
};

struct Node {
	int u,v,w;
	bool operator <(Node &node) {
		return this->w < node.w;
	}
};
vector<Node> V;
vector<pii> Pairs;

void kruskal(int n,int m,vector<pii>& Pairs) {
	sort(V.begin(),V.end());
	DisjointSet sets(v+1);
	for(int i=0;i<V.size();++i) {
		int p=sets.find(V[i].u);
		int q=sets.find(V[i].v);
		if(p!=q) {
			sets.merge(p,q);
			cost+=V[i].w;
			Pairs.push_back(make_pair(V[i].u,V[i].v));
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>v>>e;
	for(int i=0;i<e;++i) {
		int u,v,w;
		cin>>u>>v>>w;
		Node node;
		node.u=u; node.v=v; node.w=w;
		V.push_back(node);
	}
	kruskal(v,e,Pairs);
	for(int i=0;i<Pairs.size();++i) cout<<Pairs[i].first<<" "<<Pairs[i].second<<'\n';
	cout<<cost;
}
