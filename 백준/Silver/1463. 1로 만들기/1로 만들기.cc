#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int memo[1000001];

int op(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }

    int ans;
    if (n%3 == 0){
        if (n%2 == 0) {
            ans = min(min(op(n-1), op(n/3)), op(n/2))+1;
        } else {
            ans = min(op(n-1), op(n/3))+1;
        }
    } else if (n%2 == 0){
        ans = min(op(n-1), op(n/2))+1;
    } else {
        ans =  op(n-1)+1;
    }

    if (memo[n] == -1) {
        memo[n] = ans;
    }
    return ans;
}

int main() {
    int x;
    cin >> x;

    memo[2] = 1;
    memo[3] = 1;
    for (int i = 4; i < 1000001; i++)
    {
        memo[i] = -1;
    }
    
    cout << op(x);
    return 0;
}