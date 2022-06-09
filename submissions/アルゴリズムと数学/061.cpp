#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ull N;
    cin >> N;

    ull num = 1;
    while(num <= N){
        if(num == N){
            cout << "Second" << endl;
            return 0;
        }
        num = num * 2 + 1;
    }

    cout << "First" << endl;
    return 0;
}