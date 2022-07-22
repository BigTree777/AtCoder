#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;

    queue<vector<pair<bool, int>>> q;
    pair<bool, int> p = make_pair(true, N); // true:red
    vector<pair<bool, int>> v(1, p);
    q.push(v);
    queue<ll> blue;
    blue.push(0);
    ll _max = -1;
    while(q.size() != 0){
        vector<pair<bool, int>> vec = q.front();
        q.pop();
        sort(vec.begin(), vec.end());

        ll num = blue.front();
        blue.pop();

        if(num > _max) _max = num;
        // op1
        vector<pair<bool, int>> new_vec(vec.size());
        copy(vec.begin(), vec.end(), new_vec.begin());
        for(int i = vec.size()-1; i > -1 ; i--){
            if(vec[i].second < 2 || vec[i].first == false) break;
            if(vec[i].first == true){
                new_vec[i] = make_pair(true, vec[i].second - 1); // red(n-1) x 1
                for(int j = 0; j < X; j++){ // blue(n) x X
                    new_vec.push_back(make_pair(false, vec[i].second));
                }
                q.push(new_vec);
                blue.push(num + X);
                break;
            }
        }

        // op2
        new_vec.clear();
        new_vec.resize(vec.size());
        copy(vec.begin(), vec.end(), new_vec.begin());
        for(int i = num-1; i > -1; i++){
            if(vec[i].second < 2) break;
            if(vec[i].first == false){
                new_vec[i] = make_pair(true, vec[i].second - 1); // red(n-1) x 1
                for(int j = 0; j < Y; j++){ // blue(n-1) x Y
                    new_vec.push_back(make_pair(false, vec[i].second - 1));
                }
                q.push(new_vec);
                blue.push(num + Y - 1);
                break;
            }
        }
    }

    cout << _max << endl;
    return 0;
}