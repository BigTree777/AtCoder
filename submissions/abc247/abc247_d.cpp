#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    uint Q;
    cin >> Q;

    vector<uint> query[Q];
    uint num;
    for(uint i = 0; i < Q; i++){
        cin >> num;
        if(num == 1){
            query[i].push_back(num);
            cin >> num;
            query[i].push_back(num);
            cin >> num;
            query[i].push_back(num);
        }
        else if(num == 2){
            query[i].push_back(num);
            cin >> num;
            query[i].push_back(num);
        }
    }

    deque<pair<uint, uint>> ans;
    for(vector<uint> q: query){
        if(q[0] == 1){
            uint x = q[1];
            uint c = q[2];
            pair<uint, uint> p = make_pair(x, c);
            ans.push_back(p);
        }
        else if(q[0] == 2){
            uint c = q[1];
            ll sum = 0;
            while(1){
                if(ans.front().second < c){
                    sum += (ll)ans.front().first * (ll)ans.front().second;
                    c -= ans.front().second;
                    ans.pop_front();
                    continue;
                }
                else{
                    sum += (ll)ans.front().first * (ll)c;
                    if(ans.front().second - c > 0){
                        pair<uint, uint> p = make_pair(ans.front().first, ans.front().second - c);
                        ans.pop_front();
                        ans.push_front(p);
                    }
                    else ans.pop_front();
                    break;
                }
            }
            cout << sum << endl;
        }
        else{
            return 1;
        }
    }
    return 0;
}