#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    queue<int> q;
    string order;
    int a;

    for(int i=0; i<n; i++){
        cin >> order;

        if (order == "push"){
            cin >> a;
            q.push(a);
        } else if (order == "pop"){
            if(q.empty()){
                cout << -1 << endl;
            } else{
                cout << q.front() << endl;
                q.pop();
            }
        } else if (order == "size"){
            cout << q.size() << endl;
        } else if (order == "empty"){
            cout << (int)(q.empty()) << endl;
        } else if (order == "front"){
            if(q.empty()){
                cout << -1 << endl;
            } else{
                cout << q.front() << endl;
            }
        } else if (order == "back"){
            if(q.empty()){
                cout << -1 << endl;
            } else{
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}