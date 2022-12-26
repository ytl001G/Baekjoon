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

int n, m;
int visited[1000][1000];
int box[1000][1000];
queue<pair<int, int>> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isClear(){
    bool ret = true;

    FOR(i,0,m){
        FOR(j,0,n){
            if (box[j][i] != -1 && visited[j][i] == 0){
                ret = false;
                break;
            }
        }
    }

    return ret;
}

int main() {
    FASTIO;

    FOR(i,0,1000){
        FOR(j,0,1000){
            visited[j][i] = 0;
            box[j][i] = -1;
        }
    }

    cin >> n >> m;

    FOR(i,0,m){
        FOR(j,0,n){
            cin >> box[j][i];

            if (box[j][i] == 1){
                q.push(make_pair(j,i));
                visited[j][i] = 1;
            }
        }
    }

    int days = -1;
    while (!q.empty()){
        int len = q.size();
        days++;

        FOR(_,0,len){
            pair<int, int> now = q.front();
            q.pop();

            FOR(i,0,4){
                int x = now.first + dx[i];
                int y = now.second + dy[i];

                if (0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && box[x][y] == 0){
                    visited[x][y] = 1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }

    if (isClear()){
        cout << days;
    } else {
        cout << -1;
    }

    return 0;
}