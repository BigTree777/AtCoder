#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void dfs(int& ans, int* w, int* h, vector<int>* a, int ij) {
  int i = ij / 3; 
  int j = ij % 3;
  if(i == 3) { // iが9以上 == 終了
    ans++;
    return;
  }
  if(i == 2) { // 対象の行の最後の要素を埋める
    int x = w[j] - a[0][j] - a[1][j];
    if(x <= 0) return;
    a[i][j] = x; 
    dfs(ans, w, h, a, ij+1);
  }
  else if (j == 2) { // 対象の列の最後の要素を埋める
    int x = h[i] - a[i][0] - a[i][1];
    if (x <= 0) return;
    a[i][j] = x;
    dfs(ans, w, h, a, ij+1);
  }
  else {
    for (int x = 1; x <= 30; x++){ // 総当り
        a[i][j] = x;
        dfs(ans, w, h, a, ij+1);
    }
  }
}

int main(){
    int h[3], w[3];
    for(int i = 0; i < 3; i++) cin >> h[i];
    for(int i = 0; i < 3; i++) cin >> w[i];

    if (h[0] + h[1] + h[2] != w[0] + w[1] + w[2]) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    vector<int> a[3];
    for(int i = 0; i < 3; i++) a[i] = {0, 0, 0};
    dfs(ans, w, h, a, 0);
    cout << ans << endl;
    return 0;
}