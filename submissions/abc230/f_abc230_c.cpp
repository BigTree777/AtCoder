#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll = long long;

int main(){
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;
    vector<bool> tmp_vec(1, false);
    vector<vector<bool>> out(Q-P+1, tmp_vec);

    ll i, j;
    for(i=0; i<(Q-P+1); i++){
        for(j=0; j<(S-R+1); j++){
            out[i].push_back(false);
        }
    }
    ll k, min_k, max_k;
    // operation 1
    min_k = std::max(P-A, R-B);
    max_k = std::min(Q-A, S-B);
    for(k=min_k; k<=max_k; k++){
        i = A - P + k; //(A + k - 1) - (P - 1);
        j = B - R + k; //(B + k - 1) - (R - 1);
        if((i<0) | (j<0) | (i>Q-P) | (j>S-R)) continue;
        out[i][j] = true;
    }
    // operation 2
    min_k = std::max(P-A, B-S);
    max_k = std::min(Q-A, B-R);
    for(k=min_k; k<=max_k; k++){
        i = A - P + k; // (A + k - 1) - (P - 1);
        j = B - R - k; // (B - k - 1) - (R - 1);
        if((i<0) | (j<0) | (i>Q-P) | (j>S-R)) continue;
        out[i][j] = true;
    }
    // output
    for(i=0; i<(Q-P+1); i++){
        for(j=0; j<(S-R+1); j++){
            cout << (out[i][j] >= true ? "#" : ".");
        }
        std::cout << std::endl;
    }
    return 0;
}
