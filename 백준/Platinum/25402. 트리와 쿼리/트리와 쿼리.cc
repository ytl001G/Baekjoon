#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int N, Q;
vector<int> S;
vector<vector<int>> graph;

int dfs(int start, int parent){
    int c = 1;
    
    for (int child : graph[start]){
        bool good = false;
        
        for (int x : S){
            if (x == child){
                good = true;
            }
        }

        if (child == parent){
            good = false;
        }
        
        if (good){
            // printf("dfs(%d)", child);
            c += dfs(child, start);
        }
    }
    
    // printf("%dc ", c);
    return c;
}

void solve(){
    int K;
    cin >> K;
    
    S.clear();
    
    for (int i = 0; i < K; i++){
        int x;
        cin >> x;
        S.push_back(x);
    }
    
    int cnt = 0;
    for (int x : S){
        // printf("%da%d ", x, cnt);
        cnt += dfs(x,0)-1;
    }
    
    printf("%d\n", cnt/2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i <= N-1; i++){
        vector<int> t;
        
        graph.push_back(t);
    }
    
    for(int i = 0; i < N-1; i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    cin >> Q;
    while (Q--){
        solve();
    }
    
    return 0;
}
