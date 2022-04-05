#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    string T;

    cin >> N;
    cin >> T;

    int sign = 1;
    float rad = 0;
    float s, c;
    bool x_ori = true;
    vector<int> pos(2, 0);
    for(char t: T){
        if(t == 'S'){
            if(x_ori) pos[0] += sign;
            else pos[1] += sign;
        }
        else{
            rad -= 0.5 * M_PI;
            if(rad < 2 * M_PI) rad += 2 * M_PI;
            s = sin(rad);
            c = cos(rad);
            if(round(s) != 0){
                sign = s;
                x_ori = false;
            }
            else if(round(c) != 0){
                sign = c;
                x_ori = true;
            }
            else return -1;
        }
        // cout << t << ":" << pos[0] << " " << pos[1] << endl;
    }
    cout << pos[0] << " " << pos[1] << endl;
    return 0;
}