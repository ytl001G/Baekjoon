#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    cout << "<";
    while(q.size()){
        for(int i = 0; i < k; i++){
            if (i == k-1){
                cout << q.front();
                if (q.size() > 1){
                    cout << ", ";
                }
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        }
    }
    cout << ">";


    return 0;
}