#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

set<string> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    while(n--){
        string a;
        cin >> a;
        s.insert(a);
    }
    
    int ans = 0;
    while(m--){
        string a;
        cin >> a;
        if (s.find(a) != s.end()) ans++;
    }
    
    cout << ans;

    return 0;
}
