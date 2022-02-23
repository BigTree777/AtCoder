// source: https://atcoder.jp/contests/abc240/editorial/3421
// N x Xの配列を用いることにより何回目にどの位置を通るかをすべて記録できる
// キーワード: 動的計画法

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, X;
    cin >> N >> X;

    int a[N], b[N];
    for(int i=0; i<N; i++) cin >> a[i] >> b[i];

    vector dp(N + 1, vector(X + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= X; ++j) {
            if (dp[i][j]) {
                if (j + a[i] <= X) {
                    dp[i + 1][j + a[i]] = true;
                }
                if (j + b[i] <= X) {
                    dp[i + 1][j + b[i]] = true;
                }
            }
        }
    }
    cout << (dp[N][X] ? "Yes" : "No") << '\n';
    return 0;
}