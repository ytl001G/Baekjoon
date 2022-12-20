#include <iostream>
#include <string>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) int x = n; while(x--)

using namespace std;

int main() {
    FASTIO;

    string str;

    getline(cin, str);

    bool isblank = true;
    int ans = 0;

    FOR(i,0,str.size()){
        if (i != 0 && (str[i-1] != ' ' && str[i] == ' '))
            isblank = true;

        if (isblank) {
            if (str[i] != ' ') {
                ans++;
                isblank = false;
            }
        }
    }

    cout << ans;

    return 0;
}