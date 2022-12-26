#include <bits/stdc++.h>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define endl "\n"

using namespace std;

int n,m;

int window[50][50];
int visited[50][50];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(pair<int, int> pair){
    if (window[pair.first][pair.second] == 0){
        return 0;
    }

    if (visited[pair.first][pair.second]){
        return 0;
    }

    visited[pair.first][pair.second] = 1;

    FOR(i,0,4){
        int x = pair.first + dx[i];
        int y = pair.second + dy[i];

        if (0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && window[x][y]){
            dfs(make_pair(x,y));
        }
    }

    return 1;
}

void test(){
    FOR(i,0,50){
        FOR(j,0,50){
            window[i][j] = visited[i][j] = 0;
        }
    }

    cin >> n;
    cin >> m;
    iin(k);

    FOR(i,0,k){
        iin(x);
        iin(y);

        window[x][y] = 1;
    }

    int cnt = 0;

    FOR(i,0,50){
        FOR(j,0,50){
            cnt += dfs(make_pair(j,i));
        }
    }

    cout << cnt << endl;
}

int main() {
    FASTIO;

    iin(T);

    FOR(i,0,T){
        test();
    }

    return 0;
}