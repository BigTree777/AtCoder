#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull H, W;
    cin >> H >> W;

    ull ans = 0;
    if(H == 1 || W == 1){
        cout << "1" << endl;
        return 0;
    }
    ull row = ceilf64((double)W * 0.5f);
    if(W % 2 != 0){
        ull new_H = floorf64((double)H * 0.5f);
        ans = ((2 * row) - 1) * new_H;
        if(H % 2 != 0) ans += row;
    }
    else ans = row * H;

    cout << ans << endl;
    return 0;
}