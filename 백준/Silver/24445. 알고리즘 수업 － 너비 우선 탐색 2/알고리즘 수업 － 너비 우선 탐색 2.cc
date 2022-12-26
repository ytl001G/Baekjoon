#include <bits/stdc++.h>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
queue<int> q;
int visited[100001] = {0,};
int order = 1;

void bfs(int start){
    visited[start] = order;
    q.push(start);

    while (!q.empty()){
        int now = q.front();
        q.pop();

        FOR(i,0,graph[now].size()){
            if (!visited[graph[now][i]]){
                order++;
                visited[graph[now][i]] = order;
                q.push(graph[now][i]);
            }
        }
    }
}

bool compare(int i, int j){
    return i > j;
}

int main() {
    FASTIO;

    iin(n);
    iin(m);
    iin(r);


    FOR(i,0,n+1){
        vector<int> v;
        graph.push_back(v);
    }

    FOR(i,0,m){
        iin(x);
        iin(y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    FOR(i,1,n+1){
        sort(graph[i].begin(), graph[i].end(), compare);
    }

    bfs(r);

    FOR(i,1,n+1){
        cout << visited[i] << endl;
    }

    return 0;
}