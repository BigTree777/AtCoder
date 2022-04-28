#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    string s[N], t[N];
    map<string, bool> m;
    for(int i = 0; i < N; i++){
        cin >> s[i] >> t[i];
        if(s[i] == t[i]){
            m[s[i]] = false;
            m[t[i]] = false;
            continue;
        }
        if(m.find(s[i]) != m.end()){
            m[s[i]] = true;
        }
        else{
            m[s[i]] = false;
        }
        if(m.find(t[i]) != m.end()){
            m[t[i]] = true;
        }
        else{
            m[t[i]] = false;
        }
    }

    string a;
    for(int i = 0; i < N; i++){
        a = s[i];
        if(m[a]){
            a = t[i];
            if(m[a]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}