#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 32005
using namespace std;

int n,m,inDegree[MAX];
bool chk;
vector<int> adj[MAX];
vector<int> v;

void topologySort() {
	queue<int> q;
	FORS(i,1,n+1) if(inDegree[i]==0) q.push(i);
	FORS(i,1,n+1) {
		if(q.empty()) {
			//사이클 발생
			chk=1;
			break;
		}
		int cur=q.front(); q.pop();
		v.push_back(cur);
		for(auto next:adj[cur]) {
			if(--inDegree[next]==0) q.push(next);
		}
	}
	if(chk) cout<<0; // 사이클 발생
	else FOR(i,v.size()) cout<<v[i]<<" ";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	FOR(i,m) {
		int a,b;
		cin>>a>>b;
		inDegree[b]++;
		adj[a].push_back(b);
	}
	topologySort();
}
