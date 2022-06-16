#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    uint N;
    cin >> N;
    
    
    vector<ull> vec;
    for(uint i = 2; i < N+1; i++){
        vec.push_back((ull)pow(i, 2));
    }

    ull ans = 1;
    vector<ull> sub_vec;
    for(uint i = 0; i < vec.size(); i++){
        ull target = vec[i];
        for(uint j = 2; j < ceil(pow(target, 0.5)); j++){
            if(target % j == 0) sub_vec.push_back(j);
        }
        ans += pow(sub_vec.size(), 2);
    }
    
    cout << ans << endl;
    return 0;
}