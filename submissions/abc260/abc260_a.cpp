#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string S;
    cin >> S;

    char c0 = S[0];
    char c1 = S[1];
    char c2 = S[2];
    string ans;
    if(c0 == c1){
        if(c2 == c1){
            cout << -1 << endl;
            return 0;
        }
        cout << c2 << endl;
        return 0;
    }
    else if(c1 == c2){
        if(c0 == c2){
            cout << -1 << endl;
            return 0;
        }
        cout << c0 << endl;
        return 0;
    }
    else if(c0 == c2){
        if(c0 == c1){
            cout << -1 << endl;
            return 0;
        }
        cout << c1 << endl;
        return 0;
    }
    else{
        cout << c0 << endl;
        return 0;
    }
}