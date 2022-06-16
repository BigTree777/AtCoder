#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int Q;
    cin >> Q;

    vector<int> vec_q[Q];
    map<int, int> amount;
    for(int i = 0; i < Q; i++){
        int num, x, c;
        vector<int> vec(3, -1);
        cin >> num;
        vec[0] = num;
        if(num == 1){
            cin >> x;
            vec[1] = x;
            amount[x] = 0;
        }
        else if(num == 2){
            cin >> x;
            cin >> c;
            vec[1] = x;
            vec[2] = c;
        }
        vec_q[i] = vec;
    }

    vector<int> query;
    vector<int> logger;
    int _max = -1, _min = -1;
    for(int i = 0; i < Q; i++){
        query = vec_q[i];
        if(query[0] == 1){
            if(amount[query[1]] == 0) logger.push_back(query[1]);
            amount[query[1]] += 1;
        }
        else if(query[0] == 2){
            if(amount[query[1]] <= query[2]){
                amount[query[1]] = 0;
                if(_max == query[1]) _max = -1;
                if(_min == query[1]) _min = -1;
            }
            else{
                amount[query[1]] -= query[2];
            }
        }
        else if(query[0] == 3){
            sort(logger.begin(), logger.end());
            if(_max == -1){
                for(vector<int>::iterator itr = logger.begin(); itr != logger.end(); itr++){
                    if(amount[*itr] > 0){
                        _min = *itr;
                        break;
                    }
                }
            }
            if(_min == -1){
                for(vector<int>::reverse_iterator itr = logger.rbegin(); itr != logger.rend(); itr++){
                    if(amount[*itr] > 0){
                        _max = *itr;
                        break;
                    }
                }
            }
            int ans = _max - _min;
            cout << ans << endl;
        }
    }

    return 0;
}