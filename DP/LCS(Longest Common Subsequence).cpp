#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 1005
using namespace std;

int d[MAX][MAX],i,j;
bool c[MAX][MAX];
string a,b;
vector<char> v;

int main() {
	cin>>a>>b;
	int x=a.length();
	int y=b.length();
	FORS(i,1,x+1) FORS(j,1,y+1) {
		d[i][j]=max({d[i-1][j],d[i][j-1],d[i-1][j-1]+(a[i-1]==b[j-1])});
	}
	cout<<d[x][y]<<'\n';
	while(d[x][y]) {
		if(d[x][y]==d[x-1][y]) --x;
		else if(d[x][y]==d[x][y-1]) --y;
		else {
			v.push_back(a[x-1]);
			--x,--y;
		}
	}
	reverse(v.begin(),v.end());
	FOR(i,v.size()) cout<<v[i];
}

// adding more problem based on lcs like longest palindrome 
#include<stdio.h> 
#include<string.h> 
  
 
int max (int x, int y) { return (x > y)? x : y; } 
  
// Returns the length of the longest palindromic subsequence in seq 
int lps(char *str) 
{ 
   int n = strlen(str); 
   int i, j, cl; 
   int L[n][n];  // Create a table to store results of subproblems 
  
  
   
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
} 
  
 
int main() 
{ 
    char seq[] = "GEEKS FOR GEEKS"; 
    int n = strlen(seq); 
    printf ("The length of the LPS is %d", lps(seq)); 
    getchar(); 
    return 0; 
} 
