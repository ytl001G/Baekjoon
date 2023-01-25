#include <bits/stdc++.h>

using namespace std;

int window[32][32];
int n, l;
long long int I;

int main() {
  cin >> n >> l >> I;

  window[0][0] = 1;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= l; j++) {
      if (i == 0 || j == 0) {
        window[i][j] = 1;
      } else {
        window[i][j] = window[i - 1][j - 1] + window[i - 1][j];
      }
    }
  }

  while (n > 0) {
    if (I <= window[n - 1][l]) {
      cout << "0";
      n--;
    } else {
      cout << "1";
      I -= window[n - 1][l];
      n--;
      l--;
    }
  }

  return 0;
}