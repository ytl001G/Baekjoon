#include <bits/stdc++.h>
using namespace std;

long long int solution[5001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> solution[i];
    }
    
    sort(solution+1, solution+n+1);
    
    long long int minn = 1000000000000000;
    long long int L, M, R;
    
    for (int m = 2; m < n; m++){
        int l = 1, r = n;
        
        long long int minarr[3];
        minarr[0] = solution[l];
        minarr[1] = solution[m];
        minarr[2] = solution[r];
        
        while (l < m && m < r){
            if (abs(solution[l] + solution[m] + solution[r]) < abs(minarr[0] + minarr[1] + minarr[2])){
                minarr[0] = solution[l];
                minarr[1] = solution[m];
                minarr[2] = solution[r];
            }
            
            if (abs(solution[l] + solution[m] + solution[r]) < minn){
                minn = abs(solution[l] + solution[m] + solution[r]);
                L = solution[l];
                M = solution[m];
                R = solution[r];
            }
            
            if (solution[l] + solution[m] + solution[r] >= 0){
                r--;
            } else {
                l++;
            }
        }
    }
    
    cout << L << " " << M << " " << R;
    
    return 0;
}
