#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct N{
    int node;
    int cost;
    int Max;
};

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    if (n == 1){
        cout << 0;
        return 0;
    }
    
    vector<vector<pair<int,int>>> graph;
    vector<bool> visited;
    
    for(int i = 0; i <= n; i++){
        vector<pair<int,int>> temp;
        graph.push_back(temp);
        visited.push_back(0);
    }
    
    for(int i = 0; i < n-1; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        
        graph[start].push_back(make_pair(end, cost));
        graph[end].push_back(make_pair(start, cost));
    }
    
    queue<N> q;
    N start;
    start.node = a;
    start.cost = 0;
    start.Max = 0;
    q.push(start);
    
    while (!q.empty()){
        N now = q.front();
        q.pop();
        
        visited[now.node] = 1;
        
        // cout << "now : " << now.first << "cost : " << now.second << endl;
        
        if(now.node == b){
            cout << now.cost - now.Max;
            break;
        }
        
        for(int i = 0; i < graph[now.node].size(); i++){
            if(!visited[graph[now.node][i].first]){
                N nextNode;
                nextNode.node = graph[now.node][i].first;
                nextNode.cost = now.cost + graph[now.node][i].second;
                nextNode.Max = max(now.Max, graph[now.node][i].second);
                q.push(nextNode);
            }
        }
    }
  
    return 0;
}
