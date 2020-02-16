#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 1000010
using namespace std;

int n,a[MAX],pos,before[MAX],cur;
vector<int> v,y,idx;

int lis(int n) {
	FOR(i,n) {
		pos=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		if(pos==v.size()) {
			v.push_back(a[i]);
			idx.push_back(i);
		}
		else{
			v[pos]=a[i];
			idx[pos]=i;
		}
		if(pos>=1) before[i]=idx[pos-1];		
	}
	return v.size();
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(before,-1,sizeof(before));
	cin>>n;
	FOR(i,n) cin>>a[i];
	cout<<lis(n)<<'\n';
	cur=idx.back();
	while(cur!=-1) {
		y.push_back(a[cur]);
		cur=before[cur];
	}
	for(int i=y.size()-1;i>=0;--i) cout<<y[i]<<" ";
}
