#include<bits/stdc++.h>
using namespace std;
string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    int t[m+1][n+1];
    for(int i=0; i<=m; ++i) {
        t[i][0] = 0;
    }
    for(int i=1; i<=n; ++i) {
        t[0][i] = 0;
    }
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j) {
            if(str1[i-1]==str2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    cout<< t[m][n]<<endl;
    //traversing table
    int i=m, j=n;
    string scs = "";
    
    while(i>0 && j>0) {
        if(str1[i-1] == str2[j-1]){
            scs.push_back(str1[i-1]);
            --i;
            --j;
        }
        else {
            if(t[i-1][j] < t[i][j-1]){
                scs.push_back(str2[j-1]);
                --j;
            } else {
                scs.push_back(str1[i-1]);
                --i;
            }
        }
    }
    while(i>0){
        scs.push_back(str1[i-1]);
        --i;
    }
    while(j>0){
        scs.push_back(str2[j-1]);
        --j;
    }
    reverse(scs.begin(), scs.end());
    return scs;
}
