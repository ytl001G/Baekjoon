#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;

using namespace std;

int main() {
    FASTIO;

    iin(n);

    vector<int> zero;
    vector<int> one;

    zero.push_back(1);
    zero.push_back(0);
    one.push_back(0);
    one.push_back(1);

    while (n--) {
        iin(c);

        if (c < zero.size()) {
            cout << zero[c] << " " << one[c] << endl;
            continue;
        }

        int start = zero.size();
        FOR(i, start, c+1){
            zero.push_back(zero[i-1]+zero[i-2]);
            one.push_back(one[i-1]+one[i-2]);
        }

        cout << zero[c] << " " << one[c] << endl;
    }

    return 0;
}