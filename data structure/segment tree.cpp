// 1.RMQ 

//node는 1번부터 시작, v의 idx는 0부터 시작
//int h = (int)ceil(log2(n));
//v.resize(n), tree.resize( 1<<(h+1) ); => 1<<(h+1)은 4*n으로 전부 커버

const int INT_MAX = numeric_limits<int>::max();
vector<int> v,tree;

int init(int node, int nodeLeft, int nodeRight) {
    //리프 노드: nodeLeft == nodeRight
	if(nodeLeft == nodeRight) return tree[node] = v[nodeLeft];
	else {
		int mid=(nodeLeft+nodeRight)/2;
        return tree[node] = min(init(node*2, nodeLeft, mid)
		,init(node*2+1, mid+1, nodeRight));
	}
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
	//node가 담당하는 구간: [nodeLeft, nodeRight]
    //구해야하는 최솟값의 범위: [left, right]
	if(nodeRight<left || right<nodeLeft) return INT_MAX;
	else if(left<=nodeLeft && nodeRight<=right) return tree[node];
    else {
    	int mid=(nodeLeft+nodeRight)/2;
        return min(query(node*2,nodeLeft,mid,left,right)
        ,query(node*2+1,mid+1,nodeRight,left,right));
    }
}

int update(int node, int nodeLeft, int nodeRight, int idx, int newVal) {
	//구간 밖이면 update없이 현재 노드를 반환 
	if(idx<nodeLeft || idx>nodeRight) return tree[node];
	//리프 노드인 경우 update
	if(nodeLeft == nodeRight) return tree[node]=newVal;
	
	int mid=(nodeLeft+nodeRight)/2;
	return tree[node] = min(update(node*2, nodeLeft, mid, idx, newVal)
	,update(node*2+1,mid+1, nodeRight, idx, newVal)); 
}



// 2.구간 합

typedef long long ll;
vector<ll> v,tree;

ll init(int node, int nodeLeft, int nodeRight) {
    //리프 노드: nodeLeft == nodeRight
	if(nodeLeft == nodeRight) return tree[node] = v[nodeLeft];
	else {
		int mid=(nodeLeft+nodeRight)/2;
		return tree[node] = init(node*2, nodeLeft, mid)
		+init(node*2+1, mid+1, nodeRight);
	}
}

ll sum(int node, int nodeLeft, int nodeRight, int left, int right) {
    //node가 담당하는 구간: [nodeLeft, nodeRight]
    //구해야하는 합의 범위: [left, right]
	if(nodeRight<left || right<nodeLeft) return 0;
	else if(left<=nodeLeft && nodeRight<=right) return tree[node];
    else {
    	int mid=(nodeLeft+nodeRight)/2;
        return sum(node*2,nodeLeft,mid,left,right)
        +sum(node*2+1,mid+1,nodeRight,left,right);
    }
}

//void update()
void update(int node, int nodeLeft, int nodeRight, int idx, ll diff) {
    //newVal:변경할 수, diff: Δv[idx]
    //diff = newVal-v[idx]
	if(idx<nodeLeft || idx>nodeRight) return;
	tree[node] += diff;
    //리프 노드가 아니면 자식도 update
	if(nodeLeft != nodeRight) {
		int mid=(nodeLeft+nodeRight)/2;
		update(node*2, nodeLeft, mid, idx, diff);
		update(node*2+1, mid+1, nodeRight, idx, diff);
	}
}

//ll update()
ll update(int node, int nodeLeft, int nodeRight, int idx, int newVal) {
    //구간 밖이면 update없이 현재 노드를 반환
	if(idx<nodeLeft || idx>nodeRight) return tree[node];
    //리프 노드를 newVal로 update
	if(nodeLeft==nodeRight) return tree[node] = newVal;

	int mid=(nodeLeft+nodeRight)/2;
	return tree[node] = update(node*2, nodeLeft, mid, idx, newVal)
	+update(node*2+1,mid+1, nodeRight, idx, newVal);
}







//lazy propagation
// 1. node 구조체를 만들고 val과 lazy를 관리
struct NODE {
	ll val,lazy;
};

