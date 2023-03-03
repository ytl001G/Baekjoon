#include <bits/stdc++.h>
using namespace std;

long long int solution[100001];

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
    
    int l = 1, r = n;
    
    long long int minarr[2];
    minarr[0] = solution[l];
    minarr[1] = solution[r];
    
    while (l < r){
        if (abs(solution[l] + solution[r]) < abs(minarr[0] + minarr[1])){
            minarr[0] = solution[l];
            minarr[1] = solution[r];
        }
        
        if (solution[l] + solution[r] >= 0){
            r--;
        } else {
            l++;
        }
    }
    
    cout << minarr[0] << " " << minarr[1];


    return 0;
}
