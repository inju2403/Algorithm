// ¿­Ç÷°­È£ 5 
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#include<tuple>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX_N 400
#define MAX_V 2*(MAX_N+1)
#define src MAX_V-2
#define sink MAX_V-1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

int n,m,res,can,work,price,total,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V],cost[MAX_V][MAX_V];
vector<int> adj[MAX_V];


int main() {
	cin>>n>>m;
	
	FORS(i,1,n+1) {
		scanf("%d",&can);
		FOR(j,can) {
			scanf("%d%d",&work,&price);
			adj[i].push_back(work+MAX_N);
			adj[work+MAX_N].push_back(i);
			
			cost[i][work+MAX_N]=price;
			cost[work+MAX_N][i]=-price;
			capacity[i][work+MAX_N]=1;
		}
	}
	
	FORS(i,1,n+1) {
		capacity[src][i]=1;
		adj[src].push_back(i);
		adj[i].push_back(src);
	}
	FORS(i,1,m+1) {
		capacity[i+MAX_N][sink]=1;
		adj[i+MAX_N].push_back(sink);
		adj[sink].push_back(i+MAX_N);
	}
	
	
	while(true) {
		vector<int> parent(MAX_V,-1);
		vector<int> upper(MAX_V,INF);
		vector<bool> inQ(MAX_V,0);
		queue<int> q;
		upper[src]=0;
		inQ[src]=true;
		q.push(src);
		
		while(!q.empty()) {
			int here=q.front(); q.pop();
			inQ[here]=false;
			for(int there: adj[here]) {
				if(capacity[here][there]-flow[here][there]>0 && upper[there]>upper[here]+cost[here][there]) {
					upper[there]=upper[here]+cost[here][there];
					parent[there]=here;
					if(!inQ[there]) {
						q.push(there);
						inQ[there]=true;
					}
				}
			}
		}
		if(parent[sink]==-1) break;
		
		for (int p=sink;p!=src;p=parent[p]) {
			res+=cost[parent[p]][p];
			++flow[parent[p]][p];
			--flow[p][parent[p]];
		}
		++total;
	}
	cout<<total<<'\n'<<res;
}
