#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  
  for(int i = 0; i < n; i++){
    string s;
    getline(cin, s);

    int ans = 0, temp = 0;
    for(char c : s){
      if (c == 'O'){
        temp++;
        ans += temp;
      } else {
        temp = 0;
      }
    }

    cout << ans << endl;
  }

  return 0;
}