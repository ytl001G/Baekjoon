#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    bool flag = true;
    while(q.size() > 1){
        if(flag){
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }

        flag = !flag;
    }

    cout << q.front();

    return 0;
}