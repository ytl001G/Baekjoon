#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) FOR(i,0,n)

using namespace std;

int main() {
    FASTIO;

    iin(n);

    string ans = "";

    stack<int> s;
    s.push(0);
    int next = 1;

    FOR(i,0,n){
        iin(a);

        if (s.top() >= a){
            if (s.size() == 1){
                cout << "NO";
                return 0;
            }

            int popcount = 0;
            while (s.size() != 1){
                if (s.top() == a)
                    break;

                s.pop();
                popcount++;
            }

            FOR(_,0,popcount){
                ans += "-\n";
            }

            s.pop();

            ans += "-\n";
        } else {
            if (next > a){
                cout << "NO";
                return 0;
            }

            int pushcount = 0;
            while (s.top() != a) {
                s.push(next);
                next++;
                pushcount++;
            }

            FOR(_,0,pushcount){
                ans += "+\n";
            }

            s.pop();

            ans += "-\n";
        }
    }

    cout << ans;

    return 0;
}