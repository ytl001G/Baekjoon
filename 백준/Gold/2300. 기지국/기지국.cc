#include <bits/stdc++.h>
using namespace std;

typedef struct point{
    int x, y;
} point;

point points[10001];

bool com(point a, point b){
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

int dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }
    
    sort(points+1, points+n+1, com);
    
    for (int i = 1; i <= n; i++){
        int y_disp = 0;
        dp[i] = 100000000;
        
        for (int j = i-1; j >= 0; j--){
            y_disp = max(y_disp, abs(points[j+1].y));
            dp[i] = min(dp[i], dp[j] + max(points[i].x - points[j+1].x, y_disp * 2));
        }
    }
    
    cout << dp[n];

    return 0;
}
