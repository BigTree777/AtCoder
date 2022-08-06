#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N, L, R;
    cin >> N >> L >> R;

    ll A[N];
    ll sumA[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i != 0) sumA[i] = sumA[i-1] + A[i];
        else sumA[i] = A[i];
    }

    ll ans = INT_MAX;
    ll part_sumA;
    ll op1, op2;
    vector<ll> dp(N+1, INT_MAX);
    for(ll i = 0; i < N+1; i++){
        op1 = L * i; // op1
        // 毎回計算しているためTLE
        for(ll j = 0; j < N - i; j++){
            op2 = R * j; // op2
            if(i != 0) part_sumA = sumA[N-j-1] - sumA[i-1]; // No Change
            else part_sumA = sumA[N-j-1]; // No Change
            dp[i] = min(dp[i], op1 + op2 + part_sumA);
        }
        if(i == N) dp[i] = min(dp[i], op1);
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}