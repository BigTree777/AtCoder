// 問題文から難しい
// j mod N -> Nを法とする余り -> 0 <= (j mod N) <= N-1
// 0 <= j <= 2N-1
// i: start
// k: end
// 循環することを利用
// 連続した範囲で加算される -> 飛び飛びの値にするならば，飛ばされる値をiとする

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N, 0);
    int max_x = 0;
    for(int& a: A){
        cin >> a;
        if(a > max_x) max_x = a;
    }

    vector<int> x(N, 0);
    int ans = max_x;
    


    return 0;
}