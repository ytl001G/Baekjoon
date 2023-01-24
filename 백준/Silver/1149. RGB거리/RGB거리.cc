#include <bits/stdc++.h>

using namespace std;

int cost[1001][3];
int window[1001][3];
int n;

int main() {
  cin >> n;
  
  for(int i = 1; i <= n; i++){
    int r,g,b;
    cin >> r >> g >> b;

    cost[i][0] = r;
    cost[i][1] = g;
    cost[i][2] = b;
  }

  window[1][0] = cost[1][0];
  window[1][1] = cost[1][1];
  window[1][2] = cost[1][2];

  for(int i = 2; i <= n; i++){
    window[i][0] = min(window[i-1][1], window[i-1][2]) + cost[i][0];
    window[i][1] = min(window[i-1][0], window[i-1][2]) + cost[i][1];
    window[i][2] = min(window[i-1][1], window[i-1][0]) + cost[i][2];
  }

  cout << min(window[n][0], min(window[n][1], window[n][2]));
}