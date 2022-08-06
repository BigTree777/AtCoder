#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int card[5];
    for(int i = 0; i < 5; i++) cin >> card[i];

    map<int, int> mp;
    for(int i = 0; i < 5; i++){
        mp[card[i]]++;
    }

    string ans = "No";
    bool two = false;
    bool three = false;
    for(int c: card){
        if(mp[c] == 2){
            two = true;
        }
        else if(mp[c] == 3){
            three = true;
        }
    }
    if(two && three) ans = "Yes";
    cout << ans << endl;
    return 0;
}