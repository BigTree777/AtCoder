#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int K;
    cin >> K;

    bool stop = false;
    int num = 1;
    int ans = K;
    vector<int> vec(100, 0);
    while(!stop){
        ll tmp = K * num;
        ll nd = 1;
        ll tmp_ = tmp;
        while(1){
            tmp_ /= 10;
            if(tmp_ < 1) break;
            nd += 1;
        }
        for(int i = nd; i >= 0; i--){
            if(i == 0){
                vec[i] = tmp % 10;
                continue;
            }
            vec[i] = floor(tmp / pow(10, i));
            tmp -= vec[i] * pow(10, i);
        }
        ll ans_ = 0;
        for(int i = 0; i < vec.size(); i++){
            ans_ += vec[i];
            vec[i] = 0;
        }
        if(ans_ == 0) continue;
        if(ans_ < ans){
            ans = ans_;
        }
        if(ans <= nd) stop = true;
        num += 1;
    }
    cout << ans << endl;
    return 0;
}