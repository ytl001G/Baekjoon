#include <bits/stdc++.h>

using namespace std;

int window[100001][3];
int n;

int main() {
  cin >> n;

  window[1][0] = 1;
  window[1][1] = 1;
  window[1][2] = 1;

  for(int i = 2; i <= n; i++){
    window[i][0] = (window[i-1][0] + window[i-1][1] + window[i-1][2])%9901;
    window[i][1] = (window[i-1][0] + window[i-1][2])%9901;
    window[i][2] = (window[i-1][0] + window[i-1][1])%9901;
  }

  cout << (window[n][0] + window[n][1] + window[n][2])%9901;

  return 0;
}