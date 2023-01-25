#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int a;
    string s;
    cin >> a >> s;
    for(char c : s){
      for(int j = 0; j < a; j++){
        cout << c;
      }
    }

    cout << endl;
  }

  return 0;
}