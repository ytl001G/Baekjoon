#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) int x = n; while(x--)

using namespace std;

int main() {
    FASTIO;

    iin(n); iin(m); iin(v);

    int **lines = new int* [m];

    FOR(i,0,m){
        iin(a); iin(b);

        lines[i] = new int[2];
        lines[i][0] = a;
        lines[i][1] = b;
    }

    stack<int> s;
    vector<int> visited;

    s.push(v);

    int now;
    while (!s.empty()) {
        if (find(visited.begin(),visited.end(),s.top()) != visited.end()) {
            s.pop();
            continue;
        }
        
        now = s.top();
        cout << now << " ";
        visited.push_back(now);
        s.pop();
        
        vector<int> temp;
        FOR(i,0,m){
            if (lines[i][0] == now && find(visited.begin(),visited.end(),lines[i][1]) == visited.end())
                temp.push_back(lines[i][1]);

            if (lines[i][1] == now && find(visited.begin(),visited.end(),lines[i][0]) == visited.end())
                temp.push_back(lines[i][0]);
        }

        sort(temp.begin(),temp.end());

        FORR(i,0,temp.size()){
            s.push(temp[i]);
        }
    }

    cout << "\n";

    queue<int> q;
    visited.clear();

    q.push(v);

    while (!q.empty()) {
        if (find(visited.begin(),visited.end(),q.front()) != visited.end()) {
            q.pop();
            continue;
        }
        
        now = q.front();
        cout << now << " ";
        visited.push_back(now);
        q.pop();
        
        vector<int> temp;
        FOR(i,0,m){
            if (lines[i][0] == now && find(visited.begin(),visited.end(),lines[i][1]) == visited.end())
                temp.push_back(lines[i][1]);

            if (lines[i][1] == now && find(visited.begin(),visited.end(),lines[i][0]) == visited.end())
                temp.push_back(lines[i][0]);
        }

        sort(temp.begin(),temp.end());

        FOR(i,0,temp.size()){
            q.push(temp[i]);
        }
    }

    return 0;
}