// source: https://atcoder.jp/contests/abc241/editorial/3453
// multisetを利用

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int Q;
    cin >> Q;

    ull c[Q], x[Q], k[Q];
    multiset<ull> A;
    for(int i = 0; i < Q; i++){
        cin >> c[i] >> x[i];
        if(c[i] == 1){
            k[i] = 0;
        }
        else cin >> k[i];
    }
    multiset<ull>::iterator ans;
    bool overflow = false;
    for(int i = 0; i < Q; i++){
        overflow = false;
        if(c[i] == 1) A.insert(x[i]);
        else if(c[i] == 2){
            ans = A.upper_bound(x[i]);
            if(ans == A.begin() && k[i] > 0){
                overflow = true;
                cout << -1 << endl;
                continue;
            }
            for(ull j = 0; j < k[i]; j++){
                ans--;
                if((ans == A.begin()) && (k[i] - 1 - j > 0) ){
                    overflow = true;
                    break;
                }
            }
            if(overflow) cout << -1 << endl;
            else cout << *ans << endl;
        }
        else if(c[i] == 3){
            ans = A.lower_bound(x[i]);
            if(ans == A.end() && k[i] > 0){
                overflow = true;
                cout << -1 << endl;
                continue;
            }
            for(ull j = 0; j < k[i] - 1; j++){
                ans++;
                if(ans == A.end()){
                    overflow = true;
                    break;
                }
            }
            if(overflow) cout << -1 << endl;
            else cout << *ans << endl;
        }
    }
    return 0;
}