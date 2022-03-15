#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, w;
    cin >> n >> w;

    int wi[n+1], vi[n+1];
    for(int i = 1; i < n+1; i++) cin >> wi[i] >> vi[i];

    ll dp[n+1][w+1];
    dp[0][0] = 0;
    for(int i = 1; i < w+1; i++) dp[0][i] = INT_MIN;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            if(j < wi[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-wi[i]]+vi[i], dp[i-1][j]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < w+1; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}