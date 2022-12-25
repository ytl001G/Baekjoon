#include <bits/stdc++.h>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define endl "\n"

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

using namespace std;

int main() {
    FASTIO;

    iin(n);

    // set
    char **window = new char *[n];
    FOR(i,0,n){
        window[i] = new char[n];
        FOR(j,0,n){
            window[i][j] = 0;
        }
    }

    char **visited = new char *[n];
    FOR(i,0,n){
        visited[i] = new char[n];
        FOR(j,0,n){
            visited[i][j] = 0;
        }
    }

    queue<pair<int,int>> q;

    vector<int> ans;

    // input
    FOR(i,0,n){
        FOR(j,0,n){
            cin >> window[i][j];
        }
    }

    // exe
    FOR(i,0,n){
        FOR(j,0,n){
            if(window[i][j] == '0'){
                continue;
            }

            if(!visited[i][j]){
                visited[i][j] = 1;
                q.push(make_pair(i,j));

                int cnt = 0;
                while (!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    cnt++;

                    // sides
                    FOR(i,0,4){
                        int x = p.first+dx[i];
                        int y = p.second+dy[i];

                        if (0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && (window[x][y] == '1')){
                            visited[x][y] = 1;
                            q.push(make_pair(x,y));
                        }
                    }
                }

                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    FOR(i,0,ans.size()){
        cout << ans[i] << endl;
    }

    return 0;
}