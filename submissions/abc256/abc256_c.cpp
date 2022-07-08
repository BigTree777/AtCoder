// ref: https://atcoder.jp/contests/abc256/editorial/4129
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int h[3], w[3];
    for(int i = 0; i < 3; i++) cin >> h[i];
    for(int i = 0; i < 3; i++) cin >> w[i];

    int ans = 0;
    for(int i = 1; i < 31; i++){
        for(int j = 1; j < 31; j ++){
            for(int k = 1; k < 31; k++){
                for(int l = 1; l < 31; l++){
                    int m = h[0] - i - j;
                    int n = h[1] - k - l;
                    int o = w[0] - i - k;
                    int p = w[1] - j - l;
                    int q = w[2] - m - n;
                    // initializer_list<int> vec = {m, n, o, p, q};
                    // if(min(vec) > 0){

                    // }
                    if(min({m, n, o, p, q}) > 0){ // 中括弧で初期化リスト(initializer_list)
                        if(o + p + q == h[2]) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}