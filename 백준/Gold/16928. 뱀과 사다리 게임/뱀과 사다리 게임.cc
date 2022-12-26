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

int visited[101] = {0,};
int dice[] = {1,2,3,4,5,6};

int ledder_snake[101] = {0,};
queue<int> q;

int n, m;

int main() {
    FASTIO;

    cin >> n >> m;

    FOR(i,0,n+m){
        int x, y;
        cin >> x >> y;
        ledder_snake[x] = y;
    }

    visited[1] = 1;
    q.push(1);

    int cnt = -1;
    while(!q.empty()){
        int len = q.size();
        cnt++;

        int now;
        FOR(_,0,len){
            now = q.front();
            q.pop();

            if (now == 100){
                break;
            }

            FOR(i,0,6){
                int next = now + dice[i];
                if(1 <= next && next <= 100){
                    if(ledder_snake[next] != 0){
                        next = ledder_snake[next];
                    }

                    if (!visited[next]){
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
        }

        if (now == 100){
            break;
        }
    }
    
    cout << cnt;

    return 0;
}