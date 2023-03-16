#include <bits/stdc++.h>
using namespace std;

int l, c;
char words[16];

bool isvowel(char v){
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

bool check[16];
void dfs(int n, int k, int C, int V){
    if (k == l && C >= 2 && V >= 1){
        for (int i = 1; i <= c; i++){
            if (check[i]){
                printf("%c", words[i]);
            }
        }
        
        printf("\n");
    } else if (n <= c - 1){
        check[n+1] = 1;
        dfs(n+1, k+1, C + !isvowel(words[n+1]), V + isvowel(words[n+1]));
        check[n+1] = 0;
        dfs(n+1, k, C, V);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> l >> c;
    
    for(int i = 1; i <= c; i++){
        cin >> words[i];
    }
    
    sort(words+1, words+c+1);
    
    dfs(0, 0, 0, 0);

    return 0;
}