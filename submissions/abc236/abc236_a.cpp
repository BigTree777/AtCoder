#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    int a, b;
    cin >> a >> b;
    int size_S = S.size();
    string str_a = S.substr(a-1, 1);
    string str_b = S.substr(b-1, 1);
    string ans = S.substr(0, a-1) + str_b \
                + S.substr(a, b-a-1) + str_a \
                + S.substr(b, size_S-b);
   
    // cout << "str_(0, a-1): " << S.substr(0, a-1) << endl;
    // cout << "str_b: " << str_b << endl;
    // cout << "str_(a, b-a-1): " << S.substr(a, b-a-1) << endl;
    // cout << "str_a: " << str_a << endl;
    // cout << "str_(b, size_S-b): " << S.substr(b, size_S-b) << endl;

    cout << ans << endl;
    return 0;   
}