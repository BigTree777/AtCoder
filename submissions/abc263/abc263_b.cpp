#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;

    ll P[N+1];
    for(ll i = 2; i < N+1; i++) cin >> P[i];

    ll idx = N;
    ll ans = 0;
    ll now = P[idx];
    while(1){
        now = P[idx];
        ans++;
        if(now == 1) break;
        idx = now;
    }
    cout << ans << endl;
    return 0;
}