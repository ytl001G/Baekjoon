#include <iostream>
#include <algorithm>

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

    int *s = new int[n];

    FOR(i,0,n)
        cin >> s[i];

    sort(s, s+n);

    iin(m);

    FOR(i,0,m){
        int left = -1;
        int right = n;
        iin(a);

        while (left+1<right){
            int mid = (left + right)/2;

            if (s[mid] > a) right = mid;
            else if (s[mid] < a) left = mid;
            else {
                cout << 1 << " ";
                break;
            }
        }

        if (left+1 == right)
            cout << 0 << " ";
    }

    return 0;
}