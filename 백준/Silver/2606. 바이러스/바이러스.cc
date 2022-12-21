#include <iostream>
#include <queue>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) FOR(i,0,n)

using namespace std;

int main() {
    FASTIO;

    iin(n);
    iin(m);

    vector<vector<int>> graph;

    FOR(i,1,n+1){
        vector<int> a;
        graph.push_back(a);
    }

    FOR(i,0,m){
        iin(a);iin(b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int *visited = new int[n+1];
    FOR(i,1,n+1)
        visited[i] = 0;

    queue<int> q;

    q.push(1);
    visited[1] = 1;

    int nodes = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        nodes++;

        for (auto &&i : graph[now])
        {
            if (!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
        
    }

    cout << nodes-1;

    return 0;
}