// reference: https://atcoder.jp/contests/abc263/editorial/4551
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N, L, R;
    cin >> N >> L >> R;

    ll A[N+1];
    for(int i = 1; i < N+1; i++) cin >> A[i];

    // op1
    vector<ll> op1(N+1, LONG_LONG_MAX);
    op1[0] = 0;
    for(ll i = 0; i < N; i++){
        op1[i+1] = min(op1[i] + A[i+1], L * (i + 1));
    }
    // op2
    vector<ll> op2(N+1, LONG_LONG_MAX);
    op2[0] = 0;
    for(ll i = 0; i < N; i++){
        op2[i+1] = min(op2[i] + A[N-i], R * (i + 1));
    }
    // ans
    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < N+1; i++){
        ll tmp = op1[i] + op2[N-i];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}