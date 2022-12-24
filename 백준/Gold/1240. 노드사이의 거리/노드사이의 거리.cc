#include <iostream>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define endl "\n"

using namespace std;

int n, m;

int visited[1000];

int graph[1000][1000];

void dfs(int s, int e, int dist){
    if (visited[s] == 1){
        return;
    }

    if (s == e){
        cout << dist << endl;
        return;
    }

    visited[s] = 1;

    FOR(i,0,n){
        if (graph[s][i] != 0){
            dfs(i, e, dist+graph[s][i]);
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    FOR(i,0,n){
        FOR(j,0,n){
            graph[i][j] = 0;
        }
    }

    FOR(i,0,n-1){
        iin(x);iin(y);iin(c);
        x--;
        y--;

        graph[x][y] = graph[y][x] = c;
    }

    // solve
    FOR(i,0,m){
        iin(x);iin(y);
        x--;
        y--;

        for (auto &&i : visited)
        {
            i = 0;
        }

        dfs(x, y, 0);
    }

    return 0;
}