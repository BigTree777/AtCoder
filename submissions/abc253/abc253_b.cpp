#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){

    int H, W;
    cin >> H >> W;

    string S[H+1];
    for(int i = 0; i < H; i++) cin >> S[i+1];

    vector<pair<int, int>> pone;
    for(int i = 1; i < H+1; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == 'o'){
                pone.push_back(make_pair(i, j));
            }
            if(pone.size() == 2) break;
        }
    }

    int ans = abs(pone[0].first - pone[1].first);
    ans += abs(pone[0].second - pone[1].second);
    cout << ans << endl;

    return 0;
}