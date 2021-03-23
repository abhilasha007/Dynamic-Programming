#include<bits/stdc++.h>
using namespace std;

string printLCS(string text1, string text2) {
    int n = text1.size(); int m = text2.size();
    int** t = new int*[n+1];
    for(int i=0; i<=n; ++i){
        t[i] = new int[m+1];
    }
    for(int i=0; i<=n; ++i) {
        t[i][0] = 0;
    }
    for(int i=0; i<=m; ++i){
        t[0][i] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) {
            if(text1[i-1]== text2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    int i=n; 
    int j=m;
    string s = "";
    while(i > 0 && j > 0) {
        if(text1[i-1]==text2[j-1]){
            s.push_back(text1[i-1]);
            --i;
            --j;
        }
        else {
            if(t[i-1][j] < t[i][j-1]) {
                j--;
            }
            else {
                i--;
            }
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s1 = "acbcf";
    string s2 = "abcdaf";
    cout<< printLCS(s1, s2);
    return 0;
}
