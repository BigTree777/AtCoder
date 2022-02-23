// ようかんそのものを切ろうとするのではなく，ようかんをK+1個に
// 分けた時の長さを対象とし，その最小値を二分探索
// K+1個以上に分けられない -> 長さが大きいので探索範囲を左側に縮小する
// K+1個以上に分けられる -> 長さが短いので探索範囲を右側に移動
// reference: https://github.com/E869120/kyopro_educational_90/blob/main/sol/001.cpp

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, L, K;
    cin >> N >> L >> K;
    int A[N];
    for(int i=0; i<N; i++) cin >> A[i];

    int head = 0; 
    int tail = L;
    int half = 0;
    int count = 0;
    int before = 0;
    int l_length, r_length;
    while(tail - head > 1){
        half = (head + tail) * 0.5;
        before = 0;
        count = 0;
        for(int i=0; i<N; i++){
            l_length = A[i] - before;
            r_length = L - A[i];
            if((l_length >= half) && (r_length >= half)){
                count += 1;
                before = A[i];
            }
        }
        if(count >= K) head = half;
        else tail = half;
    }

    cout << head << endl;
    return 0;
}