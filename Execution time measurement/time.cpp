#include<bits/stdc++.h>
using namespace std;

int main() {
	long long sum=0;
	clock_t st,ed;
	st=clock();
	for(int i=0;i<10000;i++) for(int j=0;j<10000;j++) {
		++sum;
	}
	ed=clock();
	cout<<double(ed-st)<<"ms";
}
