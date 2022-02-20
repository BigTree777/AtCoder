#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main(){
    ll n;
    cin >> n;

    ll a = 1;
    ll b = pow(n, 2);

    for(ll i=0; i<n; i++){
        a *= 2;
        if(a > b) break;
    }
    if(a > b) cout << "Yes" << endl;
    else cout << "No" << endl;
    

    return 0;
}