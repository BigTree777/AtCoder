#include<stdio.h>
#include<iostream>
#include<string>

int main(void){
  int N;
  std::cin >> N;
  int H[N];
  for(int i=0; i < N; i++){
    std::cin >> H[i];
  }
  int now = H[0];
  int next = H[1];
  int idx = 1;
  while(now < next){
    now = next;
    if(idx>=N-1){
      break;
    }
    next = H[idx+1];
    idx++;
  }
  std::cout << now << std::endl;
  return 0;
}
