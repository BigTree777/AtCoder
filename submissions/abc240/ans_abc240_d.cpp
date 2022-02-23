// source: https://atcoder.jp/contests/abc240/submissions/29491014

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // n = 200000;
    int count = 0;
    vector<pair<int, int>> ball;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        // a = 1;
        count += 1;
        if (ball.empty() or ball.back().first != a) {
            ball.emplace_back(a, 1);
        } else {
            ball.back().second += 1;
            if (ball.back().second == a) {
                count -= a;
                ball.pop_back();
            }
        }
        cout << count << '\n';
    }
    return 0;
}