vector<ll> v;
vector<NODE> tree;
int n,m,k,a,b,c;
ll d;

void propagation(int node,int l,int r) {
	if(tree[node].lazy != 0) { 
		tree[node].val += (ll)(r-l+1)*tree[node].lazy; 
		if(l != r) { 
			tree[node*2].lazy += tree[node].lazy;
			tree[node*2+1].lazy += tree[node].lazy; 
		}
		tree[node].lazy =0;
	}
}

ll init(int node,int l,int r) {
	if(l==r) return tree[node].val=v[l];
	int mid=(l+r)/2;
	return tree[node].val=init(2*node,l,mid)+init(2*node+1,mid+1,r);
}

void update(int node,int l,int r,int s,int e,ll diff) {
	propagation(node,l,r);
	if(e<l || s>r) return;
	if(s<=l && r<=e) {
		tree[node].val += (ll)(r-l+1)*diff;
		if(l!=r) {
			tree[2*node].lazy+=diff;
			tree[2*node+1].lazy+=diff;
		}
		return;
	}
	int mid=(l+r)/2;
	update(2*node,l,mid,s,e,diff);
	update(2*node+1,mid+1,r,s,e,diff);
	tree[node].val=tree[2*node].val+tree[2*node+1].val;
}

ll sum(int node,int l,int r,int s,int e) {
	propagation(node,l,r);
	if(e<l || s>r) return 0;
	if(s<=l && r<=e) return tree[node].val;
	int mid=(l+r)/2;
	return sum(2*node,l,mid,s,e)+sum(2*node+1,mid+1,r,s,e);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
	v.resize(n); tree.resize(4*n);
	for(int i=0; i<n; ++i) cin>>v[i];
	init(1,0,n-1);
	for(int i=0; i<m+k; ++i) {
		cin>>a;
		if(a==1) {
			cin>>b>>c>>d;
			b-=1; c-=1;
			update(1,0,n-1,b,c,d);
		}
		else {
			cin>>b>>c;
			b-=1; c-=1;
			cout<<sum(1,0,n-1,b,c)<<'\n';
		}
	}
	return 0;
}




//2. lazy배열을 따로 관리 
vector<ll> v,tree,lazy;
int n,m,k,a,b,c;
ll d;

void propagation(int node,int l,int r) {
	if(lazy[node] != 0) { 
		tree[node] += (r-l+1)*lazy[node]; 
		if(l != r) { 
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node]; 
		}
		lazy[node] =0;
	}
}

ll init(int node,int l,int r) {
	if(l==r) return tree[node]=v[l];
	int mid=(l+r)/2;
	return tree[node]=init(2*node,l,mid)+init(2*node+1,mid+1,r);
}

void update(int node,int l,int r,int s,int e,ll diff) {
	propagation(node,l,r);
	if(e<l || s>r) return;
	if(s<=l && r<=e) {
		tree[node] += (r-l+1)*diff;
		if(l!=r) {
			lazy[node*2]+=diff;
			lazy[node*2+1]+=diff;
		}
		return;
	}
	int mid=(l+r)/2;
	update(node*2,l,mid,s,e,diff);
	update(node*2+1,mid+1,r,s,e,diff);
	tree[node]=tree[node*2]+tree[node*2+1];
}

ll sum(int node,int l,int r,int s,int e) {
	propagation(node,l,r);
	if(e<l || s>r) return 0;
	if(s<=l && r<=e) return tree[node];
	int mid=(l+r)/2;
	return sum(node*2,l,mid,s,e)+sum(node*2+1,mid+1,r,s,e);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
	v.resize(n); tree.resize(4*n); lazy.resize(4*n);
	for(int i=0; i<n; ++i) cin>>v[i];
	init(1,0,n-1);
	for(int i=0; i<m+k; ++i) {
		cin>>a;
		if(a==1) {
			cin>>b>>c>>d;
			b-=1; c-=1;
			update(1,0,n-1,b,c,d);
		}
		else {
			cin>>b>>c;
			b-=1; c-=1;
			cout<<sum(1,0,n-1,b,c)<<'\n';
		}
	}
	return 0;
}
