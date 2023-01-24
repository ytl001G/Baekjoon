#include <bits/stdc++.h>

using namespace std;

int number[101];
long long int window[101][21];
int n;

int main() {
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> number[i];
  }

  window[1][number[1]] = 1;

  for(int i = 1; i < n-1; i++){
    for(int j = 0; j <= 20; j++){
      if(window[i][j]){
        if(0 <= j + number[i+1] && j + number[i+1] <= 20){
          window[i+1][j + number[i+1]] += window[i][j];
        }

        if(0 <= j - number[i+1] && j - number[i+1] <= 20){
          window[i+1][j - number[i+1]] += window[i][j];
        }
      }
    }
  }

  cout << window[n-1][number[n]];
  
  return 0;
}