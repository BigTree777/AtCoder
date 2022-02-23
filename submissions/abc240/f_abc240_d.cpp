// サンプルを解くことはできるが，提出すると15問もWA
// ボールが連続で消えるようなケースに対応できていなかった

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    // debug -> 23548でエラー -> 配列のサイズの限界？ -> そもそもaの配列がいらない
    // int* a;
    // a = (int *)malloc(sizeof(int));
    // vector<int> a(N, 0);
    // for(int i=0; i<N; i++){
    //     a[i] = 0;
    //     cout << i << ": " << a[i] << endl;
    // }
    // int a[N];
    // for(int i=0; i<N; i++) cin >> a[i];
    int N;
    cin >> N;
    // // debug
    // N = 10;
    deque<int> tube;

    int front = 0;
    int count = 0;
    int limit = 0;
    int a;
    for(int i=0; i<N; i++){
        // cout << "****" << i <<endl;
        cin >> a;
        // // debug
        // a = 500;
        if(tube.size()!=0) front = tube.back();
        // tube.push_back(a[i]);
        // if(front == a[i]){
        tube.push_back(a);
        if(front == a){
            if(count == 0){
                limit = front;
                count = 2;
            }
            else{
                count += 1;
            }
            if(limit == count){
                for(int j=0; j<limit; j++) tube.pop_back();
                // 原因
                // N = 5, a = {3 3 2 2 3}
                // ボールが連続で消えるようなケースに対応できない
                count = 0;
                limit = 0;
            }
        }
        else{
            count = 0;
            limit = 0;
        }
        cout << tube.size() << endl;
        // for(int j=0; j<tube.size(); j++) cout << tube[j] << " ";
        // cout << endl;
        front = 0;
    }

    return 0;
}