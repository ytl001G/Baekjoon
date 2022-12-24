#include <iostream>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) FOR(i,0,n)

using namespace std;

int main() {
    FASTIO;

    iin(n);iin(m);

    // 인접행렬
    int **graph = new int *[n];
    FOR(i,0,n){
        graph[i] = new int[n];

        FOR(j,0,n){
            if (i == j){
                graph[i][j] = 0;
            } else {
                graph[i][j] = 1<<20;
            }
        }
    }

    // input
    FOR(i,0,n-1){
        iin(x);iin(y);iin(c);
        x--;
        y--;

        graph[x][y] = graph[y][x] = c;
    }

    // calc
    FOR(mi,0,n){
        FOR(s,0,n){
            FOR(e,0,n){
                if (graph[s][e] > graph[s][mi] + graph[mi][e]){
                    graph[s][e] = graph[s][mi] + graph[mi][e];
                }
            }
        }
    }

    // solve
    FOR(i,0,m){
        iin(x);iin(y);
        x--;
        y--;

        cout << graph[x][y] << "\n";
    }

    return 0;
}