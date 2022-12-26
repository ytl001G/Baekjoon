#include <bits/stdc++.h>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define endl "\n"

using namespace std;

int visited[1001] = {0,};
vector<vector<int>> graph;

int n, m, cnt = 0;

void dfs(int start){
    visited[start] = 1;

    FOR(i,0,graph[start].size()){
        if(!visited[graph[start][i]]){
            dfs(graph[start][i]);
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    FOR(_,0,n+1){
        vector<int> temp;
        graph.push_back(temp);
    }

    FOR(_,0,m){
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    FOR(i,1,n+1){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }

    cout << cnt;

    return 0;
}