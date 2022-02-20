#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull s_val = 12800000;
    int H;
    cin >> H;

    double ans, ans1, ans2;

    ans1 = (s_val + H) * 0.001;
    ans2 = H * ans1 * 0.001;
    ans = sqrt(ans2) * 1000;

    cout << fixed;
    cout << setprecision(6) << ans << endl;
    return 0;
}