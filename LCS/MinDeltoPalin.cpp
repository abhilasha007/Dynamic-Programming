// Minimum deletions to make string palindrome = m - LPS
/**
 Given a string of S as input. Your task is to write a program to remove or delete minimum number of 
 characters from the string so that the resultant string is palindrome.
**/

#include<bits/stdc++.h>
using namespace std;

int minDeletes(string str) {
    int m = str.length();
    string s1 = str;
    reverse(str.begin(), str.end());
    string s2 = str;
    
    int t[m+1][m+1];
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int i=1; i<=m; ++i) t[0][i] = 0;
    
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=m; ++j) {
            if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];
            else
            t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }
    return m - t[m][m];
}

int main()
{
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    cout<< minDeletes(str)<<endl;
	}
	return 0;
    
}