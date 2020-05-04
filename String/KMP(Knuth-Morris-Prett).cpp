#include<iostream>
#include<vector>
#include<string>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
using namespace std;

string a,b;

vector<int> getPi(const string& s) {
	int sz=s.size();
	vector<int> pi(sz,0);
	int j=0;
	FORS(i,1,sz) {
		while(j>0 && s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) pi[i]=++j;
	}
	return pi;
}

vector<int> KMP(const string& H, const string& N) {
	int n=H.size(), m=N.size();
	vector<int> ret;
	vector<int> pi=getPi(N);
	int j=0;
	FOR(i,n) {
		while(j>0 && H[i]!=N[j]) j=pi[j-1];
		if(H[i]==N[j]) {
			if(j==m-1) {
				ret.push_back(i-(m-1));
				j=pi[j];	
			}
			else ++j;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	getline(cin,a);
	getline(cin,b);
	vector<int> res=KMP(a,b);
	cout<<res.size()<<'\n';
	FOR(i,res.size()) cout<<res[i]<<" ";
}
