#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int m, n;
ll S[1025][1025], x[1025][1025];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + x[i][j];
        }
    }
    
    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1] << "\n";
    }

    return 0;
}