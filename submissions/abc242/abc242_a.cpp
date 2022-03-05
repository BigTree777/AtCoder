#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    if(X <= A){
        cout << 1 << endl;
        return 0;
    }
    else{
        if(X > B){
            cout << 0 << endl;
            return 0;
        }
        else{
            double ans = (double)C / (double)(B - A);
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}