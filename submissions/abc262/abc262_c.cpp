#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;

    ll a[N+1];
    for(ll i = 1; i < N+1; i++) cin >> a[i];

    ll ans = 0;
    vector<ll> new_a;
    for(ll i = 1; i < N+1; i++){
        if(a[i] == i) new_a.push_back(i); // a[i] = i
        else if((a[i] > i)  && (a[a[i]] == i)) ans++; // a[j] = i
    }
    if(new_a.size() != 0) ans += (ll)(0.5 * (float)new_a.size() * (float)(new_a.size() - 1));
    cout << ans << endl;
    return 0;
}