#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;

    int a[N];
    for(int i=0; i<N; i++) cin >> a[i];
    deque<int> tube;

    int front = 0;
    int count = 0;
    int limit = 0;
    for(int i=0; i<N; i++){
        if(tube.size()!=0) front = tube.back();
        tube.push_back(a[i]);
        if(front == a[i]){
            if(count == 0){
                limit = front;
                count = 2;
            }
            else{
                count += 1;
            }
            if(limit == count){
                for(int j=0; j<limit; j++) tube.pop_back();
                count = 0;
                limit = 0;
            }
        }
        else{
            count = 0;
            limit = 0;
        }
        cout << tube.size() << endl;
        front = 0;
    }

    return 0;
}