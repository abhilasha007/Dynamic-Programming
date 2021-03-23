// LRS = LCS(s, s) when checking equal make sure i!=j

/*Given a string, find the length of the longest repeating subsequence such that 
 the two subsequences don’t have same string character at the same position, 
 i.e., any i’th character in the two subsequences shouldn’t have the same index in 
 the original string.
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    int t[n+1][n+1];
		    for(int i=0; i<=n; ++i) t[i][0] = 0;
		    for(int i=1; i<=n; ++i) t[0][i] = 0;
		    
		    for(int i=1; i<=n; ++i){
		        for(int j=1; j<=n; ++j){
		            if(str[i-1]==str[j-1] && i!=j){ //
		                t[i][j] = 1 + t[i-1][j-1];
		            }
		            else {
		                t[i][j] = max(t[i][j-1], t[i-1][j]);
		            }
		        }
		    }
		    return t[n][n];
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}