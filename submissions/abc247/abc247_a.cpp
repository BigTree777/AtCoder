#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string S;
    cin  >>  S;

    string ans = S;
    ans[0] = '0';
    for(int i = 1; i < S.size(); i++){
        ans[i] = S[i-1];
        // cout << i << ": " << ans[i] << endl;
    }

    cout << ans.c_str() << endl;
    return 0;
}