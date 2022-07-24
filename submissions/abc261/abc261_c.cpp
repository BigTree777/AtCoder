#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    string S[N];
    map<string, int> mp;
    for(int i = 0; i < N; i++){
        cin >> S[i];
        mp[S[i]] = -1;
    }
    for(int i = 0; i < N; i++){
        mp[S[i]] += 1;
        if(mp[S[i]] == 0) cout << S[i] << endl;
        else cout << S[i] << "(" << mp[S[i]] << ")" << endl;
    }

    return 0;
}