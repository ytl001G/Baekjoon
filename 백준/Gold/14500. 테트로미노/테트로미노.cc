#include <iostream>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[500][500] = {0};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    int ans = 0;
    // I
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-3; j++) {
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3]);
        }
    }
    
    for (int i = 0; i < n-3; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j]);
        }
    }
    
    // O
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1]);
        }
    }
    
    // L
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1]);
        }
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1]);
        }
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i+2][j]);
        }
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i][j]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+2]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j]);
        }
    }
    
    // S
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1]);
        }
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+2][j]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i][j+1] + arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1]);
        }
    }
    
    // T
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j]);
        }
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-1; j++) {
            ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i+1][j]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1]);
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-2; j++) {
            ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+1]);
        }
    }
    
    cout << ans;
}