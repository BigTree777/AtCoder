#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll search(map<ll, vector<ll>>& dic, ll idx, vector<ll> rm_num){
    ll start;
    for(vector<ll>::iterator i=dic[idx].begin(); i!=dic[idx].end(); i++){
        start = *i;
    }
    return start;
}

int main(){
    ll N;
    cin >> N;
    ll A[N];
    map<ll, vector<ll>> dic;
    ll x;
    for(ll i=0; i<N; i++) {
        cin >> A[i];
        if(dic.count(A[i])==0){
            vector<ll> v;
            dic[A[i]] = v;
            for(ll j=0; j<i; j++){
                dic[A[i]].push_back(A[j]);
            }
        }
        for(pair<ll, vector<ll>> par: dic){
            x = par.first;
            if(x==A[i]) continue;
            dic[x].push_back(A[i]);
        }
    }
    // ll idx = 1, before_idx = 0, start = 0;
    // if(dic[1].size()==0){
    //     cout << " " << endl;
    //     return 0;
    // }
    // vector<ll> rm_num;
    // while(1){
    //     before_idx = idx;
    //     idx = search(dic, idx, rm_num);
    //     if(before_idx <= idx){
            
    //     }
    // }
    if(dic.size()==1){
        cout << " " << endl;
        return 0;
    }     
    vector<ll> cand, b_cand;
    ll _min = LONG_LONG_MAX;
    ll value, count=0;
    while(cand.size()!=1){
        b_cand = cand;
        for(pair<ll, vector<ll>> par: dic){
            x = par.first;
            if(count!=0){
              if(find(b_cand.begin(), b_cand.end(), x)==b_cand.end()){
                  continue;
              }
            }
            value = *(dic[x].begin() + count);
            if(value < _min){
                _min = value;
                cand.clear();
                if(find(cand.begin(), cand.end(), x)==cand.end()){
                    cand.push_back(x);
                }
            }
            else if(value == _min){
                if(find(cand.begin(), cand.end(), x)==cand.end()){
                    cand.push_back(x);
                }
            }
        }
        count++;
        _min = LONG_LONG_MAX;
    }
    for(ll a: dic[*cand.begin()]){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}