// source: https://github.com/E869120/math-algorithm-book/blob/main/editorial/chap5-4/prob5-4-5.cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
// 最大公約数を返す関数
ll GCD(ll A, ll B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}
 
// 最小公倍数を返す関数 -> 最大公約数を活用
ll LCM(ll A, ll B) {
	return (A / GCD(A, B)) * B;
}
 
int main() {
    ull N, K;
	cin >> N >> K;
    ull V[K];
	for (int i = 0; i < K; i++) cin >> V[i];
 
	// ビット全探索 -> ビットで考えることにより組み合わせが簡単に
    ull ans = 0;
	for (int i = 1; i < (1 << K); i++) {
		ll cnt = 0; // 選んだ数の個数
		ll lcm = 1; // 最小公倍数
		for (int j = 0; j < K; j++) {
			if ((i & (1 << j)) != 0) { // 論理積が0でない -> 採用される数字 (例)101 -> V[0]とV[2]が採用
				cnt += 1;
				lcm = LCM(lcm, V[j]);
			}
		}
		ll num = floorf64((double)N / (double)lcm); // 選ばれた数すべての倍数であるものの個数
		if (cnt % 2 == 1) ans += num;
		if (cnt % 2 == 0) ans -= num;
	}
 
	// 出力
	cout << ans << endl;
	return 0;
}