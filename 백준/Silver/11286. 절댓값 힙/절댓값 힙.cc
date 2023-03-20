#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct cmp{
    bool operator()(int a, int b){
        if (abs(a) != abs(b)){
            return abs(a) > abs(b);
        } else {
            return a > b;
        }
    }
};

priority_queue<int, vector<int>, cmp> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    while(n--){
        int a;
        cin >> a;
        
        if (a == 0){
            if (q.empty()){
                cout << 0 << endl;
            } else {
                cout << q.top() << endl;
                q.pop();
            }
        } else {
            q.push(a);
        }
    }

    return 0;
}
