#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;

    int ans = 0;
    for(int i = 0; i <= 100; i++){
        if((i > R1) && (i > R2)) break;
        if((L1 <= i) && (i <= R1)){
            if((L2 <= i) && (i <= R2)){
                ans += 1;
            }
        }
    }

    if(ans > 0) ans -= 1;
    cout << ans << endl;
    return 0;
}