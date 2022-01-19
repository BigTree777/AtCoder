#include<stdio.h>

int h[100010]; // as long as possible?

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", h+i); // 配列名がアドレスを表す

    int pos = 0;
    while((pos+1 < n) && (h[pos] < h[pos+1])) pos++;
    printf("%d\n", h[pos]);
}