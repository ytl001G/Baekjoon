#include <iostream>
#include <string>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int    
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;

using namespace std;

int main() {
    FASTIO;

    string str;
    cin >> str;

    string target[] = {"c=", "c-", "dz", "d-", "lj", "nj", "s=", "z="};

    bool isbound;
    string nowchar;
    int ans = 0;

    FOR(i, 0, str.size()) {
        nowchar += str[i];

        if (nowchar.size() == 2) {
            isbound = false;
            FOR(j, 0, 8) {
                if (target[j] == nowchar) {
                    isbound = true;
                    break;
                }
            }

            if (!isbound) {
                ans += 2;
                nowchar.clear();
            } else if (nowchar != "dz") {
                ans++;
                nowchar.clear();
            }
        }

        if (nowchar.size() == 3) {
            if (nowchar == "dz=") {
                ans++;
            } else {
                ans += 3;
            }
            nowchar.clear();
        }
    }

    cout << ans;

    return 0;
}