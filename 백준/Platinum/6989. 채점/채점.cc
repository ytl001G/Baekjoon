#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#define MAX 1132500

int score[151][151];
bitset<MAX+1> bit[151];

int problem_score[151];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> problem_score[i];
    }
    
    int k;
    cin >> k;
    
    for(int i = 1; i <= n; i++){
        int temp = 0;
        int acc = 0;
        
        for(int j = i; j <= n; j++){
            temp += problem_score[j];
            acc += temp;
            
            score[i][j] = acc;
        }    
    }

    if (k > score[1][n]) {
        cout << k;
        return 0;
    }
    
    bit[0][0] = 1;
    for(int i = 1; i <= n; i++){
        // 안틀림
        bit[i][score[1][i]] = 1;
        
        // j번째에 마지막으로 틀림
        for(int j = 1; j <= i; j++){
            bit[i] |= bit[j-1] << score[j+1][i];
        }
    }
    
    for(int i = k; ; i++){
        if (!bit[n][i]){
            cout << i;
            break;
        }
    }
    
    return 0;
}
