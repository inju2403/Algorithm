//번호가 낮은 노드로 union하도록 구현한 union-find 

#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)

struct node {
	int u,v,w;
	bool operator < (const node &arg) const {
		return w<arg.w;
	}
};
vector<node> vec;

int getParent(int x) {
	return x==parent[x]? x : parent[x] = getParent(parent[x]);
}

void merge(int a,int b) {
	a=getParent(a); b=getParent(b);
	a<b? parent[b]=a : parent[a]=b; 
}

int main() {
	FORS(i,1,n+1) parent[i]=i;
	FOR(i,m) {
		int a,b,c;
		cin>>a>>b>>c;
		vec.push_back({a,b,c});
	}
	//간선의 비용이 작은 순서대로 정렬
	sort(vec.begin(),vec.end());
	FOR(i,vec.size()) {
		if(getParent(vec[i].u)!=getParent(vec[i].v)) {
			merge(vec[i].u,vec[i].v);
			total+=vec[i].w;
		}
	}
	cout<<total;
} 
