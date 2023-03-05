#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

map<pii, bool> visited;
queue<pair<pii, int>> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    q.push(make_pair(make_pair(0,0), 0));
    
    bool search_all = true;
    
    while (!q.empty()){
        pii now = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if (visited.find(now) == visited.end()){
            visited.insert({now, 1});
        } else {
            continue;
        }
        
        if (now == make_pair(c,d)){
            search_all = false;
            cout << level;
            break;
        }
        
        // Empty A
        pii temp = now;
        temp.first = 0;
        q.push(make_pair(temp, level+1));
        
        // Empty B
        temp = now;
        temp.second = 0;
        q.push(make_pair(temp, level+1));
        
        // Fill A
        temp = now;
        temp.first = a;
        q.push(make_pair(temp, level+1));
        
        // Fill B
        temp = now;
        temp.second = b;
        q.push(make_pair(temp, level+1));
        
        // M A B
        temp = now;
        temp.second += temp.first;
        temp.first = 0;
        if (temp.second > b){
            temp.first = temp.second - b;
            temp.second = b;
        }
        q.push(make_pair(temp, level+1));
        
        // M B A
        temp = now;
        temp.first += temp.second;
        temp.second = 0;
        if (temp.first > a){
            temp.second = temp.first - a;
            temp.first = a;
        }
        q.push(make_pair(temp, level+1));
    }
    
    if (search_all){
        cout << -1;
    }

    return 0;
}
