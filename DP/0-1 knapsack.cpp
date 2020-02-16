// 1. 2차원 배열 + memoization 
#define INF 987654321
int n,k,w[101],v[101],cache[101][100001];

int dp(int n,int k) {
	if(k<0) return -INF;
	if(k==0||n==-1) return 0;
	int& ret=cache[n][k];
	if(ret!=-1) return ret;
	return ret=max(dp(n-1,k-w[n])+v[n],dp(n-1,k));
}

int main() {
	memset(cache,-1,sizeof(cache));
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>w[i]>>v[i];
	cout<<dp(n,k);
}



// 2. 1차원 배열 2개
#define FOR(i,n) for(int i=0;i<(n);++i)

int n, k, res,tmp[100005],d[100005],m,w,v;

int main() {
	cin >> n >> k;
	while (n--) {
		scanf("%d%d", &w, &v);
		for(int i=w;i<=k;++i) {
			tmp[i] = max(d[i], d[i - w] + v);
		}
		FOR(i, k + 1) d[i] = tmp[i];
		memest(tmp, 0 , sizeof(tmp)); 
	}
	cout << d[k];
}




// 3. 1차원 배열 1개
 
int n,k,w,v,d[100005];

int main() {
	cin>>n>>k;
	while(n--) {
		cin>>w>>v;
		for(int j=k;j>=w;--j) {
			d[j]=mdx(d[j],d[j-w]+v);
		}
	}
	cout<<d[k];
}
