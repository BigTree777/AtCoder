#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull N;
    cin >> N;
    string S;
    cin >> S;

    vector<ull> W(N);
    for(ull i = 0; i < N; i++) cin >> W[i];
    
    vector<ll> numCorrect(N+1, 0);
    vector<pair<ull, bool>> target;
    for(ull i = 0; i < N; i++){
        bool isAdult = true;
        if(S[i] == '0') isAdult = false;
        else numCorrect[0]++;

        pair<ull, bool> p = make_pair(W[i], isAdult);
        target.push_back(p);
    }

    sort(target.begin(), target.end());

    ll num_same_weight = 0;
    for(ull i = 0; i < N; i++){
        if(target[i].second) num_same_weight--;
        else num_same_weight++;

        if(i != N-1){
            if(target[i+1].first == target[i].first){
                numCorrect[i+1] = numCorrect[i];
                continue;
            }
        }

        numCorrect[i+1] = numCorrect[i] + num_same_weight;
        num_same_weight = 0;
    }

    ull ans = *max_element(numCorrect.begin(), numCorrect.end());
    cout << ans << endl;

    return 0;
}