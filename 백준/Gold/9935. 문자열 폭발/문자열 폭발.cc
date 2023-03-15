#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define forr(n) for(int i = 0; i < n; i++)

vector<char> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    int l1 = s1.size();
    int l2 = s2.size();
    
    for (char x : s1){
        s.push_back(x);
        
        if (s.size() >= l2){
            bool except = true;
            for(int i = 0; i < l2; i++){
                if (s[s.size() - l2 + i] != s2[i]){
                    except = false;
                    break;
                }
            }
            

            if (except){
                for(int i = 0; i < l2; i++){
                    s.pop_back();
                }
            }
        }
    }
    
    string ans = "";
    for(char x : s){
        ans += x;
    }
    
    if (ans != "")
        cout << ans;
    else
        cout << "FRULA";
    
    return 0;
}
