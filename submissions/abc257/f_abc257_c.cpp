#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull func(vector<ull>& vecChild, vector<ull>& vecAdult){
    ull max_child = *max_element(vecChild.begin(), vecChild.end());
    ull min_adult = *min_element(vecAdult.begin(), vecAdult.end());
    ull ans = 0;
    if(min_adult > max_child){
        ans = vecAdult.size() + vecChild.size();
        vecAdult.clear(); vecChild.clear();
        return ans;
    }
    else if(min_adult == max_child){
        ull a = 0;
        ull c = 0;
        for(ull i = 0; i < (ull)vecAdult.size(); i++){
            if(vecAdult[i] == min_adult) a++;
        }
        for(ull i = 0; i < (ull)vecChild.size(); i++){
            if(vecChild[i] == max_child) c++;
        }
        ans = (vecAdult.size() + vecChild.size() - (a + c)) + max(a, c);
        vecAdult.clear(); vecChild.clear();
        return ans;
    }
    else{
        vector<ull> ex_vecChild;
        vector<ull> ex_vecAdult;
        ull count_max_child = 0;
        ull count_min_adult = 0;
        for(ull i = 0; i < (ull)vecAdult.size(); i++){
            if((vecAdult[i] > min_adult) && (vecAdult[i] < max_child)) ex_vecAdult.push_back(vecAdult[i]);
            else if(vecAdult[i] == min_adult) count_min_adult++;
        }
        for(ull i = 0; i < (ull)vecChild.size(); i++){
            if((vecChild[i] > min_adult) && (vecChild[i] < max_child)) ex_vecChild.push_back(vecChild[i]);
            else if(vecChild[i] == max_child) count_max_child++;
        }
        if(ex_vecAdult.size() == 0 || ex_vecChild.size() == 0){
            ans = max(vecAdult.size(), vecChild.size());
            vecAdult.clear(); vecChild.clear();
            return ans;
        }
        ans = vecAdult.size() + vecChild.size() - ex_vecAdult.size() - ex_vecChild.size();
        vecAdult.clear(); vecChild.clear();
        vecAdult.reserve(ex_vecAdult.size()); vecChild.reserve(ex_vecChild.size());
        vecAdult = ex_vecAdult; vecChild = ex_vecChild;
        return ans;
    }
}

int main(){
    ull N;
    cin >> N;
    string S;
    cin >> S;

    ull W[N];
    for(ull i = 0; i < N; i++) cin >> W[i];

    vector<ull> vecChild;
    vector<ull> vecAdult;
    for(ull i = 0; i < N; i++){
        if(S[i] == '0'){
            vecChild.push_back(W[i]);
        }
        else{
            vecAdult.push_back(W[i]);
        }
    }
    if(vecChild.size() == 0 || vecAdult.size() == 0){
        cout << N << endl;
        return 0;
    }

    ull ans = 0;
    while(1){
        ans += func(vecChild, vecAdult);
        if(vecAdult.size() == 0 || vecChild.size() == 0){
            cout << ans << endl;
            break;
        }
    }
    return 0;
}