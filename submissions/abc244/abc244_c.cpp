#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N, K, X;
    cin >> N >> K >> X;

    vector<ll> A(N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> cost[N];
    vector<ll> vec(K+1, INT_MAX);
    for(int i = 0; i < N; i++) cost[i] = vec;
    for(int i = 0; i < K+1; i++){
        cost[0][i] = max(A[0] - i * X, (ll)0);
        if(cost[0][i] == 0) break;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < K+1; j++){
            if(cost[i-1][j] == INT_MAX) continue;
            for(int k = 0; k <= K - j; k++){
                cost[i][j+k] = min(cost[i-1][j] + max(A[i] - k * X, (ll)0), cost[i][j+k]);
            }
        }
    }

    ll ans = INT_MAX;
    for(ll v: cost[N-1]){
        ans = min(ans, v);
    }
    cout << ans << endl;
    
    return 0;
}