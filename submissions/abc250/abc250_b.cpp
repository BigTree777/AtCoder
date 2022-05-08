#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    vector<string> ans[N];
    bool rblack = false;
    bool cblack = false;
    for(int i = 1; i <= N*A; i++){
        cblack = rblack;
        for(int j = 1; j <= N*B; j++){
            if(cblack) cout << '#';
            else cout << '.';
            if(j % B == 0) cblack = !cblack;
        }
        cout << endl;
        if(i % A == 0) rblack = !rblack;
    }
    return 0;
}