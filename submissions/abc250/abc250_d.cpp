#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ul = unsigned long;

int main(){
    ull N;
    cin >> N;
    if(N < 54){
        cout << 0 << endl;
        return 0;
    }

    vector<ul> vec_pn;
    vec_pn.push_back(2);


    for(ull i = 3; i < N; i++){
        // 素数探し
        bool pn = true;
        ull i_3 = i * i * i;
        if(i_3 > N) break;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                pn = false;
                break;
            }
            ul j_2 = j * j;
            if(j_2 > i) break;
        }
        if(pn) vec_pn.push_back(i);
    }

    ull q, p, q_3;
    int ans = 0;
    for(int j = 0; j < vec_pn.size(); j++){
        // 250に似た数字かどうか
        q = vec_pn[j];
        q_3 = q * q * q;
        for(int k = 0; k < j; k++){
            p = vec_pn[k];
            if(q_3 * p <= N) ans += 1;
            else break;
        }
    }

    cout << ans << endl;
    return 0;
}