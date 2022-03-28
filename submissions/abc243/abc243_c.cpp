#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    map<int, vector<int>> table;
    vector<int> v;
    int x, y;
    vector<pair<int, int>> vec;
    for(int i = 0; i< N; i++){
        cin >> x >> y;
        pair<int, int> p = make_pair(x, y);
        vec.push_back(p);
        if(table.find(y) != table.end()){
            table[y].push_back(x);
        }
        else{
            v.push_back(x);
            table[y] = v;
            v.clear();
        }
        sort(table[y].begin(), table[y].end());
    }

    string S;
    cin >> S;
    
    map<int, vector<int>> check;
    for(int i = 0; i < N; i++){
        y = vec[i].second;
        vector<int> same_y = table[y];
        if(check.find(y) == check.end()){
            vector<int> tmp(same_y.size(), 0);
            check[y] = tmp;
        }
    }

    int pos, before;
    bool col = false;
    int first, last;
    for(int i = 0; i < N; i++){
        x = vec[i].first;
        y = vec[i].second;
        vector<int> same_y = table[y];
        pos = distance(same_y.begin(), find(same_y.begin(), same_y.end(), x));
        if(S[i] == 'L'){
            check[y][pos] = -1;
        }
        else if(S[i] == 'R'){
            check[y][pos] = 1;
        }
        first = distance(same_y.begin(), find(same_y.begin(), same_y.end(), 1));
        last = distance(same_y.rend(), find_if(same_y.rbegin(), same_y.rend(), [](int x) { return x == -1; })) + 1;
        if(first > last){
            col = true;
            break;
        }
    }

    if(col) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}