#include <bits/stdc++.h>
using namespace std;

int num[300001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> num[i];
    }
    
    if (n == 1){
        cout << 0;
        return 0;
    }
    
    if (n == 2){
        cout << !(num[1] <= num[2]);
        return 0;
    }
    
    int ans = 0;
    bool increase = 1;
    int pre = 0;
    
    for (int i = 1; i <= n; i++){
        if (increase && pre > num[i]){
            increase = 0;  
            ans++;
        }
        if (!increase && pre < num[i]){
            increase = 1;
            ans++;
        }
        
        pre = num[i];
    }
    
    if (ans == 0){
        cout << 0;
    } else {
        cout << floor(log2(ans)) + 1;
    }

    return 0;
}
