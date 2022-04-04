#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0), B(N, 0);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    vector<int> rec_1[N];
    rec_1[0].push_back(A[0]);
    rec_1[0].push_back(B[0]);
    bool ans = true;
    for(int i = 1; i < N; i++){
        bool a = true, b = true;
        for(int r: rec_1[i-1]){
            if((abs(r - A[i]) <= K) && a){
                rec_1[i].push_back(A[i]);
                a = false;
            }
            if((abs(r - B[i]) <= K) && b){
                rec_1[i].push_back(B[i]);
                b = false;
            }
            // if(!a && !b) break;
        }
        if(rec_1[i].size() == 0){
            ans = false;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}