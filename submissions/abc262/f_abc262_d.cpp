#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N;
    cin >> N;

    ll a[N];
    bool isOdd[N];
    for(ll i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] % 2 == 1) isOdd[i] = true;
    }

    ll ans = 0;
    ll odd, bit;
    for(ll i = 1; i < pow(2, N); i++){
        bit = 1;
        odd = 0;
        for(int j = 0; j < N-1; j++){
            if(bit & i != 0){
                if(isOdd[j]) odd++;
            }
            bit << 1;
        }
        if(odd % 2 != 0) continue;
        ans++;
    }
    ans = ans % 998244353 ;
    cout << ans << endl;
    return 0;
}