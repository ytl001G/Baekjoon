#include <iostream>
#include <set>

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

    set<int> s;

    loop(n){
        iin(a);
        s.insert(a);
    }

    iin(m);

    loop(m){
        iin(a);
        if (s.find(a) != s.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}