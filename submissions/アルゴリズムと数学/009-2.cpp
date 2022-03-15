#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, s;
    cin >> n >> s;
    int a[n+1];
    for(int i = 1; i < n+1; i++) cin >> a[i];

    int dp[n+1][s+1];
    dp[0][0] = 1;
    bool ans = false;
    for(int i = 1; i < s+1; i++) dp[0][i] = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < s+1; j++){
            if(j < a[i]) dp[i][j] = dp[i-1][j];
            else{
                if(dp[i-1][j-a[i]]==1) dp[i][j] = 1;
                else if(dp[i-1][j]==1) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        if(dp[i][s]==1){
            ans = true;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}