// source: https://github.com/E869120/kyopro_educational_90/blob/main/sol/001.cpp

#include <iostream>
using namespace std;

long long N, K, L;
long long A[1 << 18];

bool solve(long long M) {
    // K個以上の長さM以上のようかんに切ることができるかどうか
    long long cnt = 0, pre = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] - pre >= M && L - A[i] >= M) {
            cnt += 1;
            pre = A[i];
        }
    }
    if (cnt >= K) return true; // できた
    return false; // できなかった
}

int main() {
    cin >> N >> L;
    cin >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    // Step #2. 答えで二分探索
    // https://qiita.com/drken/items/97e37dd6143e33a64c8c
    long long left = -1; // 条件を満たす
    long long right = L + 1; // 条件を満たさない
    cout << "left:right -> " << left << ":" << right << endl;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2; // 
        if (solve(mid) == false) right = mid; // K個以上にできなかった
        else left = mid; // K個以上にできたら左端を真ん中に移動 
        cout << "left:right -> " << left << ":" << right << endl;
    }
    cout << left << endl;
    return 0;
}