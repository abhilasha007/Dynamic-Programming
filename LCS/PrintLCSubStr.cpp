// Print longest common substring
#include<bits/stdc++.h>
using namespace std;

string printLCSS(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    //Making 2D grid of (m+1) x (n+1)
    int t[n+1][m+1];
    
    //Initialization
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int i=1; i<=n; ++i) t[0][i] = 0;

    // Filling iteratively
    int len = 0;
    int row, col;
    for(int i=0; i<=m; ++i){
        for(int j=0; j<=n; ++j){
            if(X[i-1]==Y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                if(t[i][j] > len){
                    len = t[i][j];
                    row = i;
                    col = j;
                }
            } else {
                t[i][j] = 0;
            }
        }
    }
    string result = "";
    while(t[row][col]!=0){
        result.push_back(X[row-1]);
        --row;
        --col;
    }
    reverse(result.begin(), result.end());
    result.push_back('s');
    return result;
}

int main() {
    string X = "abcde";
    string Y = "abfce";
    cout<< "Logest Common Substring is" << printLCSS(X,Y);
    return 0;
}