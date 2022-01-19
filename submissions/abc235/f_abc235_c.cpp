#include<stdio.h>
#include<iostream>
#include<string>

int main(void){
  int N, Q;
  std::cin >> N >> Q;
  int A[N];
  for(int i=0; i < N; i++){
    std::cin >> A[i];
  }
  int x[Q], k[Q];
  for(int i=0; i<Q; i++){
    std::cin >> x[i] >> k[i];
  }
  int NoA, ans;
  for(int i=0; i<Q; i++){
    NoA = 0;
    ans = -1;
    for(int j=0; j<N; j++){
      if(x[i]==A[j]){
        NoA += 1;
        ans = j+1;
        if(NoA == k[i]) break;
      }
    }
    if(NoA != k[i]){
      ans = -1;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
