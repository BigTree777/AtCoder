#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> query[Q];
    int q, x;
    for(int i = 0; i < Q; i++){
        cin >> q >> x;
        query[i].push_back(q);
        query[i].push_back(x);
    }

    int sum_x = 0;
    for(int i = 0; i < Q; i++){
        q = query[i][0];
        x = query[i][1];
        if(q == 1){
            sum_x += x;
            if(sum_x >= N) sum_x -= N;
        }
        else{
            // if(sum_x != 0){
            //     string sub_1 = S.substr(N - sum_x, sum_x);
            //     string sub_2 = S.substr(0, N - sum_x);
            //     S = sub_1 + sub_2;
            // }
            int pos = N + ((x - 1) - sum_x);
            if(pos >= N) pos -= N;
            cout << S[pos] << endl;
            // sum_x = 0;
        }
    }

    return 0;
}