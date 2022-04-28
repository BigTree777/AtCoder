#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N, K, X;
    cin >> N >> K >> X;

    vector<ll> A(N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    for(int i = 0; i < N; i++) ans += A[i];

    ll num = 0;
    for(int i = 0; i < N; i++) num += floor(A[i] / X); // 各商品の最低価格(>=0)
    // 使用したクーポンの枚数 x クーポンの割引価格 == ansとなるクーポンの枚数
    num = min(num, K); // 最大値をKに抑制
    ans -= num * X;
    K -= num;

    for(int i = 0; i < N; i++) A[i] %= X; // 端数を算出(クーポン1枚の価格より安い)
    sort(A.begin(), A.end()); 
    
    for(int i = N-1; i > -1; i--){ // 端数の大きな商品から順にクーポンを適用 -> ansを小さくする
        if(K == 0) break;
        ans -= A[i];
        K--;
    }

    cout << ans << endl;
    
    return 0;
}