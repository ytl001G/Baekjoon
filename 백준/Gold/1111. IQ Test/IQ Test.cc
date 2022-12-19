#include <iostream>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;

using namespace std;

int main() {
    FASTIO;

    iin(n);

    int *num = new int[n];

    FOR(i,0,n) cin >> num[i];

    if (n == 1) {
        cout << 'A';
        return 0;
    } else if (n == 2) {
        if (num[0] == num[1]) cout << num[0];
        else cout << 'A';
        return 0;
    }

    // a1 = a*a0+b
    // a2 = a*a1+b

    if (num[0] == num[1]) {
        bool isconst = true;
        FOR(i,0,n) {
            if (num[i] != num[0]) {
                isconst = false;
                break;
            }
        }
        
        if (isconst) cout << num[0];
        else cout << 'B';
        return 0;
    }

    int a = (num[1] - num[2])/(num[0] - num[1]);
    int b = num[1] - a*num[0];

    bool fitrule = true;
    FOR(i,0,n-1) {
        if (num[i+1] != a*num[i]+b) {
            fitrule = false;
            break;
        }
    }

    if (fitrule) cout << a*num[n-1]+b;
    else cout << 'B';

    return 0;
}