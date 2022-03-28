#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int R, C;
    cin >> R >> C;
    pair<int, int> start, goal;
    int x, y;
    cin >> y >> x;
    start = make_pair(y, x);
    cin >> y >> x;
    goal = make_pair(y, x);
    vector<string> maize;
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        maize.push_back(s);
    }

    vector<int> dist[R+1];
    vector<int> v(C+1, -1);
    for(int i = 1; i < R+1; i++){
        dist[i] = v;
    }

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while(!q.empty()){
        int now_y = q.front().first;
        int now_x = q.front().second;
        q.pop();
        int sw = 0;
        int before_dist = dist[now_y][now_x];
        for(int i = 0; i < 4; i++){
            switch(sw){
                case 0:
                now_x -= 1;
                break;
                case 1:
                now_x += 1;
                now_y -= 1;
                break;
                case 2:
                now_y += 2;
                break;
                case 3:
                now_x += 1;
                now_y -= 1;
                break;
                default:
                break;
            }
            sw += 1;
            if((now_x < 1) || (now_x > C)) continue;
            if((now_y < 1) || (now_y > R)) continue;
            if(dist[now_y][now_x] == -1){
                if(maize[now_y-1][now_x-1] == '#'){
                    dist[now_y][now_x] = -2;
                }
                else{
                    dist[now_y][now_x] = before_dist + 1;
                    q.push(make_pair(now_y, now_x));
                }
            }
        }
    }

    cout << dist[goal.first][goal.second] << endl;
    
    return 0;
}