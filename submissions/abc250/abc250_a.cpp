#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int H, W, R, C;
    cin >> H >> W;
    cin >> R >> C;
    
    int ans = 0;
    if(C - 1 > 0) ans += 1;
    if(C + 1 <= W) ans += 1;
    if(R - 1 > 0) ans += 1;
    if(R + 1 <= H) ans += 1;

    cout << ans << endl;

    return 0;
}