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

class Point{
public:
    int x;
    int y;
    int z;

    Point(int a, int b, int c){
        this->x = a;
        this->y = b;
        this->z = c;
    }
};

int n, m, h;
int visited[100][100][100];
int box[100][100][100];
queue<Point> q;

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 1, -1, 0, 0};

bool isClear(){
    bool ret = true;

    FOR(i,0,h){
        FOR(j,0,m){
            FOR(k,0,n){
                if (box[k][j][i] != -1 && visited[k][j][i] == 0){
                    ret = false;
                    break;
                }
            }
            
        }
    }

    return ret;
}

int main() {
    FASTIO;

    FOR(i,0,100){
        FOR(j,0,100){
            FOR(k,0,100){
                visited[k][j][i] = 0;
                box[k][j][i] = -1;
            }
        }
    }

    cin >> n >> m >> h;

    FOR(i,0,h){
        FOR(j,0,m){
            FOR(k,0,n){
                cin >> box[k][j][i];

                if (box[k][j][i] == 1){
                    q.push(Point(k,j,i));
                    visited[k][j][i] = 1;
                }
            }
        }
    }

    int days = -1;
    while (!q.empty()){
        int len = q.size();
        days++;

        FOR(_,0,len){
            Point now = q.front();
            q.pop();

            FOR(i,0,6){
                int x = now.x + dx[i];
                int y = now.y + dy[i];
                int z = now.z + dz[i];

                if (0 <= x && x < n && 0 <= y && y < m && 0 <= z && z < h && !visited[x][y][z] && box[x][y][z] == 0){
                    visited[x][y][z] = 1;
                    q.push(Point(x,y,z));
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