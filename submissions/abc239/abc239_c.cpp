#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double l_12;
    l_12 = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    if(l_12 > 20){
        cout << "No" << endl;
        return 0;
    }
    vector<int> x, y;
    for(int i=-2; i<=abs(x1-x2)+2; i++) x.push_back(min(x1, x2) + i);
    for(int i=-2; i<=abs(y1-y2)+2; i++) y.push_back(min(y1, y2) + i);

    double l;
    bool ans = false;
    for(int _x: x){
        l = pow(_x - x1, 2);
        if(l > 5) continue;
        l = pow(_x - x2, 2);
        if(l > 5) continue;
        for(int _y: y){
            l = pow(_x - x1, 2) + pow(_y - y1, 2);
            if(l!=5) continue;
            l = pow(_x - x2, 2) + pow(_y - y2, 2);
            if(l!=5) continue;
            ans = true;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}