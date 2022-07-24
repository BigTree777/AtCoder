#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N, M;
    cin >> N >> M;

    map<ll, vector<ll>> X;
    vector<ll> tmpX;
    for(int i = 0; i < N; i++){
        ll x;
        cin >> x;
        X[x].push_back(i);
        tmpX .push_back(x);
    }

    map<ll, vector<ll>> YC;
    vector<ll> tmpY;
    for(int i = 0; i < M; i++){
        ll c, y;
        cin >> c >> y;
        YC[y].push_back(c);
        tmpY.push_back(y);
    }    

    sort(tmpX.begin(), tmpX.end());
    sort(tmpY.begin(), tmpY.end());
    // map<ll, vector<ll>> new_YC, new_X;
    // for(int i = 0; i < N; i++) new_X[tmpX[i]] = X[tmpX[i]];
    // for(int i = 0; i < M; i++) new_YC[tmpY[i]] = YC[tmpY[i]];

    bool isX = false;
    int idx_x = 0;
    int idx_y = 0;
    ll ans = 0;
    vector<int> rec(N, 0);
    while(1){
        if(tmpX[idx_x] > tmpY[idx_y]){
            isX = true;
        }
        else{
            isX = false;
        }

        if(isX){
            for(ll _x: X[tmpX[idx_x]]){
                if(rec[_x] != 0) continue;
                ans += tmpX[idx_x];
            }
            idx_x++;
        }
        else{
            ll tmp_ans = 0;
            
            idx_y++;
        }

        
    }

    return 0;
}