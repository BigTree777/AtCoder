// source: https://atcoder.jp/contests/abc261/editorial/4483
// ｢組み合わせによる総額の変化｣ ではなく,  ｢毎回のコイントスによる総額の変化｣ に注目
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;
	long long x[5001];
	long long c, y;
	long long cy[5001], dp[5001][5001];
	long long ans;
	for (int i = 0; i <= n; i++) cy[i] = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> x[i + 1];
	for (int i = 0; i < m; i++) {
		cin >> c >> y;
		cy[c] = y;
	}

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
        // i番目に ｢表｣ となる
		for (int j = 1; j <= i; j++){
            dp[i][j] = dp[i - 1][j - 1] + x[i] + cy[j];
            // dp[i - 1][j - 1]: i-1番目でカウンタがj-1
            // x[i]: 表になってもらえる金額
            // cy[j]: カウンタの値によってもらえる金額
        }

        // i番目に ｢裏｣ となる
		dp[i][0] = 0;
		for (int j = 0; j < i; j++){
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            // もらえる金額が増えないのでi-1番目の結果の最大値
        }
	}

	ans = 0;
	for (int i = 0; i <= n; i++)ans = max(ans, dp[n][i]);
	cout << ans << endl;

	return 0;
}
