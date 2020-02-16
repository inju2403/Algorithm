struct DisjointSet {
	vector<int> parent,rank;

    //생성자로 부모를 자기 자신으로 초기화
	DisjointSet(int n): parent(n+1),rank(n+1) {
		for(int i=1;i<=n;++i) parent[i]=i;
	}

    //부모를 찾는다.
	int find(int x) {
		return parent[x] == x ? x : find(parent[x]);
	}
    
    //부모를 합친다.
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if(a == b) return;
        //a가 v보다 rank가 낮도록 설정
        if(rank[a] > rank[v]) swap(a,b);
        parent[a] = v;
        if(rank[a] == rank[b]) ++rank[v];
	}
};



//번호가 낮은 노드로 union하도록 구현한 union-find 
int getParent(int x) {
	return x==parent[x]? x : getParent(parent[x]);
}

void merge(int a,int b) {
	a=getParent(a); b=getParent(b);
	a<b? parent[b]=a : parent[a]=b; 
}

int main() {
	for(int i=1; i<=n ; ++i) parent[i]=i;
} 
