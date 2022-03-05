#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string S;
    cin >> S;

    vector<int> ans;
    for(int i = 0; i < S.size(); i++){
        int s = (int)S[i];
        // cout << s << endl;
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << (char)ans[i];
    }
    cout << endl;

    return 0;
}