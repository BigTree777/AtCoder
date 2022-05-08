#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    string S[N];
    map<string, int> m;
    for(int i = 0; i < N; i++){
        cin >> S[i];
        if(m.find(S[i]) != m.end()){
            m[S[i]] += 1;
        }
        else{
            m[S[i]] = 1;
        }
    }

    int ans = 0;
    string ans_name;
    for(string s: S){
        if(m[s] > ans){
            ans = m[s];
            ans_name = s;
        }
    }

    cout << ans_name << endl;
    return 0;
}