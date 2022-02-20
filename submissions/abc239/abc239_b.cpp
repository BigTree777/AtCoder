#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll X;
    cin >> X;

    ll ans;
    ans = floorl(X / 10);

    if((X < 0) && (X%10!=0)) ans += -1;
    cout << ans << endl;
    return 0;
}