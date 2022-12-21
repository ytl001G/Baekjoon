#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) FOR(i,0,n)

using namespace std;

int main() {
    FASTIO;

    iin(n); iin(m);

    char **maze = new char*[m+1];
    FOR(i,0,m+1)
        maze[i] = new char[n+1];

    FOR(i,1,n+1)
        FOR(j,1,m+1)
            cin >> maze[j][i];

    pair<int,int> now;

    queue<pair<int,int>> q;
    q.push(make_pair(1,1));

    vector<pair<int,int>> visited;
    visited.push_back(make_pair(1,1));

    int cnt = 1;
    while (!q.empty()) {
        int l = q.size();
        FOR(_,0,l) {
            now = q.front();
            q.pop();

            if (now.first == m && now.second == n) {
                cout << cnt;
                break;
            }

            if (now.first > 1 && maze[now.first-1][now.second] == '1' && find(visited.begin(), visited.end(), make_pair(now.first-1, now.second)) == visited.end()) {
                q.push(make_pair(now.first-1, now.second));
                visited.push_back(make_pair(now.first-1, now.second));
            }
            
            if (now.second > 1 && maze[now.first][now.second-1] == '1' && find(visited.begin(), visited.end(), make_pair(now.first, now.second-1)) == visited.end()) {
                q.push(make_pair(now.first, now.second-1));
                visited.push_back(make_pair(now.first, now.second-1));
            }

            if (now.first < m && maze[now.first+1][now.second] == '1' && find(visited.begin(), visited.end(), make_pair(now.first+1, now.second)) == visited.end()) {
                q.push(make_pair(now.first+1, now.second));
                visited.push_back(make_pair(now.first+1, now.second));
            }
            
            if (now.second < n && maze[now.first][now.second+1] == '1' && find(visited.begin(), visited.end(), make_pair(now.first, now.second+1)) == visited.end()) {
                q.push(make_pair(now.first, now.second+1));
                visited.push_back(make_pair(now.first, now.second+1));
            }

        }

        cnt++;
    }

    return 0;
}