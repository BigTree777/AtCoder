//source: https://github.com/E869120/math-algorithm-book/blob/main/editorial/chap5-2/prob5-2-3.cpp

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	// 入力
    ull N, K;
	cin >> N >> K;
    ull A[N+1];
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 配列の初期化
    ull First[N+1], Second[N+1];
	for (int i = 1; i <= N; i++) First[i] = -1; // 初めて到達
	for (int i = 1; i <= N; i++) Second[i] = -1; // 2回目に到達
	
	// 答えを求める
	// cur は現在いる町の番号
	ull cnt = 0, cur = 1;
	while (true) {
		// First, Second の更新
		if (First[cur] == -1) First[cur] = cnt; // 初めて着くのに何回かかるか
		else if (Second[cur] == -1) Second[cur] = cnt; // 2回目に着くのに何回かかるか
		
		// K 回の移動後に町 cur にいるかどうかの判定
		if (cnt == K) {
			cout << cur << endl;
			return 0;
		}
        // ループに入ったときの判定
		else if (Second[cur] != -1 && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
			cout << cur << endl;
			return 0;
		}
		
		// 位置の更新
		cur = A[cur];
		cnt += 1;
	}
	return 0;
}