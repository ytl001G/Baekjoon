#include <bits/stdc++.h>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define endl "\n"

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n, m;
int window[8][8];

int bfs(){
    queue<pair<int, int>> Queue;
    int visited[8][8];
    FOR(i,0,8){
        FOR(j,0,8){
            visited[j][i] = 0;
        }
    }

    FOR(i,0,n){
        FOR(j,0,m){
            if (window[j][i] == 2){
                Queue.push(make_pair(j,i));
                visited[j][i] = 1;
            }
        }
    }

    while (!Queue.empty()){
        pair<int,int> now = Queue.front();
        Queue.pop();

        FOR(i,0,4){
            int nx, ny;
            nx = now.first + dx[i];
            ny = now.second + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n && window[nx][ny] == 0 && visited[nx][ny] == 0){
                visited[nx][ny] = 1;
                Queue.push(make_pair(nx, ny));
            }
        }
    }

    int area = 0;

    FOR(i,0,n){
        FOR(j,0,m){
            if(window[j][i] == 0 && visited[j][i] == 0){
                area++;
            }
        }
    }

    return area;
}

int main() {
    FASTIO;

    cin >> n >> m;

    FOR(i,0,8){
        FOR(j,0,8){
            window[j][i] = 1;
        }
    }

    FOR(i,0,n){
        FOR(j,0,m){
            cin >> window[j][i];
        }
    }

    int maxarea = 0;
    FOR(i,0,m*n){
        FOR(j,i+1,m*n){
            FOR(k,j+1,m*n){
                int x1,y1,x2,y2,x3,y3;
                x1 = i%m;
                x2 = j%m;
                x3 = k%m;
                y1 = i/m;
                y2 = j/m;
                y3 = k/m;

                if (window[x1][y1] == 0 && window[x2][y2] == 0 && window[x3][y3] == 0){
                    window[x1][y1] = 1;
                    window[x2][y2] = 1;
                    window[x3][y3] = 1;

                    int area = bfs();
                    maxarea = max(area, maxarea);

                    window[x1][y1] = 0;
                    window[x2][y2] = 0;
                    window[x3][y3] = 0;
                }
            }
        }
    }

    cout << maxarea;

    return 0;
}