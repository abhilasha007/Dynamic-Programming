// LCSubStr = LCS, in else case t[i][j] = 0; maintain max variable

//Find length of longest common substring of 2 strings, i.e., lcs that is continuous 
#include<bits/stdc++.h>
using namespace std;
int LCsubstring(string S1, string S2){
    int n = S1.length(), m = S2.length();
    int** t = new int*[n+1];
    for(int i=0; i<=n; ++i){
        t[i] = new int[m+1];
    }
    int result = 0;
    for(int i=0; i<=n; ++i) {
        t[i][0] = 0;
    }
    for(int i=0; i<=m; ++i){
        t[0][i] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(S1[i-1]==S2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                result = max(result, t[i][j]);
            }
            else {
                t[i][j] = 0;
            }
        }
    }
    return result;
}

int main() {

} 